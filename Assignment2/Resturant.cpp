#include "Resturant.h"
#include <iostream>

Resturant::Resturant(const std::string& name, Item** initialMenu, int initialMenuSize)
    : name(name), menuSize(initialMenuSize), orders(nullptr), ordersSize(0) {

    this->menu = new Item*[this->menuSize];

    for (int i = 0; i < this->menuSize; i++) {
        this->menu[i] = new Item(*(initialMenu[i]));
    }
}

Resturant::Resturant(const Resturant& other)
    : name(other.name), menuSize(other.menuSize), orders(nullptr), ordersSize(0) {

    this->menu = new Item*[this->menuSize];
    for (int i = 0; i < this->menuSize; i++) {
        this->menu[i] = new Item(*(other.menu[i]));
    }
}

Resturant::~Resturant() {
    for (int i = 0; i < this->menuSize; i++) {
        delete this->menu[i];
    }
    delete[] this->menu;

    for (int i = 0; i < this->ordersSize; i++) {
        delete this->orders[i];
    }
    if (this->orders != nullptr) {
        delete[] this->orders;
    }
}

void Resturant::setName(const std::string& name) {
    this->name = name;
}

Item** Resturant::getMenu() const {
    return this->menu;
}

int Resturant::getMenuSize() const {
    return this->menuSize;
}

void Resturant::addMenuItem(const Item& newItem) {
    int newSize = this->menuSize + 1;
    Item** newMenu = new Item*[newSize];

    for (int i = 0; i < this->menuSize; i++) {
        newMenu[i] = this->menu[i];
    }

    newMenu[this->menuSize] = new Item(newItem);

    delete[] this->menu;

    this->menu = newMenu;
    this->menuSize = newSize;
}

void Resturant::removeMenuItem(int index) {
    if (index < 1 || index > this->menuSize) {
        return;
    }

    int newSize = this->menuSize - 1;
    Item** newMenu = new Item*[newSize];

    Item* itemToDelete = this->menu[index - 1];

    for (int i = 0, j = 0; i < this->menuSize; i++) {
        if (i == index - 1) {
            continue;
        }
        newMenu[j] = this->menu[i];
        j++;
    }

    delete[] this->menu;

    delete itemToDelete;

    this->menu = newMenu;
    this->menuSize = newSize;
}

void Resturant::addOrders(Order* newOrders, int count) {
    if (count <= 0) {
        return;
    }

    int newSize = this->ordersSize + count;
    Order** newOrdersList = new Order*[newSize];

    for (int i = 0; i < this->ordersSize; i++) {
        newOrdersList[i] = this->orders[i];
    }

    for (int i = 0; i < count; i++) {
        newOrdersList[this->ordersSize + i] = new Order(newOrders[i]);
    }

    if (this->orders != nullptr) {
        delete[] this->orders;
    }

    this->orders = newOrdersList;
    this->ordersSize = newSize;
}

void Resturant::printMenu() const {
    std::cout << "<<< Menu >>>" << std::endl;
    for (int i = 0; i < this->menuSize; i++) {
        std::cout << (i + 1) << ". "
                  << this->menu[i]->getName() << "/ "
                  << this->menu[i]->getPrice() << "$/ "
                  << this->menu[i]->getCalories() << "cal" << std::endl;
    }
}

void Resturant::printOrders() const {
    std::cout << "orders (";
    for (int i = 0; i < this->ordersSize; i++) {
        if (this->orders[i] != nullptr) {
            std::cout << this->orders[i]->toString();
            if (i < this->ordersSize - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << ")" << std::endl;
}

std::string Resturant::toString() const {
    std::string result = "Restaurant['" + this->name + "', menu(";
    for (int i = 0; i < this->menuSize; i++) {
        result += this->menu[i]->toString();
        if (i < this->menuSize - 1) {
            result += ", ";
        }
    }
    result += "), orders(";
    for (int i = 0; i < this->ordersSize; i++) {
        result += this->orders[i]->toString();
        if (i < this->ordersSize - 1) {
            result += ", ";
        }
    }
    result += ")]";
    return result;
}

Order** Resturant::getOrders() const {
    return this->orders;
}

int Resturant::getOrdersSize() const {
    return this->ordersSize;
}