#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "MobileAnimal.h"

// All plant eating animals
class Herbivore : public MobileAnimal {
public:
    virtual void eat() const;
    virtual void show() const;
};

#endif