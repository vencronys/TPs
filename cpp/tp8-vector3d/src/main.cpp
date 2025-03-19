#include <iostream>

#include "Vector3d.h"

int main(int argc, char *argv[]) {
  Vector3d v1(1, 2, 3);
  Vector3d v2(1, 2, 3);
  // std::cout << v1.compare(v2) << std::endl;
  std::cout << v1.compare(&v2) << std::endl;
  std::cout << v1.compare(v2) << std::endl;
  Vector3d v3(2, 2, 3);
  Vector3d v4 = v1.norm_max(v3);
  v4.print();
  return 0;
}
