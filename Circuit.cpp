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
    for (auto &n: nodes_counter){
        int node = n.first;
        int node_value = n.second;
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
    for (auto &elements: _branch){
        std::cout << elements.first << std::endl;
        for (auto &element: elements.second){
            std::cout << element->get_name() << std::endl;
        }
    }
}

void Circuit::set_branches(){
    for (auto node: _nodes){
        int node_memory = node;
        for (auto &element: _node_elements[node]) {
            node = node_memory;
            std::cout << "_____________" <<std::endl;
            std::cout << node_memory <<std::endl;
//            std::cout << element->get_name() << std::endl;
            std::unordered_set<std::shared_ptr<Element>> set{};
            set.insert(element);
            int last_node = element->get_node(node);
//            std::cout << last_node << std::endl;
            if (is_node(last_node)){
                if (_branch.contains(get_node_key(node, last_node))){
                    _branch[get_node_key(node, last_node)].insert(element);
                }
                else{
                    _branch[get_node_key(node, last_node)] = set;
                }
                continue;
            }
            while (true){
                auto e = find_element(last_node, node);
                if (e == nullptr){
                    continue;
                }
                std::cout << e->get_name() << std::endl;
                set.insert(e);
                node = last_node;
                last_node = e->get_node(last_node);
                if (is_node(last_node)){
                    std::cout << "*********" <<std::endl;
                    std::cout << last_node <<std::endl;
                    if (_branch.contains(get_node_key(node_memory, last_node))){
                        _branch[get_node_key(node_memory, last_node)].insert(set.begin(), set.end());
                    }
                    else{
                        _branch[get_node_key(node_memory, last_node)] = set;
                    }
                    break;
                }
            }
    }

//        for (auto &e: _elements) {
//            if (e->get_node(last_node) != -1){
//                last_node = e->get_node(last_node);
//                vec.push_back(e);
//            }
//            else{
//                continue;
//            }
//            if (is_node(last_node)){
//                _branch[std::to_string(node) + std::to_string(last_node)] = vec;
//                break;
//            }
//        }
    }
}

bool Circuit::is_node(int node) const {
    if (std::ranges::any_of(_nodes.begin(), _nodes.end(), [&node](int n){return n==node;})){
        return true;
    }
    return false;
}

std::string Circuit::get_node_key(int node1, int node2) {
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
