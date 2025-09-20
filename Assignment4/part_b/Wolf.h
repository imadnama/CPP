#ifndef WOLF_H
#define WOLF_H

#include "Carnivore.h"

class Wolf : public Carnivore {
public:
    Wolf();
    virtual const char* getType() const;
    virtual void show() const;
};

#endif