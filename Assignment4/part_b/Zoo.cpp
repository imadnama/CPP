#include "Zoo.h"
#include <iostream>
#include <typeinfo>

Zoo::Zoo() : m_allCount(0), m_mobileCount(0), m_lionCount(0) {}

Zoo::~Zoo() {
    for (int i = 0; i < m_allCount; ++i) {
        delete m_allAnimals[i];
    }
}

void Zoo::addAnimal(Animal* newAnimal) {
    if (m_allCount < 200) {
        m_allAnimals[m_allCount++] = newAnimal;

        MobileAnimal* mobile = dynamic_cast<MobileAnimal*>(newAnimal);
        if (mobile != nullptr && m_mobileCount < 100) {
            m_mobileAnimals[m_mobileCount++] = mobile;
        }

        Lion* lion = dynamic_cast<Lion*>(newAnimal);
        if (lion != nullptr && m_lionCount < 100) {
            m_lions[m_lionCount++] = lion;
        }
    }
}

void Zoo::feedAll() const {
    for (int i = 0; i < m_allCount; ++i) {
        m_allAnimals[i]->eat();
    }
}

void Zoo::showAll() const {
    for (int i = 0; i < m_allCount; ++i) {
        m_allAnimals[i]->show();
    }
}

void Zoo::activateAllMobile() const {
    for (int i = 0; i < m_mobileCount; ++i) {
        m_mobileAnimals[i]->exercise();
    }
}

void Zoo::lionHuntingShow() const {
    for (int i = 0; i < m_lionCount; ++i) {
        m_lions[i]->huntInStadium();
    }
}