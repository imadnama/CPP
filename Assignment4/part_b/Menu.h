#ifndef MENU_H
#define MENU_H

#include "Zoo.h"

class Menu {
public:
    Menu();
    void insertAnimals();
    void mainMenu();

private:
    Animal* getAnimalChoice();
    Zoo m_zoo;
};

#endif