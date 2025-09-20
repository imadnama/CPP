#ifndef UTILITY_H
#define UTILITY_H

#include "List.h"
#include <string>

template <class T>
List<T> doTwice(const List<T>& list) {
    List<T> new_list;
    for (int i = 0; i < list.length(); ++i) {
        new_list.append(list[i]).append(list[i]);
    }
    return new_list;
}

template <class T>
T maxT(T* arr, int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array cannot be empty");
    }
    T max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] >= max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

#endif