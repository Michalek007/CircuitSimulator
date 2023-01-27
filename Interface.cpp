//
// Created by Michał on 27.01.2023.
//

#include "Interface.h"

void Interface::change_mode() {
    _auto_mode = !_auto_mode;
}

std::vector<std::shared_ptr<Element>> Interface::get_elements() {
    std::vector<std::shared_ptr<Element>> elements;
    std::string type {"help"};
    int node1, node2;
    float value;
    float freq {0};
    std::string source_type;
    bool const_freq_guard {false};
    while (true){
        std::shared_ptr<Element> e;
        std::cout << "Type: " << std::endl;
        std::cin >> type;
        std::cout << type << std::endl;

        if (type == "help"){
            std::cout << "All available types: " << std::endl;
            for (auto &item: _types){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }

        if (type == "x"){
            _freq = freq;
            return elements;
        }
        if (!std::ranges::any_of(_types.begin(), _types.end(), [&type](const std::string& t){return type == t;})){
            std::cout << "There is no element with that type. Write help to get type names." << std::endl;
            continue;
        }

        std::cout << "Nodes: " << std::endl;
        std::cin >> node1 >> node2;
        std::cout << node1 << node2 << std::endl;
        std::cout << "Value: " << std::endl;
        std::cin >> value;
        std::cout << value << std::endl;

        if (type == "r" || type == "R") {
            e = std::make_shared<Resistor>(node1, node2, value);
        }
        else if (type == "c" || type == "C"){
            e = std::make_shared<Capacitor>(node1, node2, value);
        }
        else if (type == "l" || type == "L"){
            e = std::make_shared<Inductor>(node1, node2, value);
        }
        else{
            if (!const_freq_guard){
                std::cout << "Freq: " << std::endl;
                std::cin >> freq;
                std::cout << freq << std::endl;
                const_freq_guard = true;
            }
            if (type == "v" || type == "V"){
                e = std::make_shared<Source>(node1, node2, value, Type::voltage, freq);
            }
            else if (type == "a" || type == "A"){
                e = std::make_shared<Source>(node1, node2, value, Type::current, freq);
            }
        }

        e->set_name({type[0], (char)(node1+'0'), (char)(node2+'0')});
        elements.push_back(e);
        std::cout << "Element " << e->get_name() << " added to circuit." << std::endl;
    }
    return elements;
}

Circuit Interface::create_circuit(const std::vector<std::shared_ptr<Element>>& elements) const{
    Circuit circuit {elements, _freq};
    return circuit;
}

void Interface::auto_setup() {
    auto elements = get_elements();
    try{
        auto circuit = create_circuit(elements);

        circuit.calculate();
        circuit.calculate_elements_current();
        circuit.calculate_elements_voltage();

        circuit.display_branches_voltage();
        circuit.display_elements_properties();
    }
    catch (const std::invalid_argument& error){
        std::cerr << error.what();
    }
}

void Interface::user_interface() {
    std::cout << "Circuit Simulator. " << " Enter your elements with following instruction: type, first node, second node, value and eventually freq." << std::endl;
    std::cout << "Type help to get command list. " << std::endl;

}
