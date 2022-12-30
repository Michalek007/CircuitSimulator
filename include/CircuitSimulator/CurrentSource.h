//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_CURRENTSOURCE_H
#define CIRCUITSIMULATOR_CURRENTSOURCE_H

#include "Element.h"
#include "Source.h"

class CurrentSource: public Source {
public:
    CurrentSource(int node1, int node2, float amp, float freq=0, float phase=0): Source(node1, node2, amp, freq, phase)
    {}
    [[nodiscard]] std::complex<float> get_current() const;
};


#endif //CIRCUITSIMULATOR_CURRENTSOURCE_H
