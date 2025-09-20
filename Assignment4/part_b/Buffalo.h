#ifndef BUFFALO_H
#define BUFFALO_H

#include "Bovidae.h"

class Buffalo : public Bovidae {
public:
    virtual const char* getType() const;
};

#endif