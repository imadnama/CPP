#include "Lion.h"
#include <iostream>

Lion::Lion() : Carnivore("Gnu") {}

const char* Lion::getType() const {
    return "Lion";
}

void Lion::show() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Royal walking in the garden." << std::endl;
}

void Lion::huntInStadium() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Hunting!" << std::endl;
}