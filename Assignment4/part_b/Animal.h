#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
public:
    virtual ~Animal() {}
    virtual void eat() const = 0;
    virtual void show() const = 0;
    virtual const char* getType() const = 0;
};

#endif