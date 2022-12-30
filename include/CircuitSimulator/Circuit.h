//
// Created by Michał on 15.12.2022.
//

#ifndef CIRCUITSIMULATOR_CIRCUIT_H
#define CIRCUITSIMULATOR_CIRCUIT_H

#include "Element.h"

class Circuit {
private:
    std::vector<std::shared_ptr<Element>> _elements;
    std::vector<int> _nodes;
    std::map<int, std::vector<std::shared_ptr<Element>>> _node_elements;
    std::map<std::string, std::unordered_set<std::shared_ptr<Element>>> _branch;
    float _freq;
    float _c_freq;
public:
    explicit Circuit(std::vector<std::shared_ptr<Element>> elements, float freq=0);
    [[nodiscard]] std::shared_ptr<Element> find_element(int node, int condition = -1) const;
    void display_nodes() const;
    void display_node_elements() const;
    void display_branch() const;
    void set_branches();
    [[nodiscard]] bool is_node(int node) const;
    static std::string get_node_key(int node1, int node2);
};


#endif //CIRCUITSIMULATOR_CIRCUIT_H
