//
// Created by Michał on 15.12.2022.
//

#include "Circuit.h"

Circuit::Circuit(std::vector<std::shared_ptr<Element>> elements): _elements{std::move(elements)}{
    std::map<int, Element> nodes;
    for (auto &element: _elements){

    }

}
