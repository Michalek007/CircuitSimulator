//
// Created by Michał on 22.12.2022.
//

#ifndef CIRCUITSIMULATOR_RESISTOR_H
#define CIRCUITSIMULATOR_RESISTOR_H

#include "Element.h"

class Resistor: public Element {
private:
    float _resistance;
public:
    Resistor(int node1, int node2, float resistance): Element(node1, node2), _resistance{resistance}{}
    [[nodiscard]] float get_resistance() const {return _resistance;}
};


#endif //CIRCUITSIMULATOR_RESISTOR_H
