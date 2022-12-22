//
// Created by Michał on 22.12.2022.
//

#ifndef CIRCUITSIMULATOR_CAPACITOR_H
#define CIRCUITSIMULATOR_CAPACITOR_H

#include "Element.h"

class Capacitor: public Element {
private:
    float _capacity;
public:
    Capacitor(int node1, int node2, float capacity): Element(node1, node2), _capacity{capacity}{}

};


#endif //CIRCUITSIMULATOR_CAPACITOR_H
