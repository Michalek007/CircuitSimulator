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
    [[nodiscard]] float get_properties() const override {return _resistance;}
    [[nodiscard]] Type get_type() const override {return Type::passive;}
    [[nodiscard]] bool is_passive() const override {return true;}
    [[nodiscard]] std::complex<float> get_impedance(float c_freq) const override;
    [[nodiscard]] std::complex<float> get_admittance(float c_freq) const override;
    [[nodiscard]] std::complex<float> get_complex_value() const override {return {0, 0};}
//    [[nodiscard]] Voltage get_voltage(std::complex<float> current) const override;
//    [[nodiscard]] Current get_current(std::complex<float> voltage) const override;
};


#endif //CIRCUITSIMULATOR_RESISTOR_H
