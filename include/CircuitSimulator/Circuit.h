//
// Created by Michał on 15.12.2022.
//

#ifndef CIRCUITSIMULATOR_CIRCUIT_H
#define CIRCUITSIMULATOR_CIRCUIT_H

#include <Eigen/Dense>
#include "Element.h"
#include "Inductor.h"
#include "Capacitor.h"
#include "Resistor.h"
#include "Voltage.h"
#include "Current.h"

class Circuit {
private:
    std::vector<std::shared_ptr<Element>> _elements;

    std::map<int, std::vector<std::shared_ptr<Element>>> _node_elements;
    std::map<int, int> _matrix_nodes;

    std::vector<int> _nodes;
    std::map<std::shared_ptr<Element>, Voltage> _element_voltage;
    std::map<std::shared_ptr<Element>, Current> _element_current;
    std::map<std::string, std::complex<float>> _branch_voltage;
    std::map<std::string, std::complex<float>> _branch_current;
    std::map<std::string, std::unordered_set<std::shared_ptr<Element>>> _branches;
    int _ground;
    float _freq;
    float _c_freq;
    int last_node_value = 0;
public:
    explicit Circuit(std::vector<std::shared_ptr<Element>> elements, float freq=0);
    void display_nodes() const;
    void display_node_elements() const;
    void display_branch() const;
    void display_matrix_nodes() const;
    void display_branches_voltage() const;
    void set_branches();
    [[nodiscard]] bool is_node(int node) const;
    std::string get_node_key(int node1, int node2);
    [[nodiscard]] std::shared_ptr<Element> find_element(int node, int condition=-1) const;

    std::complex<float> get_branch_admittance(const std::string& branch);
    void calculate();
    void calculate_elements_voltage();
    void calculate_elements_current();

};


#endif //CIRCUITSIMULATOR_CIRCUIT_H
