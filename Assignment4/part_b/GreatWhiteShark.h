#ifndef GREATWHITESHARK_H
#define GREATWHITESHARK_H

#include "Carnivore.h"

class GreatWhiteShark : public Carnivore {
public:
    GreatWhiteShark();
    virtual const char* getType() const;
    virtual void show() const;
};

#endif