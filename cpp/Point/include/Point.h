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
    Point &operator=(const Point &);
    Point &operator+(const Point &);
    Point &operator*(const float &);
    friend Point &operator*(const float &, const Point &);

private:
    char *name;
    float x;
    float y;
    static int count;
};
