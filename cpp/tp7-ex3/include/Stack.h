#pragma once
class Stack {
public:
  Stack(int = 10);
  ~Stack();
  bool full() const;
  bool empty() const;
  void add(int);
  void pop();
  void print_capacity() const;
  void print_size() const;
  void print() const;

private:
  int *address, size, capacity;
};
