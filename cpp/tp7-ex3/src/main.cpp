#include "Stack.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Stack st1;
  st1.print();
  st1<3;
  st1<13;
  st1.print();
  --st1;
  st1.print();
  Stack st2;
  st2.print();
  st2<3;
  std::cout << ((st1 == st2) ? "Equal" : "Not Equal") << NEW_LINE;
  st2<13;
  std::cout << ((st1 != st2) ? "Equal" : "Not Equal") << NEW_LINE;
  std::cout << st2[1] << NEW_LINE;
  st2 = st2+5;
  st2.print();
  st1<1;
  st2 = st2 + st1;
  st2.print();
  std::cout << st2 << NEW_LINE;
  std::cin >> st2;
  std::cout << st2 << NEW_LINE;
  return 0;
}
