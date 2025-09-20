#ifndef COW_H
#define COW_H

#include "Bovidae.h"

class Cow : public Bovidae {
public:
    virtual const char* getType() const;
};

#endif