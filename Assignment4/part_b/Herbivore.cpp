#include "Herbivore.h"
#include <iostream>

void Herbivore::eat() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Eating grass." << std::endl;
}

void Herbivore::show() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Borred staring at the guests." << std::endl;
}