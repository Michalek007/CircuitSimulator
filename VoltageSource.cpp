//
// Created by Michał on 23.12.2022.
//

#include "VoltageSource.h"

Complex VoltageSource::get_voltage() const {
    if (get_freq() == 0){
        return Complex {get_amp(), 0};
    }
    return Complex {1, 1};
}
