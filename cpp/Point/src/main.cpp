#include <iostream>
#include "Point.h"

#define NEW_LINE '\n';

int main() {
    Point p1, p3 = p1;
    p1.print();
    Point p2("p2", 1.0f, 2.0f);
    p2.print();
    std::cout << (p1.compare(p3) ? "egaux" : "pas egaux") << NEW_LINE;
    p3 = p1;
    p1 = p2 + p3;
    p1.print();
    p1 = p1 * 5;
    p1.print();
    p1 = 2 * p1;
    p1.print();
    std::cin >> p1;
    std::cout << p1;
    return 0;
}
