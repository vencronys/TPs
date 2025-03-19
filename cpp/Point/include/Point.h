#pragma once
class Point {
public:
    Point();
    Point(const char *, const float &, const float &);
    Point(const Point &);
    ~Point();
    void print() const;
    static void printCount();
    bool compare(Point) const;

private:
    char *name;
    float x;
    float y;
    static int count;
};
