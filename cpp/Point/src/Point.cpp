#include "Point.h"
#include <iostream>

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}


