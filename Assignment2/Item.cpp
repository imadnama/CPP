#include "Item.h"
#include <iostream>
#include <string>

int Item::count = 1;

// Constructors
Item::Item(const std::string& name, double price, int calories)
    : name(name), price(price), calories(calories) // Step 1: Initialize members
{this->id = count++;}

Item::Item(const std::string& name)
    : name(name), price(0.0), calories(0)
{this->id = count++;}

Item::Item(const Item& other)
    : name(other.name), price(other.price), calories(other.calories)
{this->id = count++;}

// Destructor
Item::~Item() {}

// Setters
void Item::setName(const std::string& name) {
  this->name = name;}
void Item::setPrice(double price) {
  this->price = price;}
void Item::setCalories(int calories){
  this->calories = calories;}

// Getters
std::string Item::getName() const {
  return this->name;}

double Item::getPrice() const{
  return this->price;}

int Item::getCalories() const{
  return this->calories;}

int Item::getId() const{
  return this->id;}

// Methods
std::string Item::toFullString() const {
  return "Item(" + std::to_string(this->id) + ", " + this->name + ", " +
         std::to_string(this->price) + ", " + std::to_string(this->calories) + ")";}

std::string Item::toString() const {
  return "Item(" + this->name + ", " +
         std::to_string(this->price) + ", " + std::to_string(this->calories) + ")";}

Item Item::compare(const Item& other) const {
  if (this->calories > other.calories) { return other; }
  else return *this; }

int Item::getNumOfItems() {
    return count - 1;}