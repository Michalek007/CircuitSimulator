//
// Created by Michał on 22.12.2022.
//

#include "Inductor.h"

std::complex<float> Inductor::get_impedance(float c_freq) const {
    if (c_freq == 0){
        return {-1, 0};
    }
    return {0, _inductance * c_freq};
}

std::complex<float> Inductor::get_admittance(float c_freq) const {
    if (c_freq == 0){
        return {-1, 0};
    }
    return {0, - 1/(_inductance * c_freq)};
}
