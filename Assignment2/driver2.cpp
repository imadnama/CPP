#include <iostream>
#include "Time.h"
#include "Item.h"
#include "Order.h"
#include "Resturant.h"
#include "tools.h"

using namespace std;

int main() {
    cout << "<<< Time >>>" << endl;
    Time time1;
    cout << time1.toString() << endl;

    Time time2(10, 4, 35);
    cout << time1.compare(time2) << " " << time2.compare(time1) << " " << time1.compare(time1) << endl;

    cout << "\n<<< Item >>>" << endl;
    Item item1("burger");
    cout << item1.toFullString() << endl;

    Item item2("cola", 10.49, 300);
    cout << item2.toFullString() << endl;

    Item item3(item1);
    item3.setName("nutburger");
    item3.setPrice(12.3);
    item3.setCalories(250);
    cout << item3.toFullString() << endl;

    cout << "compare: " << item2.compare(item3).toString() << endl;

    // This is the initial menu. It's an array of Item objects, not pointers.
    Item initialMenu[] = {
        Item("McDouble", 10, 400), Item("Big_Mac", 12, 550),
        Item("McChicken", 10, 400), Item("Fries", 5, 320),
        Item("Cappuccino", 3, 160), Item("Coca-Cola", 5, 210)
    };
    int initialMenuSize = 6;

    // To pass it to the Resturant, we need an array of pointers.
    Item* menuForResturant[initialMenuSize];
    for(int i = 0; i < initialMenuSize; ++i) {
        menuForResturant[i] = &initialMenu[i];
    }

    cout << "items amount: " << Item::getNumOfItems() << endl;
    printMenuItems(menuForResturant, initialMenuSize);

    cout << "\n<<< Order >>>" << endl;
    Order order1("David");
    cout << order1.toString() << endl;

    order1.addItems(menuForResturant, initialMenuSize, 1);
    cout << order1.toString() << endl;

    int itemsToAdd1[] = {3, 5};
    order1.addItems(menuForResturant, initialMenuSize, itemsToAdd1, 2);
    cout << order1.toString() << endl;

    order1.removeItem(2);
    cout << order1.toString() << endl;

    int itemsToAdd2[] = {2, 4, 5, 6};
    Order order2("Tali", Time(10, 23, 37), menuForResturant, initialMenuSize, itemsToAdd2, 4);
    cout << order2.toString() << endl;

    Order order3(order2);
    order3.setName("Jim");
    cout << order3.toString() << endl;

    cout << "\n<<< Resturant >>>" << endl;
    Resturant rest1("BurgerPoint", menuForResturant, initialMenuSize);
    cout << rest1.toString() << endl;

    rest1.printMenu();
    cout << "\n------------------\n";

    rest1.addMenuItem(Item("Green_Salad", 12, 434));
    rest1.removeMenuItem(1);
    rest1.printMenu();
    cout << "\n------------------\n";

    int davidOrderItems[] = {2, 4, 5, 6};
    Order* davidOrder = new Order("David", Time(10, 12, 17), rest1.getMenu(), rest1.getMenuSize(), davidOrderItems, 4);
    rest1.addOrders(davidOrder, 1);

    int taliOrderItems[] = {1, 3, 5};
    int jimOrderItems[] = {1, 2, 3, 5};
    Order groupOrders[] = {
        Order("Tali", Time(), rest1.getMenu(), rest1.getMenuSize(), taliOrderItems, 3),
        Order("Jim", Time(10, 15, 16), rest1.getMenu(), rest1.getMenuSize(), jimOrderItems, 4)
    };
    rest1.addOrders(groupOrders, 2);

    rest1.printOrders();
    cout << "\n------------------\n";
    cout << rest1.toString() << endl;
    cout << "------------------\n";

    Order* minCalOrder = minCalories(rest1);
    if (minCalOrder != nullptr) {
        cout << minCalOrder->toString() << endl;
    }

    cout << "------------------\n";
    Resturant rest2 = Resturant(rest1);
    rest2.setName("Burger Sheva");
    cout << rest2.toString() << endl;

    return 0;
}