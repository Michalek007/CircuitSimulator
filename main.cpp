#include <iostream>
#include "Circuit.h"

int main() {
    std::shared_ptr<Element> element1 = std::make_shared<Element>(0, 3);
    std::shared_ptr<Element> element2 = std::make_shared<Element>(3, 1);
    std::shared_ptr<Element> element3 = std::make_shared<Element>(1, 4);
    std::shared_ptr<Element> element4 = std::make_shared<Element>(0, 4);
    std::shared_ptr<Element> element5 = std::make_shared<Element>(1, 2);
    std::shared_ptr<Element> element6 = std::make_shared<Element>(0, 2);
    std::shared_ptr<Element> element7 = std::make_shared<Element>(2, 5);
    std::shared_ptr<Element> element8 = std::make_shared<Element>(0, 5);
    element1->set_name("element1");
    element2->set_name("element2");
    element3->set_name("element3");
    element4->set_name("element4");
    element5->set_name("element5");
    element6->set_name("element6");
    element7->set_name("element7");
    element8->set_name("element8");

    std::vector<std::shared_ptr<Element>> elements {element1, element2, element3, element4,
                                                    element5, element6, element7, element8};
    Circuit circuit {elements};
    circuit.display_node_elements();
    circuit.display_nodes();
    circuit.display_branch();
    return 0;
}
