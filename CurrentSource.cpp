//
// Created by Michał on 23.12.2022.
//

#include "CurrentSource.h"

std::complex<float> CurrentSource::get_current() const {
    if (get_freq() == 0){
        return {get_amp(), 0};
    }
    return {1, 1};
}
