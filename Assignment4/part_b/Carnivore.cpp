#include "Carnivore.h"
#include <iostream>

Carnivore::Carnivore(const char* food) : m_food(food) {}

void Carnivore::eat() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Preying! Eating " << m_food << "! Yummy!" << std::endl;
}

void Carnivore::exercise() const {
    std::cout << this->getType() << std::endl;
    std::cout << "Running after potential food." << std::endl;
}