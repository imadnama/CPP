#ifndef TOOLS_H
#define TOOLS_H

#include "Resturant.h"
#include "Item.h"
#include "Order.h"

void printMenuItems(Item** menu, int size);

Order* minCalories(const Resturant& rest);

#endif
