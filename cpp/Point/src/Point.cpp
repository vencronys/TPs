#include "Point.h"
#include <cstring>
#include <iostream>

int Point::Point::s_count = 0;

Point::Point() {
    m_name = new char[20];
    std::strcpy(m_name, "null");
    m_x = 0.0f;
    m_y = 0.0f;
    Point::s_count++;
}

Point::Point(const char *name, const float &x, const float &y) {
    m_name = new char[std::strlen(name) + 1];
    std::strcpy(m_name, name);
    m_x = x;
    m_y = y;
    Point::s_count++;
}

Point::~Point() {
    delete[] m_name;
    Point::s_count--;
}

void Point::Print() const {
    std::cout << m_name << "(" << m_x << ", " << m_y << ")" << std::endl;
}

void Point::PrintCount() {
    std::cout << "Count: " << Point::s_count << std::endl;
}
