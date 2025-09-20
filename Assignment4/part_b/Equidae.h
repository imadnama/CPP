#ifndef EQUIDAE_H
#define EQUIDAE_H

#include "Herbivore.h"

// Animals from the horse family
class Equidae : public Herbivore {
public:
    virtual void exercise() const;
};

#endif