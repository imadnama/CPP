#ifndef SPONGE_H
#define SPONGE_H

#include "StationaryAnimal.h"

class Sponge : public StationaryAnimal {
public:
    virtual void eat() const;
    virtual const char* getType() const;
};

#endif