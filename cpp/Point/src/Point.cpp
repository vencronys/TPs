#include "Point.h"
#include <cstring>
#include <iostream>

int Point::s_numberOfOccurences = 0;

Point::Point() {
    Point::s_numberOfOccurences++;
    m_name = new char[20];
    std::strcpy(m_name, "null");
    m_x = 0;
    m_y = 0;
}

void Point::PrintNumberOfOccurences() {
    std::cout << Point::s_numberOfOccurences << std::endl;
}

Point::Point(const char *name, const float &x, const float &y) {
    m_name = new char[std::strlen(name) + 1];
    m_name = std::strcpy(m_name, name);
    m_x = x;
    m_y = y;
}

Point::~Point() {
    delete m_name;
}
