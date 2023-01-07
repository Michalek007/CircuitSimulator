//
// Created by Michał on 23.12.2022.
//

#include "Voltage.h"


Voltage::Voltage(float amp, float freq, float phase) : _amp{amp}, _freq{freq}, _phase{phase}{
    _c_freq = (float)(freq*2*std::numbers::pi);
    _complex_v = {_amp * std::cos(_phase), _amp * std::sin(_phase)};
}

Voltage::Voltage(std::complex<float> complex_v, float freq): _complex_v{complex_v}, _freq{freq} {
    _amp = abs(complex_v);
    _phase = arg(complex_v);
    _c_freq = (float)(freq*2*std::numbers::pi);
}

void Voltage::display() const {
    std::cout << _amp << " * sin(" << _c_freq;
    if (_phase > 0){
        std::cout << " + " << _phase << ")" << std::endl;
    }
    else if (_phase < 0){
        std::cout << " " << _phase << ")" << std::endl;
    }
    else{
        std::cout << ")" << std::endl;
    }
}
