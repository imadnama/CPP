#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    std::string toString() const {
        return "Point(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }

    bool operator>=(const Point& obj) const {
        return (x + y) >= (obj.x + obj.y);
    }

    bool operator==(const Point& obj) const {
        return x == obj.x && y == obj.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << p.toString();
        return os;
    }
};

#endif