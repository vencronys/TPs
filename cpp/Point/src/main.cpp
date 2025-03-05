#include "Point.h"

int main() {

    const Point p1;
    p1.Print();

    Point p2("p2", 1.0f, 2.0f);
    p2.Print();

    return 0;
}
