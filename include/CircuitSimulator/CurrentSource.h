//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_CURRENTSOURCE_H
#define CIRCUITSIMULATOR_CURRENTSOURCE_H

#include "Element.h"

class CurrentSource: public Element {
private:
    float _current;
public:
    CurrentSource(int node1, int node2, float current): Element(node1, node2), _current{current}{}
    [[nodiscard]] float get_current() const {return _current;}
};


#endif //CIRCUITSIMULATOR_CURRENTSOURCE_H
