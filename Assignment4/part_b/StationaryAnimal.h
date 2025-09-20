#ifndef STATIONARY_ANIMAL_H
#define STATIONARY_ANIMAL_H

#include "Animal.h"

class StationaryAnimal : public virtual Animal {
public:
    virtual ~StationaryAnimal() {}
    virtual void show() const {
        std::cout << this->getType() << std::endl;
        std::cout << "Beautiful & colorful views!" << std::endl;
    }
};

#endif