#include <iostream>
#include "Circuit.h"
#include "tests/CircuitTests.h"

int main() {
    CircuitTests::circuit_test_1();
    CircuitTests::circuit_test_2();
    CircuitTests::circuit_test_3();
    CircuitTests::circuit_test_4();
    CircuitTests::circuit_test_5();
//    std::complex<float> W1 {0.01,-0};
//    std::complex<float> W2 {0.00605216,0.00314159};
//    std::complex<float> W {0.00605341,0.00314032};
//    std::cout << W1/W << std::endl;
//    std::cout << abs(W1/W) << std::endl;
//    std::cout << W2/W << std::endl;
//    std::cout << abs(W2/W) << std::endl;
//    std::cout << CircuitTests::float_comparison(0.739836, 0.74) << std::endl;
//    std::cout << CircuitTests::float_comparison(0.999924, 0.9998) << std::endl;
    std::vector<std::shared_ptr<Element>> elements;
    char type;
    int node1;
    int node2;
    float value;
    float freq {0};
    std::string source_type;
    while (true){
        std::shared_ptr<Element> e;
        std::cout << "Type: " << std::endl;
        std::cin >> type;
        std::cout << type << std::endl;
        std::cout << "Nodes: " << std::endl;
        std::cin >> node1 >> node2;
        std::cout << node1 << node2 << std::endl;
        std::cout << "Value: " << std::endl;
        std::cin >> value;
        std::cout << value << std::endl;
        if (type == 'r') {
            e = std::make_shared<Resistor>(node1, node2, value);
        }
        else if (type == 'c'){
            e = std::make_shared<Capacitor>(node1, node2, value);
        }
        else if (type == 'l'){
            e = std::make_shared<Inductor>(node1, node2, value);
        }
        else if (type == 'v'){
            std::cout << "Freq: " << std::endl;
            std::cin >> freq;
            std::cout << freq << std::endl;
            e = std::make_shared<Source>(node1, node2, value, Type::voltage, freq);
        }
        else if (type == 'a'){
            std::cout << "Freq: " << std::endl;
            std::cin >> freq;
            std::cout << freq << std::endl;
            e = std::make_shared<Source>(node1, node2, value, Type::current, freq);
        }
        else if (type == 'x'){
            try{
                Circuit circuit {elements, freq};
                circuit.calculate();
                circuit.calculate_elements_current();
                circuit.calculate_elements_voltage();
                circuit.display_elements_properties();
            }
            catch (const std::invalid_argument& error){
                std::cerr << error.what();
                continue;
            }
            break;
        }
        else{
            std::cout << "Wrong element." << std::endl;
            continue;
        }
        e->set_name({type, (char)(node1+'0'), (char)(node2+'0')});
        elements.push_back(e);
        std::cout << "Element " << e->get_name() << " added to circuit." << std::endl;
    }
    return 0;
}
