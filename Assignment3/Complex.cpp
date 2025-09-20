#include "Complex.h"
#include <iostream>
#include <string>
#include <cmath>

// Constructors
Complex::Complex()
    : real(0), imaginary(0) {}

Complex::Complex(double r)
    : real(r), imaginary(0) {}

Complex::Complex(double r, double i)
    : real(r), imaginary(i) {}

// Destructor
Complex::~Complex() {}

// Setters & Getters
void Complex::setReal(double r) {
    this->real = r;
}

void Complex::setImaginary(double i) {
    this->imaginary = i;
}

double Complex::getReal() const {
    return this->real;
}

double Complex::getImaginary() const {
    return this->imaginary;
}

// Methods

std::string Complex::toString() const {
    if (this->imaginary == 0) {
        return std::to_string(this->real);
    }
    else if (this->imaginary > 0) {
        return "(" + std::to_string(this->real) + " + " + std::to_string(this->imaginary) + "i)";
    }
    else {
        return "(" + std::to_string(this->real) + " - " + std::to_string(this->imaginary*-1) + "i)";
    }
}

// Overloaded Operators
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        this->real = other.real;
        this->imaginary = other.imaginary;
    }
    return *this;
}

Complex& Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imaginary += other.imaginary;
    return *this;
}

Complex& Complex::operator+=(double r) {
    this->real += r;
    return *this;
}

Complex& Complex::operator++() {
    this->real ++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    this->real++;
    return temp;
}

double Complex::operator!() const {
    return sqrt((this->real * this->real) + (this->imaginary * this->imaginary));
}

Complex::operator double() const {
    return this->real + this->imaginary;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.toString();
    return os;
}
std::istream& operator>>(std::istream& is, Complex& c) {
    double r = 0.0, i = 0.0;
    char colon = 0;
    is >> r >> colon >> i;
    c.real = r;
    c.imaginary = i;
    return is;
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator+(double r) const {
    return Complex(real + r, imaginary);
}

Complex operator+(double r, const Complex& c) {
    return c + r;
}