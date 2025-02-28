#include "Point.h"

int main() {
    Point p1;
    p1.Print();

    Point p2("B", 0, 7);
    p2.Print();

    Point *p3;
    p3 = new Point;
    p3->Print();

    delete p3;

    return 0;
}
