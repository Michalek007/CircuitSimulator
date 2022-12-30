//
// Created by Michał on 22.12.2022.
//

#include "Inductor.h"

std::complex<float> Inductor::get_impedance(float c_freq) const {
    return {0, _inductance * c_freq};
}
