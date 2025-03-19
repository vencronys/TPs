#include <cmath>
#include <iostream>

#include "Vector3d.h"

// Vector3d::Vector3d() {
//   x = 0;
//   y = 0;
//   z = 0;
// }

Vector3d::Vector3d(float x_, float y_, float z_) {
  x = x_;
  y = y_;
  z = z_;
}

void Vector3d::print() {
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
}

// bool Vector3d::compare(Vector3d vector3d) {
//   return (x == vector3d.get_x() && y == vector3d.get_y() &&
//           z == vector3d.get_z());
// }

bool Vector3d::compare(Vector3d *vector3d) const {
  return (x == vector3d->x && y == vector3d->y && z == vector3d->z);
}

bool Vector3d::compare(const Vector3d &vector3d) const {
  return (x == vector3d.x && y == vector3d.y && z == vector3d.z);
}

Vector3d Vector3d::oppose() const { return Vector3d(-x, -y, -z); }
Vector3d *Vector3d::opposep() const { return new Vector3d(-x, -y, -z); }
Vector3d &Vector3d::opposer() const {
  static Vector3d vector3d(-x, -y, -z);
  return vector3d;
}

Vector3d &Vector3d::norm_max(Vector3d &vector3d) {
  return ((std::sqrt(x * x + y * y + z * z) >
           std::sqrt(vector3d.x * vector3d.x + vector3d.y * vector3d.y +
                     vector3d.z * vector3d.z))
              ? *this
              : vector3d);
}

Vector3d &Vector3d::norm_max(Vector3d *vector3d) {
  return ((std::sqrt(x * x + y * y + z * z) >
           std::sqrt(vector3d->x * vector3d->x + vector3d->y * vector3d->y +
                     vector3d->z * vector3d->z))
              ? *this
              : *vector3d);
}

Vector3d *Vector3d::norm_maxp(Vector3d &vector3d) {
  return ((std::sqrt(x * x + y * y + z * z) >
           std::sqrt(vector3d.x * vector3d->x + vector3d->y * vector3d->y +
                     vector3d.z * vector3d->z))
              ? *this
              : vector3d);
}

Vector3d *Vector3d::norm_maxp(Vector3d *vector3d) {
  return ((std::sqrt(x * x + y * y + z * z) >
           std::sqrt(vector3d->x * vector3d->x + vector3d->y * vector3d->y +
                     vector3d->z * vector3d->z))
              ? *this
              : *vector3d);
}
