#ifndef HORSE_H
#define HORSE_H

#include "Equidae.h"

class Horse : public Equidae {
public:
    virtual const char* getType() const;
};

#endif