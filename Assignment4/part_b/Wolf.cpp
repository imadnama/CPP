#include "Wolf.h"
#include <iostream>

Wolf::Wolf() : Carnivore("Rabbit") {}

const char* Wolf::getType() const {
    return "Wolf";
}

void Wolf::show() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Joyful running and flapping their tail." << std::endl;
}