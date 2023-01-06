//
// Created by Michał on 06.01.2023.
//

#include "CircuitTests.h"

void CircuitTests::circuit_test_1() {

}

void CircuitTests::circuit_test_2() {

}

void CircuitTests::circuit_test_3() {

}

bool CircuitTests::float_comparison(float x, float y) {
    if (x <= y + 0.0005 && x >= y - 0.0005){
        return true;
    }
    else{
        return false;
    }
}
