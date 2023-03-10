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
    std::vector<std::shared_ptr<Element>> _elements;
    Circuit _circuit;
public:
    static Interface& GetInstance() {

        static auto* interface = new Interface();
        return *interface;
    }
    [[nodiscard]] Circuit create_circuit(const std::vector<std::shared_ptr<Element>>& elements) const;
    std::vector<std::shared_ptr<Element>> get_elements();

    void solve_circuit();
    void display_element_properties(const std::string& name);
    void display_branches();
    void display_branch_voltage() const;
    void display_branch_current() const;
    void display_all_elements();

    void auto_setup();
    void user_interface();
};


#endif //CIRCUITSIMULATOR_INTERFACE_H
