//
// Created by Michał on 28.12.2022.
//

#ifndef CIRCUITSIMULATOR_SOURCE_H
#define CIRCUITSIMULATOR_SOURCE_H

#include "Element.h"


class Source: public Element {
private:
    float _amp;
    float _freq;
    float _c_freq;
    float _phase;
    Type _type;
public:
    Source(int node1, int node2, float amp, Type type, float freq=0, float phase=0);
    [[nodiscard]] float get_amp() const {return _amp;}
    [[nodiscard]] float get_freq() const {return _freq;}
    [[nodiscard]] float get_c_freq() const {return _c_freq;}
    [[nodiscard]] float get_phase() const {return _phase;}
//    [[nodiscard]] Voltage get_voltage(std::complex<float> current) const override;
//    [[nodiscard]] Current get_current(std::complex<float> voltage) const override;
    [[nodiscard]] float get_properties() const override {return _amp;}
    [[nodiscard]] Type get_type() const override {return _type;}
    [[nodiscard]] bool is_passive() const override {return false;}
    [[nodiscard]] std::complex<float> get_impedance(float c_freq) const override {return {-1, -1};}
    [[nodiscard]] std::complex<float> get_admittance(float c_freq) const override {return {-1, -1};}
    [[nodiscard]] std::complex<float> get_complex_value() const override;


};


#endif //CIRCUITSIMULATOR_SOURCE_H
