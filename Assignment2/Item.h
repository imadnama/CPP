#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {

  static int count; // For Covering Unique IDs Per Object
  int id;
  std::string name;
  double price;
  int calories;

  public:

    // Constructors
    Item(const std::string& name, double price, int calories);
    Item(const std::string& name);
    Item(const Item& other); // The Copy Constructor

    // Destructor
    ~Item();

    // Setters and getters
    void setName(const std::string& name);
    void setPrice(double price);
    void setCalories(int calories);
    std::string getName() const;
    double getPrice() const;
    int getCalories() const;
    int getId() const;

    // Methods
    std::string toFullString() const;
    std::string toString() const;
    Item compare(const Item& other) const;

    // Static Method For Items Total Count
    static int getNumOfItems();
};

#endif