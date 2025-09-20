#ifndef MOBILE_ANIMAL_H
#define MOBILE_ANIMAL_H

#include "Animal.h"

class MobileAnimal : public virtual Animal {
public:
    virtual ~MobileAnimal() {}
    virtual void exercise() const = 0;
};

#endif