#include <iostream>
#include "Circuit.h"
#include "tests/CircuitTests.h"

int main() {
    CircuitTests::circuit_test_1();
    CircuitTests::circuit_test_2();

//    std::complex<float> W1 {0.01,-0};
    std::complex<float> W2 {0.00605216,0.00314159};
    Voltage v1 {W2, 100};
    v1.display();
//    std::complex<float> W {0.00605341,0.00314032};
//    std::cout << W1/W << std::endl;
//    std::cout << abs(W1/W) << std::endl;
//    std::cout << W2/W << std::endl;
//    std::cout << abs(W2/W) << std::endl;
//    std::cout << CircuitTests::float_comparison(0.739836, 0.74) << std::endl;
//    std::cout << CircuitTests::float_comparison(0.999924, 0.9998) << std::endl;
    return 0;
}
