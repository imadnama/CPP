#ifndef ZEBRA_H
#define ZEBRA_H

#include "Equidae.h"

class Zebra : public Equidae {
public:
    virtual const char* getType() const;
};

#endif