//
// Created by Michał on 28.12.2022.
//

#include "Source.h"

Source::Source(int node1, int node2, float amp, Type type, float freq, float phase) : Element(node1, node2),
    _amp{amp}, _type{type}, _freq{freq}, _phase{phase}{
    _c_freq = (float)(freq*2*std::numbers::pi);
}

std::complex<float> Source::get_complex_value() const {
    if (_freq == 0){
        return {_amp, 0};
    }
    return {_amp * std::cos(_phase), _amp * std::sin(_phase)};
}
