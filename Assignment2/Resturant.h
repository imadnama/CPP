#ifndef RESTURANT_H
#define RESTURANT_H

#include <string>
#include "Item.h"
#include "Order.h"

class Resturant {
    std::string name;
    Item** menu;
    Order** orders;
    int menuSize;
    int ordersSize;

public:
    Resturant(const std::string& name, Item** initialMenu, int initialMenuSize);
    Resturant(const Resturant& other);
    ~Resturant();

    void setName(const std::string& name);
    Item** getMenu() const;
    int getMenuSize() const;

    void addMenuItem(const Item& newItem);
    void removeMenuItem(int index);
    void addOrders(Order* newOrders, int count);
    void printMenu() const;
    void printOrders() const;
    std::string toString() const;

    Order** getOrders() const;
    int getOrdersSize() const;
};

#endif