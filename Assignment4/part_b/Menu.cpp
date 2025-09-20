#include "Menu.h"
#include <iostream>
#include "Lion.h"
#include "Wolf.h"
#include "GreatWhiteShark.h"
#include "Zebra.h"
#include "Horse.h"
#include "Cow.h"
#include "Sheep.h"
#include "Buffalo.h"
#include "Sponge.h"
#include "Coral.h"

Menu::Menu() {}

void Menu::insertAnimals() {
    std::cout << "Welcome to the Zoo! Please add 5 animals to begin." << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "\nAdding animal #" << (i + 1) << ":" << std::endl;
        Animal* animal = getAnimalChoice();
        if (animal) {
            m_zoo.addAnimal(animal);
            std::cout << animal->getType() << " added to the zoo!" << std::endl;
        }
    }
}

void Menu::mainMenu() {
    int choice = 0;
    while (choice != 6) {
        std::cout << "\n--- Zoo Menu ---" << std::endl;
        std::cout << "1. Add another animal" << std::endl;
        std::cout << "2. Feed all animals" << std::endl;
        std::cout << "3. Show all animals" << std::endl;
        std::cout << "4. Activate all mobile animals" << std::endl;
        std::cout << "5. Start the Lion hunting show" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Animal* animal = getAnimalChoice();
                if(animal) {
                    m_zoo.addAnimal(animal);
                    std::cout << animal->getType() << " added to the zoo!" << std::endl;
                }
                break;
            }
            case 2: m_zoo.feedAll(); break;
            case 3: m_zoo.showAll(); break;
            case 4: m_zoo.activateAllMobile(); break;
            case 5: m_zoo.lionHuntingShow(); break;
            case 6:
                std::cout << "Exiting. All animals will be released (memory cleaned)." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

Animal* Menu::getAnimalChoice() {
    int choice = 0;
    std::cout << "Select animal type:" << std::endl;
    std::cout << "1. Lion  2. Wolf  3. Shark  4. Zebra  5. Horse" << std::endl;
    std::cout << "6. Cow   7. Sheep 8. Buffalo 9. Sponge 10. Coral" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return new Lion();
        case 2: return new Wolf();
        case 3: return new GreatWhiteShark();
        case 4: return new Zebra();
        case 5: return new Horse();
        case 6: return new Cow();
        case 7: return new Sheep();
        case 8: return new Buffalo();
        case 9: return new Sponge();
        case 10: return new Coral();
        default:
            std::cout << "Invalid animal choice." << std::endl;
            return nullptr;
    }
}