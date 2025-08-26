#include "Order.h"
#include "Item.h"
#include <iostream>

// Constructors
Order::Order(const std::string& customerName)
    : customerName(customerName), orderTime(Time()), items(nullptr), size(0) {}

Order::Order(const std::string& customerName, const Time& orderTime)
    : customerName(customerName), orderTime(orderTime), items(nullptr), size(0) {}

Order::Order(const std::string& customerName, const Time& orderTime, Item** menu, int menuSize, int* itemIndices, int numItemsToAdd)
    : customerName(customerName), orderTime(orderTime), size(numItemsToAdd)
{
    if (this->size <= 0) {
    this->items = nullptr;
    this->size = 0;
    return;}

    this->items = new Item*[this->size];

    for (int i = 0; i < this->size; i++) {
    int menuIndex = itemIndices[i];
    if (menuIndex > 0 && menuIndex <= menuSize) {
    this->items[i] = menu[menuIndex - 1];}
    else {this->items[i] = nullptr;}
    }
}

Order::Order(const std::string& customerName, Item** menu, int menuSize, int itemIndex)
    : customerName(customerName), size(1), orderTime(Time())
{
    this->items = new Item*[1];
    if (itemIndex > 0 && itemIndex <= menuSize){
      this->items[0] = menu[itemIndex-1];
    }
    else { this->items[0] = nullptr;
    }
}

Order::Order(const Order& other)
    : customerName(other.customerName), size(other.size), orderTime(Time())
{
    if (this->size == 0) {
        this->items = nullptr;
        return;
    }

    this->items = new Item*[this->size];

    for (int i = 0; i < this->size; i++) {
        this->items[i] = other.items[i];
    }
}

// Destructor
Order::~Order() {
    if (this->items != nullptr) {
        delete[] this->items;
    }
}

// Setter
void Order::setName(const std::string& customerName){
  this->customerName = customerName;
}

// Methods
void Order::addItems(Item** menu, int menuSize, int* itemIndices, int numItemsToAdd)
{
    if (numItemsToAdd <= 0) {
        return;
    }

    int newSize = this->size + numItemsToAdd;
    Item** newItems = new Item*[newSize];

    for (int i = 0; i < this->size; i++) {
        newItems[i] = this->items[i];
    }
    for (int i = 0; i < numItemsToAdd; i++) {
        int menuIndex = itemIndices[i];

        int destinationIndex = this->size + i;

        if (menuIndex > 0 && menuIndex <= menuSize) {
            newItems[destinationIndex] = menu[menuIndex - 1];
        } else {
            newItems[destinationIndex] = nullptr;
        }
    }

    if (this->items != nullptr) {
        delete[] this->items;
    }

    this->items = newItems;
    this->size = newSize;
}

void Order::addItems(Item** menu, int menuSize, int itemIndex) {
    int newSize = this->size + 1;
    Item** newItems = new Item*[newSize];

    for (int i = 0; i < this->size; i++) {
        newItems[i] = this->items[i];
    }

    if (itemIndex > 0 && itemIndex <= menuSize) {
        newItems[this->size] = menu[itemIndex - 1];
    } else {
        newItems[this->size] = nullptr; // Add null if index is bad
    }

    if (this->items != nullptr) {
        delete[] this->items;
    }

    this->items = newItems;
    this->size = newSize;
}

void Order::removeItem(int index) {
    if (index < 1 || index > this->size || this->size == 0) {
        return;
    }

    int newSize = this->size - 1;

    if (newSize == 0) {
        delete[] this->items;
        this->items = nullptr;
        this->size = 0;
        return;
    }

    Item** newItems = new Item*[newSize];

    for (int i = 0, j = 0; i < this->size; i++) {
        if (i == index - 1) {
            continue;
        }
        newItems[j] = this->items[i];
        j++;
    }

    delete[] this->items;

    this->items = newItems;
    this->size = newSize;
}

double Order::getTotal() const
{
  double total = 0;
  for (int i = 0; i < this->size; i++){
    if (this->items[i] != nullptr){
    total += items[i]->getPrice();
    }
  }
  return total;
}

int Order::getCalories() const
{
  int totalCalories = 0;
  for (int i = 0; i < this->size; i++){
    if (this->items[i] != nullptr){
      totalCalories += items[i]->getCalories();
    }
  }
  return totalCalories;
}

std::string Order::toString() const
{
    std::string result = "Order['" + this->customerName + "', " + this->orderTime.toString() + ", (";

    for (int i = 0; i < this->size; i++) {
        if (this->items[i] != nullptr) {
            result += this->items[i]->toString();
        }

        if (i < this->size - 1) {
            result += ", ";
        }
    }

    result += ")";

    result += "," + std::to_string(this->getTotal()) + "$,";
    result += std::to_string(this->getCalories()) + "cal]";

    return result;
}