#include "Equidae.h"
#include <iostream>

void Equidae::exercise() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Running fast in circles." << std::endl;
}