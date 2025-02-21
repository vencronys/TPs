#include "Point.h"
#include <iostream>
#include <string>

int Point::s_numberOfOccurences = 0;
void Point::PrintNumberOfOccurences() {
    std::cout << Point::s_numberOfOccurences << std::endl;
}

Point::Point() {
    Point::s_numberOfOccurences++;
}

void Point::SetPoint(std::string name, int x, int y) {
    m_name = name;
    m_x = x;
    m_y = y;
}
