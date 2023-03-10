//
// Created by Michał on 23.12.2022.
//

#include "Current.h"

Current::Current(float amp, float freq, float phase) : _amp{amp}, _freq{freq}, _phase{phase}{
    _c_freq = (float)(freq*2*std::numbers::pi);
    _complex_v = {_amp * std::cos(_phase), _amp * std::sin(_phase)};
}

Current::Current(std::complex<float> complex_v, float freq): _complex_v{complex_v}, _freq{freq} {
    _amp = abs(complex_v);
    _phase = arg(complex_v);
    _c_freq = (float)(freq*2*std::numbers::pi);
}

void Current::display() const {
    if (_amp == 0){
        std::cout << 0 << std::endl;
        return;
    }
    if (_freq == 0){
        std::cout << "Current: " << _amp << std::endl;
        return;
    }
//    std::cout << _amp << " * sin(" << _c_freq;
//    if (_phase > 0){
//        std::cout << " + " << _phase << ") A" << std::endl;
//    }
//    else if (_phase < 0){
//        std::cout << " " << _phase << ") A" << std::endl;
//    }
//    else{
//        std::cout << ") A" << std::endl;
//    }
    std::cout << "Current: " << _amp  << " Phase: " << _phase << std::endl;
}
