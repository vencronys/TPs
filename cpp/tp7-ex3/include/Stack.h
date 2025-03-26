#pragma once
#include <iostream>

#define NEW_LINE '\n'

class Stack {
public:
  Stack(int = 20);
  Stack(const Stack &);
  ~Stack();
  bool full() const;
  bool empty() const;
  void push(const int &);
  void pop();
  void print_capacity() const;
  void print_size() const;
  void print() const;
  Stack &operator=(const Stack &);
  int operator[](const int &) const;
  bool operator==(const Stack &) const;
  bool operator!=(const Stack &) const;
  void operator<(const int &);
  void operator--();
  Stack &operator+(const Stack &) const;
  Stack &operator+(const int &) const;
  friend Stack &operator+(const int &, const Stack &);
  friend std::ostream &operator<<(std::ostream &, const Stack &);
  friend std::istream &operator>>(std::istream &, Stack &);

private:
  int *address, size, capacity;
};
