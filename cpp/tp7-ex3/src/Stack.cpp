#include "Stack.h"
#include <cwchar>
#include <iostream>
#include <ostream>

Stack::Stack(int capacity_) {
  capacity = capacity_;
  address = new int[capacity];
  size = 0;
}

Stack::Stack(const Stack &other) {
  capacity = other.capacity;
  address = new int[capacity];
  size = other.size;
  for (int i = 0; i < size; i++) {
    address[i] = other.address[i];
  }
}

Stack::~Stack() { delete[] address; }

bool Stack::full() const { return size == capacity; }

bool Stack::empty() const { return size == 0; }

void Stack::push(const int &number) {
  if (full()) {
    std::cout << "Stack is full!" << NEW_LINE;
    return;
  }
  address[size++] = number;
}
void Stack::pop() {
  if (empty()) {
    std::cout << "ERROR: STACK IS EMPTY!" << NEW_LINE;
    return;
  }
  size--;
}
void Stack::print_capacity() const {
  std::cout << "The Stack's capacity is " << capacity << NEW_LINE;
}

void Stack::print_size() const {
  if (empty()) {
    std::cout << "ERROR: STACK IS EMPTY!" << NEW_LINE;
    return;
  }
  std::cout << "The Stack's size is " << size << NEW_LINE;
}

void Stack::print() const {
  if (empty()) {
    std::cout << "The stack is empty." << NEW_LINE;
    return;
  }
  for (int i = 0; i < size; i++) {
    std::cout << address[i] << " ";
  }
  std::cout << NEW_LINE;
}

Stack &Stack::operator=(const Stack &other) {
  if (this == &other) {
    return *this;
  }
  delete[] address;
  capacity = other.capacity;
  address = new int[capacity];
  size = other.size;
  for (int i = 0; i < size; i++) {
    address[i] = other.address[i];
  }
  return *this;
}

int Stack::operator[](const int &index) const {
  if (index < 0 || index >= size) {
    std::cout << "ERROR: INDEX OUT OF RANGE!" << NEW_LINE;
    return -1;
  }
  return address[index];
}

bool Stack::operator==(const Stack &other) const {
  if (size != other.size) {
    return false;
  }
  for (int i = 0; i < size; i++) {
    if (address[i] != other.address[i]) {
      return false;
    }
  }
  return true;
}

bool Stack::operator!=(const Stack &other) const { return !(*this == other); }

void Stack::operator<(const int &number) {
  if (full()) {
    std::cout << "Stack is full!" << NEW_LINE;
    return;
  }
  address[size++] = number;
}

void Stack::operator--() {
  if (empty()) {
    std::cout << "ERROR: STACK IS EMPTY!" << NEW_LINE;
    return;
  }
  size--;
}

Stack &Stack::operator+(const Stack &other) const {
  static Stack result(*this);
  for (int i = 0; i < other.size; i++) {
    result.address[i] += other.address[i];
  }
  return result;
}

Stack &Stack::operator+(const int &number) const {
  static Stack result(*this);
  for (int i = 0; i < size; i++) {
    result.address[i] += number;
  }
  return result;
}

Stack &operator+(const int &number, const Stack &stack) {
  static Stack result(stack);
  for (int i = 0; i < stack.size; i++) {
    result.address[i] += number;
  }
  return result;
}

std::ostream &operator<<(std::ostream &os, const Stack &stack) {
  os << "[";
  for (int i = 0; i < stack.size; i++) {
    os << stack.address[i];
    if (i < stack.size - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

std::istream &operator>>(std::istream &is, Stack &stack) {
  int value;
  while (stack.size < stack.capacity) {
    is >> value;
    stack.push(value);
  }
  return is;
}
