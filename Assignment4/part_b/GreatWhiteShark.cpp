#include "GreatWhiteShark.h"
#include <iostream>

GreatWhiteShark::GreatWhiteShark() : Carnivore("Fish") {}

const char* GreatWhiteShark::getType() const {
    return "GreatWhiteShark";
}

void GreatWhiteShark::show() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Water diving." << std::endl;
}