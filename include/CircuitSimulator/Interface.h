//
// Created by Michał on 27.01.2023.
//

#ifndef CIRCUITSIMULATOR_INTERFACE_H
#define CIRCUITSIMULATOR_INTERFACE_H
#include "Circuit.h"

class Interface {
private:
    Interface() = default;
    Interface(const Interface&) = delete;
    Interface operator=(const Interface&) = delete;
    Interface(Interface&&) = delete;
    Interface& operator=(Interface&&) = delete;

    const std::vector<std::string> _commands {"calculate", "display", "add", "remove", "reset"};
    const std::vector<std::string> _types {"R", "r", "l", "L", "c", "C", "V", "v", "A", "a"};
    float _freq {0};
public:
    static Interface& GetInstance() {

        static auto* interface = new Interface();
        return *interface;
    }
    [[nodiscard]] Circuit create_circuit(const std::vector<std::shared_ptr<Element>>& elements) const;
    std::vector<std::shared_ptr<Element>> get_elements();

    void solve_circuit(Circuit& circuit);
    void display_element_properties(const Circuit& circuit);
    void display_branches(const Circuit& circuit);
    void display_branch_voltage(const Circuit& circuit) const;
    void display_branch_current(const Circuit& circuit) const;
    void display_all_elements(const Circuit& circuit);

    void auto_setup();
    void user_interface();
};


#endif //CIRCUITSIMULATOR_INTERFACE_H
