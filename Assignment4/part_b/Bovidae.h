#ifndef BOVIDAE_H
#define BOVIDAE_H

#include "Herbivore.h"

// Animals from the cattle family
class Bovidae : public Herbivore {
public:
    virtual void exercise() const;
};

#endif