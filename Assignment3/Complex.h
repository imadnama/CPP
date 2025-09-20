#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <iostream>

class Complex{

  double real;
  double imaginary;

public:

  // Constructors
  Complex();
  Complex(double r);
  Complex(double r, double i);

  // Destructor
  ~Complex();

  // Setters & Getters
  void setReal(double r);
  void setImaginary(double i);
  double getReal() const;
  double getImaginary() const;

  // Methods
  std::string toString() const;

  // Overloaded Operators
  Complex& operator=(const Complex& other);
  Complex& operator+=(const Complex& other);
  Complex& operator+=(double r);

  Complex& operator++();
  Complex operator++(int);

  double operator!() const;
  operator double() const;

  friend std::ostream& operator<<(std::ostream& os, const Complex& c);
  friend std::istream& operator>>(std::istream& is, Complex& c);

  bool operator==(const Complex& other) const;
  bool operator!=(const Complex& other) const;

  Complex operator+(const Complex& other) const;
  Complex operator+(double r) const;

  friend Complex operator+(double r, const Complex& c);
};

#endif