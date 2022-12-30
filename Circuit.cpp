//
// Created by Michał on 15.12.2022.
//

#include "Circuit.h"

Circuit::Circuit(std::vector<std::shared_ptr<Element>> elements, float freq): _elements{std::move(elements)}, _freq{freq}{
    _c_freq = (float) (2 * std::numbers::pi * _freq);

    std::map<int, int> nodes_counter;
    for (auto &element: _elements) {
        nodes_counter[element->get_node1()] += 1;
        nodes_counter[element->get_node2()] += 1;
    }
    int value = 1;
    for (auto &n: nodes_counter){
        int node = n.first;
        int node_value = n.second;
        if (node_value > value){
            value = node_value;
            _ground = node;
        }
        if (node_value > 2){
            _nodes.push_back(node);
            for (auto &element: _elements){
                if (element->get_node1() == node || element->get_node2() == node){
                    _node_elements[node].push_back(element);
                }
            }
        }
    }
    set_branches();
}

std::shared_ptr<Element> Circuit::find_element(int node, int condition) const{
    for (auto &element: _elements){
        if (element->get_node1() == node){
            if (element->get_node2() == condition){
                continue;
            }
            return element;
        }
        if (element->get_node2() == node) {
            if (element->get_node1() == condition) {
                continue;
            }
            return element;
        }
    }
    return nullptr;
}

void Circuit::display_nodes() const {
    for (auto &node: _nodes){
        std::cout << node << std::endl;
    }
}

void Circuit::display_node_elements() const {
    for (auto &elements: _node_elements){
        std::cout << elements.first << std::endl;
        for (auto &element: elements.second){
            std::cout << element->get_name() << std::endl;
        }
    }
}

void Circuit::display_branch() const {
    for (auto &elements: _branches){
        std::cout << elements.first << std::endl;
        for (auto &element: elements.second){
            std::cout << element->get_name() << std::endl;
        }
    }
}

void Circuit::display_matrix_nodes() const {
    for (auto &elements: _matrix_nodes){
        std::cout << elements.first << std::endl;
        std::cout << elements.second << std::endl;
    }
}

void Circuit::set_branches(){
    for (auto node: _nodes){
        int node_memory = node;
        for (auto &element: _node_elements[node]) {
            node = node_memory;
            std::unordered_set<std::shared_ptr<Element>> set{};
            set.insert(element);
            int last_node = element->get_node(node);
            if (is_node(last_node)){
                if (_branches.contains(get_node_key(node, last_node))){
                    _branches[get_node_key(node, last_node)].insert(element);
                }
                else{
                    _branches[get_node_key(node, last_node)] = set;
                }
                continue;
            }
            while (true){
                auto e = find_element(last_node, node);
                if (e == nullptr){
                    continue;
                }
                set.insert(e);
                node = last_node;
                last_node = e->get_node(last_node);
                if (is_node(last_node)){
                    if (_branches.contains(get_node_key(node_memory, last_node))){
                        _branches[get_node_key(node_memory, last_node)].insert(set.begin(), set.end());
                    }
                    else{
                        _branches[get_node_key(node_memory, last_node)] = set;
                    }
                    break;
                }
            }
        }
    }
}

bool Circuit::is_node(int node) const {
    if (std::ranges::any_of(_nodes.begin(), _nodes.end(), [&node](int n){return n==node;})){
        return true;
    }
    return false;
}

std::string Circuit::get_node_key(int node1, int node2) {
    if (!_matrix_nodes.contains(node1)){
        if (node1 == _ground){
            _matrix_nodes[node1] = 0;
        }
        else{
            _matrix_nodes[node1] = last_node_value + 1;
            last_node_value += 1;
        }
    }
    if (!_matrix_nodes.contains(node2)){
        if (node2 == _ground){
            _matrix_nodes[node2] = 0;
        }
        else {
            _matrix_nodes[node2] = last_node_value + 1;
            last_node_value += 1;
        }
    }
    if (node1 > node2){
        return std::to_string(node2) + std::to_string(node1);
    }
    else if (node1 < node2){
        return std::to_string(node1) + std::to_string(node2);
    }
    else{
        throw std::invalid_argument("Invalid branch.");
    }
}

void Circuit::calculate() {
    unsigned int size = _nodes.size()-1;
    Eigen::MatrixXcf Y(size, size);
    for (auto &item: _branches){
        int n0 = _matrix_nodes[(int)(item.first[0] - '0')];
        int n1 = _matrix_nodes[(int)(item.first[1] - '0')];
        auto branch_impedance = get_branch_impedance(item.first);
        if (n0 == 0){
            Y(n1-1,n1-1) = branch_impedance;
        }
        else{
            Y(n0-1,n1-1) = -branch_impedance;
            Y(n1-1,n0-1) = -branch_impedance;
        }
        for (auto &element: item.second){
            if (element->is_passive()){

            }
        }
    }
    std::cout << Y << std::endl;
    std::cout << Y.determinant() << std::endl;

//    for (int i=0;i<size;i++){
//        for (int j=0;j<size;j++){
//
//        }
//    }
}

std::complex<float> Circuit::get_branch_impedance(const std::string& branch){
    std::complex<float> sum(0, 0);
    for (auto &item: _branches[branch]){
        sum += item->get_admittance(_c_freq);
    }
    return sum;
}
