#pragma once
#include "Point.h"
class Point3d: public Point {
public:
    Point3d();
    Point3d(const char *, const float &, const float &, const float &);
    Point3d(const Point3d &);
    ~Point3d();
    Point3d & operator=(const Point3d &);
private:
    float z;
};