//
// Created by Michał on 22.12.2022.
//

#include "Resistor.h"

std::complex<float> Resistor::get_impedance(float c_freq) const {
    return {_resistance, 0};
}
