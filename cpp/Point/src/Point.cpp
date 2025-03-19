#include "Point.h"
#include <cstring>
#include <iostream>

int Point::Point::count = 0;

Point::Point() {
    name = new char[5];
    std::strncpy(name, "null", 4);
    name[4] = '\0';
    x = 0.0f;
    y = 0.0f;
    Point::count++;
}

Point::Point(const char *name_, const float &x_, const float &y_) {
    name = new char[std::strlen(name_) + 1];
    std::strncpy(name, name_, std::strlen(name_) + 1);
    name[std::strlen(name_)] = '\0';
    x = x_;
    y = y_;
    Point::count++;
}

Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
    name = new char[std::strlen(p.name) + 1];
    std::strncpy(name, p.name, std::strlen(p.name) + 1);
    name[std::strlen(p.name)] = '\0';
    std::cout << "Constructeur de recopie" << std::endl;
}

Point::~Point() {
    delete[] name;
    Point::count--;
}

void Point::print() const {
    std::cout << name << "(" << x << ", " << y << ")" << std::endl;
}

void Point::printCount() {
    std::cout << "Count: " << Point::count << std::endl;
}

bool Point::compare(Point p) const {
    return (x == p.x && y == p.y && !std::strcmp(name, p.name));
}

Point &Point::operator=(const Point &p) {
    x = p.x;
    y = p.y;
    delete[] name;
    name = new char[std::strlen(p.name) + 1];
    std::strncpy(name, p.name, std::strlen(p.name) + 1);
    name[std::strlen(p.name)] = '\0';
    return *this;
}
