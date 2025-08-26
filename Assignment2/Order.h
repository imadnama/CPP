#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "Time.h"
#include "Item.h"

class Order {
    std::string customerName;
    Time orderTime;
    Item** items;
    int size;

public:
    // Constructors
    Order(const std::string& customerName);
    Order(const std::string& customerName, const Time& orderTime);
    Order(const std::string& customerName, const Time& orderTime, Item** menu, int menuSize, int* itemIndices, int numItemsToAdd);
    Order(const std::string& customerName, Item** menu, int menuSize, int itemIndex);
    Order(const Order& other);

    // Destructor
    ~Order();

    // Setters
    void setName(const std::string& customerName);

    // Methods
    void addItems(Item** menu, int menuSize, int itemIndex);
    void addItems(Item** menu, int menuSize, int* itemIndices, int numItemsToAdd);
    void removeItem(int index);
    double getTotal() const;
    int getCalories() const;
    std::string toString() const;
};

#endif