#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "MobileAnimal.h"
#include "Lion.h"

class Zoo {
public:
    Zoo();
    ~Zoo();

    void addAnimal(Animal* newAnimal);
    void feedAll() const;
    void showAll() const;
    void activateAllMobile() const;
    void lionHuntingShow() const;

private:
    Animal* m_allAnimals[200];
    MobileAnimal* m_mobileAnimals[100];
    Lion* m_lions[100];

    int m_allCount;
    int m_mobileCount;
    int m_lionCount;
};

#endif