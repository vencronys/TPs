#include "Stack.h"

int main(int argc, char *argv[]) {
  Stack stack(5);
  stack.pop();
  stack.add(13);
  stack.add(7);
  stack.print();
  stack.print_size();
  stack.print_capacity();
  stack.pop();
  stack.print();
  return 0;
}
