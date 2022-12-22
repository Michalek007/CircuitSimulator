//
// Created by Michał on 22.12.2022.
//

#ifndef CIRCUITSIMULATOR_INDUCTOR_H
#define CIRCUITSIMULATOR_INDUCTOR_H

#include "Element.h"

class Inductor: public Element {
private:
    float _inductance;
public:
    Inductor(int node1, int node2, float inductance): Element(node1, node2), _inductance{inductance}{}
};


#endif //CIRCUITSIMULATOR_INDUCTOR_H
