//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_VOLTAGESOURCE_H
#define CIRCUITSIMULATOR_VOLTAGESOURCE_H

#include "Element.h"
#include "Source.h"

class VoltageSource: public Source {
public:
    VoltageSource(int node1, int node2, float amp, float freq=0, float phase=0): Source(node1, node2, amp, freq, phase)
    {}

    [[nodiscard]] std::complex<float> get_voltage() const;
};


#endif //CIRCUITSIMULATOR_VOLTAGESOURCE_H
