#include "Point.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <istream>

#define NEW_LINE '\n';

int Point::count = 0;

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
    std::cout << "Constructeur de recopie" << NEW_LINE;
}

Point::~Point() {
    delete[] name;
    Point::count--;
}

void Point::print() const {
    std::cout << name << "(" << x << ", " << y << ")" << NEW_LINE;
}

void Point::printCount() {
    std::cout << "Count: " << Point::count << NEW_LINE;
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

Point &Point::operator+(const Point &p) {
    size_t imp_length = std::strlen(name), p_length = std::strlen(p.name);
    static Point rp(*this);
    rp.x += p.x;
    rp.y += p.y;
    delete[] rp.name;
    rp.name = new char[imp_length + p_length + 1];
    std::strncpy(rp.name, name, imp_length);
    std::strncpy(rp.name + imp_length, p.name, p_length);
    name[imp_length + p_length + 1] = '\0';
    return rp;
}

Point &Point::operator*(const float & number) {
    static Point rp(*this);
    rp.x *= number;
    rp.y *= number;
    return rp;
}

Point &operator*(const float & number, const Point &p) {
    static Point rp(p);
    rp.x *= number;
    rp.y *= number;
    return rp;
}
std::istream &operator>>(std::istream & istr, Point &p) {
    std::cout << "Insert name: ";
    istr >> p.name;
    std::cout << "Insert x: ";
    istr >> p.x;
    std::cout << "Insert y: ";
    istr >> p.y;
    return istr;
}
std::ostream &operator<<(std::ostream & ostr, Point &p) {
    ostr << p.name << "(" << p.x << ", " << p.y << ")" << NEW_LINE;
return ostr;
}
