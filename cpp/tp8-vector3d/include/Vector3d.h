#pragma once

class Vector3d {
public:
  // Vector3d();
  // Vector3d(float x, float y, float z);
  // inline Vector3d(float x = 0, float y = 0, float z = 0);
  Vector3d(float x = 0, float y = 0, float z = 0);
  void print();
  // bool compare(Vector3d vector3d);
  bool compare(Vector3d *vector3d) const;
  bool compare(const Vector3d &vector3d) const;
  Vector3d oppose() const;
  Vector3d *opposep() const;
  Vector3d &opposer() const;
  Vector3d &norm_max(Vector3d &vector3d);
  Vector3d &norm_max(Vector3d *vector3d);
  Vector3d *norm_maxp(Vector3d &vector3d);
  Vector3d *norm_maxp(Vector3d *vector3d);

private:
  float x, y, z;
};
// Vector3d::Vector3d(float x_, float y_, float z_) {
//   x = x_;
//   y = y_;
//   z = z_;
// }
