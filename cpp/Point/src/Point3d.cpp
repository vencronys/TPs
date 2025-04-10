#include <iostream>
#include "Point3d.h"

Point3d::Point3d() {
    z = 0;
    std::cout << "Point3d default constructor called" << std::endl;
}

Point3d::Point3d(const char *name_, const float &x_, const float &y_, const float &z_): Point(name_, x_, y_) {
    z = 0;
    std::cout << "Point3d default constructor called" << std::endl;
}

Point3d::Point3d(const Point3d & p): Point(p) {
    z = p.z;
    std::cout << "Point3d copy constructor called" << std::endl;
}

Point3d::~Point3d() {
    std::cout << "Point3d default destructor called" << std::endl;
}

Point3d & Point3d::operator=(const Point3d & p) {
    if (this != &p) {
        Point::operator=(p);
        z = p.z;
    }
    std::cout << "Point3d assignment operator called" << std::endl;
    return *this;
}