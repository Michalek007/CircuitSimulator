//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_VOLTAGESOURCE_H
#define CIRCUITSIMULATOR_VOLTAGESOURCE_H

#include "Element.h"
#include "Source.h"

// TODO: class Voltage with _phase, _freq, _c_freq, _amp, _complex_v
// constructor with _complex_value
// constructor with _phase, _freq, _amp
// getters
// override operators for ostream
// or method display

class VoltageSource: public Source {
public:
    VoltageSource(int node1, int node2, float amp, float freq=0, float phase=0, Type type=Type::voltage)
    : Source(node1, node2, amp, type, freq, phase) {}

    [[nodiscard]] std::complex<float> get_voltage() const;
};


#endif //CIRCUITSIMULATOR_VOLTAGESOURCE_H
