//
// Created by Michał on 15.12.2022.
//

#ifndef CIRCUITSIMULATOR_CIRCUIT_H
#define CIRCUITSIMULATOR_CIRCUIT_H

#include "Element.h"

class Circuit {
private:
    std::shared_ptr<std::vector<std::shared_ptr<Element>>> _elements;
public:
    explicit Circuit(std::shared_ptr<std::vector<std::shared_ptr<Element>>> elements): _elements{std::move(elements)}{}
};


#endif //CIRCUITSIMULATOR_CIRCUIT_H
