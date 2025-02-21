#include "Point.h"
#include <iostream>

int Point::s_numberOfOccurences = 0;
void Point::PrintNumberOfOccurences() {
    std::cout << Point::s_numberOfOccurences << std::endl;
}

Point::Point(int m_x, int m_y) : m_x(m_x), m_y(m_y) {
    Point::s_numberOfOccurences++;
}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}

void Point::setX(int m_x) {
    this->m_x = m_x;
}

void Point::setY(int m_y) {
    this->m_y = m_y;
}

void Point::move(int dx, int dy) {
    m_x += dx;
    m_y += dy;
}



