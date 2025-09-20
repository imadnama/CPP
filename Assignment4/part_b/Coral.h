#ifndef CORAL_H
#define CORAL_H

#include "StationaryAnimal.h"

class Coral : public StationaryAnimal {
public:
    virtual void eat() const;
    virtual const char* getType() const;
};

#endif