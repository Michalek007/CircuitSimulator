//
// Created by Michał on 15.12.2022.
//

#include "Circuit.h"

Circuit::Circuit(std::vector<std::shared_ptr<Element>> elements): _elements{std::move(elements)}{
    std::map<int, Element> nodes;
    std::map<int, int> nodes_counter;
    for (auto &element: _elements){
        nodes_counter[element->get_node1()] += 1;
        nodes_counter[element->get_node2()] += 1;
    }

    for (auto &element: nodes_counter){
//        std::cout << element.first << std::endl;
//        std::cout << element.second << std::endl;
        if (element.second > 2){
            
        }
    }

}
