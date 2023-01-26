//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_CURRENT_H
#define CIRCUITSIMULATOR_CURRENT_H

#include <iostream>
#include <complex>
#include <cmath>

class Current {
private:
    float _amp;
    float _freq;
    float _c_freq;
    float _phase;
    std::complex<float> _complex_v;
public:
    explicit Current(float amp=0, float freq=0, float phase=0);
    Current(std::complex<float> complex_v, float freq);
    [[nodiscard]] float get_amp() const {return _amp;}
    [[nodiscard]] float get_freq() const {return _freq;}
    [[nodiscard]] float get_c_freq() const {return _c_freq;}
    [[nodiscard]] float get_phase() const {return _phase;}
    [[nodiscard]] std::complex<float> get_complex_value() const {return _complex_v;}
    void display() const;
};


#endif //CIRCUITSIMULATOR_CURRENT_H
