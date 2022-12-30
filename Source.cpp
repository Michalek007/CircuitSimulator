//
// Created by Michał on 28.12.2022.
//

#include "Source.h"

std::complex<float> Source::get_complex_value() const {
    if (_freq == 0){
        return {_amp, 0};
    }
    return {_amp * std::cos(_phase), _amp * std::sin(_phase)};
}
