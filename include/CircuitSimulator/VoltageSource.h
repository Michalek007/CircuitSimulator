//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_VOLTAGESOURCE_H
#define CIRCUITSIMULATOR_VOLTAGESOURCE_H

#include "Element.h"

class VoltageSource: public Element {
private:
    float _voltage;
public:
    VoltageSource(int node1, int node2, float voltage): Element(node1, node2), _voltage{voltage}{}
    [[nodiscard]] float get_voltage() const {return _voltage;}
};


#endif //CIRCUITSIMULATOR_VOLTAGESOURCE_H
