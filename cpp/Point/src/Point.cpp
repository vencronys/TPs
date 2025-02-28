#include "Point.h"
#include <iostream>
#include <string>

int Point::s_numberOfOccurences = 0;

Point::Point() {
    Point::s_numberOfOccurences++;
    m_name = "undefined";
    m_x = 0;
    m_y = 0;
    std::cout << "Def Cons" << std::endl;
}

void Point::PrintNumberOfOccurences() {
    std::cout << Point::s_numberOfOccurences << std::endl;
}

Point::Point(const std::string &name, const int &x, const int &y) {
    m_name = name;
    m_x = x;
    m_y = y;
}
