//
// Created by Michał on 22.12.2022.
//

#include "Capacitor.h"

std::complex<float>  Capacitor::get_impedance(float c_freq) const {
    return {0, -1/(_capacity * c_freq)};
}

std::complex<float> Capacitor::get_admittance(float c_freq) const {
    return {0, _capacity * c_freq};
}
