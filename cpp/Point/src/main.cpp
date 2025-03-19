#include "iostream"

#include "Point.h"

int main() {

    Point p1, p3 = p1;
    p1.print();

    Point p2("p2", 1.0f, 2.0f);
    p2.print();

    std::cout << (p1.compare(p3) ? "egaux" : "pas egaux") << std::endl;

    p3 = p1;

    return 0;
}
