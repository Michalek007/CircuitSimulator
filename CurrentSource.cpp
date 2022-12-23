//
// Created by Michał on 23.12.2022.
//

#include "CurrentSource.h"

Complex CurrentSource::get_current() const {
    if (get_freq() == 0){
        return Complex {get_amp(), 0};
    }
    return Complex {1, 1};
}
