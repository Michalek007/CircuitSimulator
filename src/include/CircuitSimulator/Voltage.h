//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_VOLTAGE_H
#define CIRCUITSIMULATOR_VOLTAGE_H

#include <iostream>
#include <complex>
#include <cmath>

class Voltage {
private:
    float _amp;
    float _freq;
    float _c_freq;
    float _phase;
    std::complex<float> _complex_v;
public:
    explicit Voltage(float amp=0, float freq=0, float phase=0);
    Voltage(std::complex<float> complex_v, float freq);
    [[nodiscard]] float get_amp() const {return _amp;}
    [[nodiscard]] float get_freq() const {return _freq;}
    [[nodiscard]] float get_c_freq() const {return _c_freq;}
    [[nodiscard]] float get_phase() const {return _phase;}
    [[nodiscard]] std::complex<float> get_complex_value() const {return _complex_v;}
    void display() const;
};


#endif //CIRCUITSIMULATOR_VOLTAGE_H
