//
// Created by Michał on 22.12.2022.
//

#include "Capacitor.h"

Complex Capacitor::get_impedance(float c_freq) const {
    Complex impedance {0, -1/(get_capacity() * c_freq)};
    return impedance;
}
