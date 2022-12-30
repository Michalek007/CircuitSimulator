//
// Created by Michał on 23.12.2022.
//

#include "VoltageSource.h"

std::complex<float> VoltageSource::get_voltage() const {
    if (get_freq() == 0){
        return {get_amp(), 0};
    }
    return {1, 1};
}
