//
// Created by Michał on 15.12.2022.
//

#ifndef CIRCUITSIMULATOR_ELEMENT_H
#define CIRCUITSIMULATOR_ELEMENT_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <utility>
#include <cmath>
#include "Complex.h"

class Element {
private:
    int _node1;
    int _node2;

public:
    Element(int node1, int node2): _node1{node1}, _node2{node2}{}
};


#endif //CIRCUITSIMULATOR_ELEMENT_H
