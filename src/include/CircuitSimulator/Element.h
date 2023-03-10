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
#include <complex>
#include "Voltage.h"
#include "Current.h"

enum class Type{
    current = 0,
    voltage = 1,
    d_current = 2,
    d_voltage = 3,
    passive = 4
};


class Element {
private:
    int _node1;
    int _node2;
    std::string _name;

public:
    explicit Element(int node1, int node2): _node1{node1}, _node2{node2}{}
    [[nodiscard]] int get_node1() const {return _node1;}
    [[nodiscard]] int get_node2() const {return _node2;}
    [[nodiscard]] std::string get_name() const {return _name;}
    void set_name(const std::string& name) {_name = name;}
    void change_node_value (int node, int value);

    [[nodiscard]] int get_node(int node) const;
    [[nodiscard]] virtual float get_properties() const = 0;
    [[nodiscard]] virtual Type get_type() const = 0;
    [[nodiscard]] virtual bool is_passive() const = 0;
    [[nodiscard]] virtual std::complex<float> get_impedance(float c_freq) const = 0;
    [[nodiscard]] virtual std::complex<float> get_admittance(float c_freq) const = 0;
    [[nodiscard]] virtual std::complex<float> get_complex_value() const = 0;
//    [[nodiscard]] virtual Voltage get_voltage(std::complex<float> current) const = 0;
//    [[nodiscard]] virtual Current get_current(std::complex<float> voltage) const = 0;

    ~Element() = default;
};


#endif //CIRCUITSIMULATOR_ELEMENT_H
