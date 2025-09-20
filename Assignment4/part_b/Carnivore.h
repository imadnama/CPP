#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "MobileAnimal.h"

// All meat eating animals
class Carnivore : public MobileAnimal {
public:
    Carnivore(const char* food);
    virtual void eat() const;
    virtual void exercise() const;
private:
    const char* m_food;
};

#endif