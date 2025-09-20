#ifndef SHEEP_H
#define SHEEP_H

#include "Bovidae.h"

class Sheep : public Bovidae {
public:
    virtual const char* getType() const;
};

#endif