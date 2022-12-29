#include <iostream>
#include "Circuit.h"

int main() {
    std::shared_ptr<Element> element1 = std::make_shared<Element>(0, 1);
    std::shared_ptr<Element> element2 = std::make_shared<Element>(1, 2);
    std::shared_ptr<Element> element3 = std::make_shared<Element>(2, 0);
    std::vector<std::shared_ptr<Element>> elements {element1, element2, element3};
    Circuit circuit {elements};
    return 0;
}
