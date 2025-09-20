#ifndef COMPLEXARRAY_H
#define COMPLEXARRAY_H

#include "Complex.h"
#include <iostream>
#include <string>

class ComplexArray{

  Complex* arr;
  int size;

  public:
    // Constructors
    ComplexArray();
    ComplexArray(int s);
    ComplexArray(Complex* a, int s);
    ComplexArray(const ComplexArray& other);

    // Destructor
    ~ComplexArray();

    // Setters & Getters
    int getSize() const;

    // Methods
    std::string toString() const;

    // Overloaded Operators
    ComplexArray& operator=(const ComplexArray& other);
    Complex& operator[](int index);
    const Complex& operator[](int index) const;

    ComplexArray& operator+=(const ComplexArray& other);
    ComplexArray& operator+=(const Complex& c);

    Complex operator!() const;

    friend std::ostream& operator<<(std::ostream& os, const ComplexArray& ca);
    friend std::istream& operator>>(std::istream& is, ComplexArray& ca);

};

bool operator==(const ComplexArray& first, const ComplexArray& second);
bool operator!=(const ComplexArray& first, const ComplexArray& second);
ComplexArray operator+(const ComplexArray& first, const ComplexArray& second);

#endif
