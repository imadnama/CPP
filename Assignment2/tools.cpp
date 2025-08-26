#include "tools.h"
#include <iostream>

void printMenuItems(Item** menu, int size) {
    std::cout << "<<< Menu >>>" << std::endl;
    for (int i = 0; i < size; i++) {
        if (menu[i] != nullptr) {
            std::cout << (i + 1) << ". "
                      << menu[i]->getName() << "/ "
                      << menu[i]->getPrice() << "$/ "
                      << menu[i]->getCalories() << "cal" << std::endl;
        }
    }
}

Order* minCalories(const Resturant& rest) {
    int orderCount = rest.getOrdersSize();

    if (orderCount == 0) {
        return nullptr;
    }

    Order** orders = rest.getOrders();

    Order* minOrder = orders[0];
    int minCal = minOrder->getCalories();

    for (int i = 1; i < orderCount; i++) {
        if (orders[i] != nullptr) {
            int currentCalories = orders[i]->getCalories();
            if (currentCalories < minCal) {
                minCal = currentCalories;
                minOrder = orders[i];
            }
        }
    }

    return minOrder;
}