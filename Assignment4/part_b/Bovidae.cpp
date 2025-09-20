#include "Bovidae.h"
#include <iostream>

void Bovidae::exercise() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Walking slowly in the garden." << std::endl;
}