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
#include <algorithm>
#include <unordered_set>
#include "Complex.h"

class Element {
private:
    int _node1;
    int _node2;
    std::string _name;

public:
    Element(int node1, int node2): _node1{node1}, _node2{node2}{}
    [[nodiscard]] int get_node1() const {return _node1;}
    [[nodiscard]] int get_node2() const {return _node2;}
    [[nodiscard]] std::string get_name() const {return _name;}
    void set_name(const std::string& name) {_name = name;}
    int get_node(int node) const;

};


#endif //CIRCUITSIMULATOR_ELEMENT_H
