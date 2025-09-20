#include "Coral.h"
#include <iostream>

void Coral::eat() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Feeding on a variety of small sea-organisms." << std::endl;
}

const char* Coral::getType() const {
    return "Coral";
}