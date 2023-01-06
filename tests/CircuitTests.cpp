//
// Created by Michał on 06.01.2023.
//

#include "CircuitTests.h"

void CircuitTests::circuit_test_1() {
    std::shared_ptr<Element> element1 = std::make_shared<Capacitor>(3, 1, 10 * 1e-03);
    std::shared_ptr<Element> element2 = std::make_shared<Capacitor>(2, 0, 1e-06);
    std::shared_ptr<Element> element3 = std::make_shared<Resistor>(1, 4, 1000);
    std::shared_ptr<Element> element4 = std::make_shared<Resistor>(0, 4, 1000);
    std::shared_ptr<Element> element5 = std::make_shared<Source>(0, 3, 1, Type::voltage, 100);
    std::shared_ptr<Element> element6 = std::make_shared<Inductor>(1, 2, 1);
    std::shared_ptr<Element> element7 = std::make_shared<Resistor>(2, 5, 1000);
    std::shared_ptr<Element> element8 = std::make_shared<Resistor>(0, 5, 1000);
    element1->set_name("c1");
    element2->set_name("c2");
    element3->set_name("r1");
    element4->set_name("r2");
    element5->set_name("e1");
    element6->set_name("l1");
    element7->set_name("r3");
    element8->set_name("r4");
    std::vector<std::shared_ptr<Element>> elements {element1, element2, element3, element4,
                                                    element5, element6, element7, element8};
    Circuit circuit {elements, 100};


//    circuit.display_node_elements();
//    circuit.display_nodes();
    circuit.display_branch();
    circuit.display_matrix_nodes();
    circuit.calculate();
    circuit.display_branches_voltage();
}

void CircuitTests::circuit_test_2() {
    std::shared_ptr<Element> e1 = std::make_shared<Source>(0, 1, 1, Type::voltage, 100);
    std::shared_ptr<Element> e2 = std::make_shared<Resistor>(1, 2, 1000);
    std::shared_ptr<Element> e3 = std::make_shared<Resistor>(2, 3, 1000);
    std::shared_ptr<Element> e4 = std::make_shared<Inductor>(3, 0, 1e-03);
    std::shared_ptr<Element> e5 = std::make_shared<Inductor>(2, 4, 1e-03);
    std::shared_ptr<Element> e6 = std::make_shared<Capacitor>(4, 0, 10 * 1e-06);
    std::shared_ptr<Element> e7 = std::make_shared<Resistor>(4, 5, 1000);
    std::shared_ptr<Element> e8 = std::make_shared<Source>(5, 6, 2, Type::voltage, 100);
    std::shared_ptr<Element> e9 = std::make_shared<Capacitor>(6, 0, 10 * 1e-06);
    std::shared_ptr<Element> e10 = std::make_shared<Capacitor>(5, 7, 10 * 1e-06);
    std::shared_ptr<Element> e11 = std::make_shared<Resistor>(7, 0, 1000);
    e1->set_name("e1");
    e2->set_name("r1");
    e3->set_name("r2");
    e4->set_name("l1");
    e5->set_name("l2");
    e6->set_name("c1");
    e7->set_name("r3");
    e8->set_name("e2");
    e9->set_name("c2");
    e10->set_name("c3");
    e11->set_name("r4");
    std::vector<std::shared_ptr<Element>> elements {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11};
    Circuit circuit {elements, 100};


//    circuit.display_node_elements();
//    circuit.display_nodes();
    circuit.display_branch();
    circuit.display_matrix_nodes();
    circuit.calculate();
    circuit.display_branches_voltage();
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
