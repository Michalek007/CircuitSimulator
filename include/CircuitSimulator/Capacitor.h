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
    [[nodiscard]] float get_properties() const override {return _capacity;}
    [[nodiscard]] Type get_type() const override {return Type::passive;}
    [[nodiscard]] bool is_passive() const override {return true;}
    [[nodiscard]] std::complex<float> get_impedance(float c_freq) const override;
    [[nodiscard]] std::complex<float> get_admittance(float c_freq) const override;
    [[nodiscard]] std::complex<float> get_complex_value() const override {return {0, 0};}
//    [[nodiscard]] Voltage get_voltage(std::complex<float> current) const override;
//    [[nodiscard]] Current get_current(std::complex<float> voltage) const override;
};


#endif //CIRCUITSIMULATOR_CAPACITOR_H

