//
// Created by Michał on 15.12.2022.
//

#include "Circuit.h"

Circuit::Circuit(std::vector<std::shared_ptr<Element>> elements): _elements{std::move(elements)}{
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
//    for (auto &node: _nodes){
//
//    }

    }

//    for (auto &element: nodes_counter){
//        std::cout << element.first << std::endl;
//        std::cout << element.second << std::endl;
//        if (element.second > 2){
//            _nodes.push_back(element.first);
//            int condition = -1;
//            for (int i = 0; i < element.second; i++){
//                auto el = find_element(element.first, condition);
//                if (el == nullptr){
//                    std::cout << "nullptr" << std::endl;
//                    continue;
//                }
//                nodes[element.first].push_back(el);
//                if (element.first == el->get_node1()){
//                    condition = el->get_node2();
//                }
//                else{
//                    condition = el->get_node1();
//                }
//            }
//        }
//    }

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

void Circuit::set_branches() {
    for (auto node: _nodes){
        int node_memory = node;
        for (auto &element: _node_elements[node]) {
            node = node_memory;
            std::cout << element->get_name() << std::endl;
            std::vector<std::shared_ptr<Element>> vec{};
            vec.push_back(element);
            int last_node = element->get_node(node);
            std::cout << last_node << std::endl;
            if (is_node(last_node)){
                _branch[std::to_string(node) + std::to_string(last_node)] = vec;
                continue;
            }
            while (true){
                auto e = find_element(last_node, node);
                if (e == nullptr){
                    continue;
                }
                std::cout << e->get_name() << std::endl;
                vec.push_back(e);
                node = last_node;
                last_node = e->get_node(last_node);
                if (is_node(last_node)){
                    _branch[std::to_string(node) + std::to_string(last_node)] = vec;
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

bool Circuit::is_node(int node) {
    for (auto i: _nodes) {
        if (node == i){
            return true;
        }
    }
    return false;
}
