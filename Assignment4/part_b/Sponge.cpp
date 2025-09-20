#include "Sponge.h"
#include <iostream>

void Sponge::eat() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Filtering waterflow to obtain food." << std::endl;
}

const char* Sponge::getType() const {
    return "Sponge";
}