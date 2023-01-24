//
// Created by Michał on 15.12.2022.
//

#include "Element.h"

int Element::get_node(int node) const {
    if (node == _node1){
        return _node2;
    }
    else if (node == _node2){
        return _node1;
    }
    else{
        return -1;
    }
}

void Element::change_node_value(int node, int value) {
    if (_node1 == node){
        _node1 = value;
    }
    else if (_node2 == node){
        _node2 = value;
    }
    else{
        throw std::invalid_argument(" Invalid node.");
    }
}
