#include "Point.h"

int main() {
    Point p1(3, 4);
    p1.print();
    p1.move(1, 1);
    p1.print();
    p1.setX(7);
    p1.print();
    p1.setY(2);
    p1.print();
    return 0;
}
