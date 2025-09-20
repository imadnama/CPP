#ifndef LION_H
#define LION_H

#include "Carnivore.h"

class Lion : public Carnivore {
public:
    Lion();
    virtual const char* getType() const;
    virtual void show() const;
    void huntInStadium() const;
};

#endif