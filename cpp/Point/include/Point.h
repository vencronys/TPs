#pragma once
#include <iostream>
class Point {
public:
    Point();
    Point(const char *, const float &, const float &);
    Point(const Point &);
    ~Point();
    void print() const;
    static void printCount();
    bool compare(Point) const;
    Point &operator=(const Point &);
    Point &operator+(const Point &);
    Point &operator*(const float &);
    friend Point &operator*(const float &, const Point &);
    friend std::istream &operator>>(std::istream &, Point &);
    friend std::ostream &operator<<(std::ostream &, Point &);

private:
    char *name;
    float x;
    float y;
    static int count;
};
