#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <stdexcept>

template <class T>
class List {
    T* m_data;
    int m_size;

    int get_real_index(int index) const {
        if (index >= 0 && index < m_size) return index;
        if (index < 0 && (m_size + index) >= 0) return m_size + index;
        throw std::out_of_range("Index out of range");
    }

public:
    List() : m_data(nullptr), m_size(0) {}
    ~List() { delete[] m_data; }

    List(const List<T>& other) : m_data(nullptr), m_size(0) {
        if (other.m_size > 0) {
            m_data = new T[other.m_size];
            m_size = other.m_size;
            for (int i = 0; i < m_size; ++i) m_data[i] = other.m_data[i];
        }
    }

    List<T>& operator=(const List<T>& other) {
        // Self-assignment check
        if (this == &other) return *this;

        delete[] m_data;
        m_data = nullptr;
        m_size = 0;

        if (other.m_size > 0) {
            m_data = new T[other.m_size];
            m_size = other.m_size;
            for (int i = 0; i < m_size; ++i) m_data[i] = other.m_data[i];
        }
        return *this;
    }

    void clear() {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
    }

    int length() const { return m_size; }

    int count(const T& element) const {
        int counter = 0;
        for (int i = 0; i < m_size; ++i) {
            if (m_data[i] == element) counter++;
        }
        return counter;
    }

    int index(const T& element) const {
        for (int i = 0; i < m_size; i++) {
            if (m_data[i] == element) return i;
        }
        throw std::invalid_argument("Element not found in list");
    }

    List<T>& append(const T& element) {
        T* new_data = new T[m_size + 1];
        for (int i = 0; i < m_size; ++i) new_data[i] = m_data[i];
        new_data[m_size] = element;
        delete[] m_data;
        m_data = new_data;
        m_size++;
        return *this;
    }

    List<T>& extend(const List<T>& other) {
        if (other.m_size == 0) return *this;
        T* new_data = new T[m_size + other.m_size];
        for (int i = 0; i < m_size; ++i) new_data[i] = m_data[i];
        for (int i = 0; i < other.m_size; ++i) new_data[m_size + i] = other.m_data[i];
        delete[] m_data;
        m_data = new_data;
        m_size += other.m_size;
        return *this;
    }

    List<T>& remove(int index) {
        int real_idx = get_real_index(index);
        T* new_data = new T[m_size - 1];
        int new_i = 0;
        for (int i = 0; i < m_size; ++i) {
            if (i != real_idx) new_data[new_i++] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_size--;
        return *this;
    }

    List<T> operator+(const List<T>& other) const {
        List<T> result(*this);
        result.extend(other);
        return result;
    }

    List<T>& operator+=(const List<T>& other) {
        return this->extend(other);
    }

    T& operator[](int index) { return m_data[get_real_index(index)]; }
    const T& operator[](int index) const { return m_data[get_real_index(index)]; }

    List<T> operator[](const std::string& slice_str) const {
        size_t colon_pos = slice_str.find(':');
        if (colon_pos == std::string::npos) throw std::invalid_argument("Invalid slice format");

        std::string start_s = slice_str.substr(0, colon_pos);
        std::string end_s = slice_str.substr(colon_pos + 1);

        int start_idx = start_s.empty() ? 0 : std::stoi(start_s);
        int end_idx = end_s.empty() ? m_size : std::stoi(end_s);

        if (start_idx < 0) start_idx = m_size + start_idx;
        if (start_idx < 0) start_idx = 0;
        if (start_idx > m_size) start_idx = m_size;

        if (end_idx < 0) end_idx = m_size + end_idx;
        if (end_idx < 0) end_idx = 0;
        if (end_idx > m_size) end_idx = m_size;

        List<T> result;
        if (start_idx >= end_idx) return result;

        for (int i = start_idx; i < end_idx; ++i) result.append(m_data[i]);
        return result;
    }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    os << "List[";
    for (int i = 0; i < list.m_size; ++i) {
        os << list.m_data[i];
        if (i < list.m_size - 1) os << ",";
    }
    os << "]";
    return os;
}

#endif