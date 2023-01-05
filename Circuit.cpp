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
        std::cout << "___________" << std::endl;
        std::cout << elements.first << std::endl;
        std::cout << "___________" << std::endl;
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

void Circuit::display_branches_voltage() const {
    for (auto &item: _branch_voltage){
        std::cout << item.first << std::endl;
        std::cout << item.second << std::endl;
    }
}

void Circuit::set_branches(){
    int memory {0};
    for (auto node: _nodes){
        for (auto &element: _node_elements[node]) {
            int condition {0};
            for (auto &vec: _branches){
//                if (vec.first[0] == (char)node || vec.first[1] == (char)node){
//
//                }
                for (auto &item: vec.second){
                    if (element == item) condition = 1;
                }
                if (condition){
                     break;
                }
            }
            if (condition){
                continue;
            }
            std::unordered_set<std::shared_ptr<Element>> set{};
            set.insert(element);
            int current_node = element->get_node(node);
            int last_node = node;
            if (is_node(current_node)){
                if (_branches.contains(get_node_key(node, current_node))){
//                    _branches[get_node_key(node, current_node)].insert(element);
                    _branches[get_node_key(node, current_node) + std::to_string(memory)] = set;
                    memory += 1;
                }
                else{
                    _branches[get_node_key(node, current_node)] = set;
                }
                continue;
            }
            while (true){
                auto e = find_element(current_node, last_node);
                if (e == nullptr){
//                    set.insert(element);
                    continue;
                }
                else{
                    set.insert(e);
                    last_node = current_node;
                    current_node = e->get_node(current_node);
                }
                if (is_node(current_node)){
                    if (_branches.contains(get_node_key(node, current_node))){
//                        _branches[get_node_key(node, current_node)].insert(set.begin(), set.end());
                        _branches[get_node_key(node, current_node) + std::to_string(memory)] = set;
                        memory += 1;
                    }
                    else{
                        _branches[get_node_key(node, current_node)] = set;
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
    std::string key;
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
        key = std::to_string(node2) + std::to_string(node1);
    }
    else if (node1 < node2){
        key = std::to_string(node1) + std::to_string(node2);
    }
    else{
        throw std::invalid_argument("Invalid branch.");
    }
//    if (_branches.contains(key)){
//        return key + "r";
//    }
//    else{
//        return key;
//    }
    return key;
}

void Circuit::calculate() {
    unsigned int size = _nodes.size()-1;
    Eigen::MatrixXcf Y(size, size);
    Eigen::VectorXcf I = Eigen::VectorXcf::Zero(size);
    for (auto &item: _branches){
        int n0 = _matrix_nodes[(int)(item.first[0] - '0')];
        int n1 = _matrix_nodes[(int)(item.first[1] - '0')];
        auto branch_admittance = get_branch_admittance(item.first);
        if (n0 == 0){
            Y(n1-1,n1-1) = branch_admittance;
        }
        else{
            Y(n0-1,n1-1) = -branch_admittance;
            Y(n1-1,n0-1) = -branch_admittance;
        }
        if (!std::ranges::any_of(item.second.begin(), item.second.end(), [](const std::shared_ptr<Element>& arg){return !arg->is_passive();})){
            continue;
        }
        for (auto &element: item.second){
            if (!element->is_passive()){
                if (!n0){
                    if (element->get_type() != Type::current){
                        I(n1-1) += element->get_complex_value() / branch_admittance;
                    }
                    else{
                        I(n1-1) += element->get_complex_value();
                    }
                }
                else{
                    if (element->get_type() != Type::current){
                        I(n0-1) += element->get_complex_value() / branch_admittance;
                        I(n1-1) += element->get_complex_value() / branch_admittance;
                    }
                    else{
                        I(n0-1) += element->get_complex_value();
                        I(n1-1) += element->get_complex_value();
                    }
                }
            }
        }
    }
//    std::cout << Y << std::endl;
//    std::cout << I << std::endl;

    std::complex Vi{0, 0};

    for (int i=0;i<size;i++){
        auto Yi = Y;
        for (int j=0;j<size;j++){
            Yi(j, i) = I(j);

        }
        std::cout << "___________________" << std::endl;
//        std::cout << Yi << std::endl;
        std::cout << Yi.determinant() << std::endl;
        std::cout << Y.determinant() << std::endl;
        auto yi = Yi.determinant();
        auto y = Y.determinant();
        Vi = yi/y;
        std::cout << Vi << std::endl;
        _branch_voltage[get_node_key(0, i+1)] = Vi;
    }
}

std::complex<float> Circuit::get_branch_admittance(const std::string& branch){
    std::complex<float> sum(0, 0);
    for (auto &item: _branches[branch]){
        sum += item->get_impedance(_c_freq);
    }
    return std::complex<float> {1, 0} / sum;
}
