//
// Created by Michał on 22.12.2022.
//

#include "Inductor.h"

Complex Inductor::get_impedance(float c_freq) const {
    Complex impedance {0, get_inductance() * c_freq};
    return impedance;
}
