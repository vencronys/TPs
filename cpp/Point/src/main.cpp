#include "Point.h"

int main() {
    Point p1;
    p1.SetPoint("A", 1, 3);
    p1.Print();

    Point p2;
    p2.SetPoint("B", 0, 7);
    p2.Print();
    Point::PrintNumberOfOccurences();
    return 0;
}
