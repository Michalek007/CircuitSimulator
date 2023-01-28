//
// Created by Michał on 06.01.2023.
//

#include "CircuitTests.h"

void CircuitTests::circuit_test_1() {
    std::shared_ptr<Element> e1 = std::make_shared<Capacitor>(3, 1, 10 * 1e-03);
    std::shared_ptr<Element> e2 = std::make_shared<Capacitor>(2, 0, 1e-06);
    std::shared_ptr<Element> e3 = std::make_shared<Resistor>(1, 4, 1000);
    std::shared_ptr<Element> e4 = std::make_shared<Resistor>(0, 4, 1000);
    std::shared_ptr<Element> e5 = std::make_shared<Source>(0, 3, 1, Type::voltage, 100);
    std::shared_ptr<Element> e6 = std::make_shared<Inductor>(1, 2, 1);
    std::shared_ptr<Element> e7 = std::make_shared<Resistor>(2, 5, 1000);
    std::shared_ptr<Element> e8 = std::make_shared<Resistor>(0, 5, 1000);
    e1->set_name("c1");
    e2->set_name("c2");
    e3->set_name("r1");
    e4->set_name("r2");
    e5->set_name("e1");
    e6->set_name("l1");
    e7->set_name("r3");
    e8->set_name("r4");

    std::vector<std::shared_ptr<Element>> elements {e1, e2, e3, e4, e5, e6, e7, e8};
    Circuit circuit {elements, 100};

    circuit.calculate();
    circuit.calculate_elements_voltage();
    circuit.calculate_elements_current();
    circuit.display_branches_voltage();
    circuit.display_elements_properties();
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

    circuit.calculate();
    circuit.calculate_elements_voltage();
    circuit.calculate_elements_current();
    circuit.display_branches_voltage();
    circuit.display_elements_properties();
}

void CircuitTests::circuit_test_3() {
    std::shared_ptr<Element> e1 = std::make_shared<Source>(0, 1, 1, Type::voltage);
    std::shared_ptr<Element> e2 = std::make_shared<Resistor>(1, 2, 1000);
    std::shared_ptr<Element> e3 = std::make_shared<Resistor>(2, 0, 1000);
    std::shared_ptr<Element> e4 = std::make_shared<Source>(4, 0, 1, Type::voltage);
    std::shared_ptr<Element> e5 = std::make_shared<Resistor>(2, 3, 1000);
    std::shared_ptr<Element> e6 = std::make_shared<Resistor>(3, 0, 1000);
    std::shared_ptr<Element> e7 = std::make_shared<Resistor>(3, 4, 1000);
    e1->set_name("e1");
    e2->set_name("r1");
    e3->set_name("r2");
    e4->set_name("e2");
    e5->set_name("r3");
    e6->set_name("r4");
    e7->set_name("r5");

    std::vector<std::shared_ptr<Element>> elements {e1, e2, e3, e4, e5, e6, e7};
    Circuit circuit {elements};

    circuit.calculate();
    circuit.calculate_elements_voltage();
    circuit.calculate_elements_current();
    circuit.display_branches_voltage();
    circuit.display_elements_properties();
}

void CircuitTests::circuit_test_4() {
    std::shared_ptr<Element> e1 = std::make_shared<Source>(0, 1, 1, Type::voltage, 100);
    std::shared_ptr<Element> e2 = std::make_shared<Resistor>(1, 2, 1000);
    std::shared_ptr<Element> e3 = std::make_shared<Resistor>(2, 3, 1);
    std::shared_ptr<Element> e4 = std::make_shared<Inductor>(3, 0, 1);
    e1->set_name("e1");
    e2->set_name("r1");
    e3->set_name("c1");
    e4->set_name("l1");

    std::vector<std::shared_ptr<Element>> elements {e1, e2, e3, e4};
    Circuit circuit {elements, 100};

    circuit.calculate();
    circuit.calculate_elements_voltage();
    circuit.calculate_elements_current();
    circuit.display_branches_voltage();
    circuit.display_elements_properties();
}

void CircuitTests::circuit_test_5() {
    std::shared_ptr<Element> e1 = std::make_shared<Source>(0, 1, 1, Type::voltage, 100);
    std::shared_ptr<Element> e2 = std::make_shared<Resistor>(1, 2, 1000);
    std::shared_ptr<Element> e3 = std::make_shared<Capacitor>(2, 0, 0.001);
    e1->set_name("e1");
    e2->set_name("r1");
    e3->set_name("c1");

    std::vector<std::shared_ptr<Element>> elements {e1, e2, e3};
    Circuit circuit {elements, 100};

    circuit.calculate();
    circuit.calculate_elements_voltage();
    circuit.calculate_elements_current();
    circuit.display_branches_voltage();
    circuit.display_elements_properties();
}

bool CircuitTests::float_comparison(float x, float y) {
    if (x <= y + 0.0005 && x >= y - 0.0005){
        return true;
    }
    else{
        return false;
    }
}
