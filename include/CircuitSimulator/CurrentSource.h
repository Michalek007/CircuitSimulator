//
// Created by Michał on 23.12.2022.
//

#ifndef CIRCUITSIMULATOR_CURRENTSOURCE_H
#define CIRCUITSIMULATOR_CURRENTSOURCE_H

#include "Element.h"

class CurrentSource: public Element {
private:
    float _amp;
    float _freq;
    float _c_freq;
    float _phase;
public:
    CurrentSource(int node1, int node2, float amp, float freq=0, float phase=0): Element(node1, node2),
    _amp{amp}, _freq{freq}, _phase{phase}{
        _c_freq = (float)(freq*2*std::numbers::pi);
    }
    [[nodiscard]] float get_amp() const {return _amp;}
    [[nodiscard]] float get_freq() const {return _freq;}
    [[nodiscard]] float get_c_freq() const {return _c_freq;}
    [[nodiscard]] float get_phase() const {return _phase;}
    [[nodiscard]] Complex get_current() const;
};


#endif //CIRCUITSIMULATOR_CURRENTSOURCE_H
