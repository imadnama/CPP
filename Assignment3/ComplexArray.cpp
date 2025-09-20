#include "ComplexArray.h"
#include <iostream>
#include <string>

// Constructors & Destructor

ComplexArray::ComplexArray() {
    this->arr = nullptr;
    this->size = 0;
}

ComplexArray::ComplexArray(int s) {
    this->size = s;
    this->arr = new Complex[this->size];
}

ComplexArray::ComplexArray(Complex* a, int s) {
    this->size = s;
    this->arr = new Complex[this->size];
    for (int i = 0; i < this->size; i++) {
        this->arr[i] = a[i];
    }
}

ComplexArray::ComplexArray(const ComplexArray& other) {
    this->size = other.size;
    this->arr = new Complex[this->size];
    for (int i = 0; i < this->size; i++) {
        this->arr[i] = other.arr[i];
    }
}

ComplexArray::~ComplexArray() {
    delete[] this->arr;
}

// Setters & Getters

int ComplexArray::getSize() const {
    return this->size;
}

// Methods

std::string ComplexArray::toString() const {
    if (this->size == 0) {
        return "/";
    }

    std::string result = "";
    for (int i = 0; i < this->size; i++) {
        result += this->arr[i].toString();
        if (i < this->size - 1) {
            result += " ";
        }
    }
    return result;
}

// Overloaded Operators

ComplexArray& ComplexArray::operator=(const ComplexArray& other) {
    if (this != &other) {
        delete[] this->arr;
        this->size = other.size;
        this->arr = new Complex[this->size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

Complex& ComplexArray::operator[](int index) {
    if (index < 0) {
        return this->arr[this->size + index];
    }
    return this->arr[index];
}

const Complex& ComplexArray::operator[](int index) const {
    if (index < 0) {
        return this->arr[this->size + index];
    }
    return this->arr[index];
}

ComplexArray& ComplexArray::operator+=(const ComplexArray& other) {
    int newSize = this->size + other.size;
    Complex* tempArr = new Complex[newSize];

    for (int i = 0; i < this->size; i++) {
        tempArr[i] = this->arr[i];
    }
    for (int i = 0; i < other.size; i++) {
        tempArr[this->size + i] = other.arr[i];
    }

    delete[] this->arr;
    this->arr = tempArr;
    this->size = newSize;

    return *this;
}

ComplexArray& ComplexArray::operator+=(const Complex& c) {
    int newSize = this->size + 1;
    Complex* tempArr = new Complex[newSize];

    for (int i = 0; i < this->size; i++) {
        tempArr[i] = this->arr[i];
    }
    tempArr[this->size] = c;

    delete[] this->arr;
    this->arr = tempArr;
    this->size = newSize;

    return *this;
}

Complex ComplexArray::operator!() const {
    Complex sum;
    for (int i = 0; i < this->size; i++) {
        sum += this->arr[i];
    }
    return sum;
}

std::ostream& operator<<(std::ostream& os, const ComplexArray& ca) {
    os << ca.toString();
    return os;
}

std::istream& operator>>(std::istream& is, ComplexArray& ca) {
    for (int i = 0; i < ca.size; i++) {
        std::cout << "Enter complex number [real:imag] ";
        is >> ca.arr[i];
    }
    return is;
}

bool operator==(const ComplexArray& first, const ComplexArray& second) {
    if (first.getSize() != second.getSize()) {
        return false;
    }
    for (int i = 0; i < first.getSize(); i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const ComplexArray& first, const ComplexArray& second) {
    return !(first == second);
}

ComplexArray operator+(const ComplexArray& first, const ComplexArray& second) {
    ComplexArray result = first;
    result += second;
    return result;
}