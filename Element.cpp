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
