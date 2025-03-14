#include "Stack.h"
#include <iostream>

#define NEW_LINE '\n';

Stack::Stack(int capacity_) {
  capacity = capacity_;
  address = new int[capacity];
  size = 0;
}

Stack::~Stack() { delete[] address; }

bool Stack::full() const { return size == capacity; }

bool Stack::empty() const { return size == 0; }

void Stack::add(int number) {
  if (full()) {
    std::cout << "Stack is full!" << NEW_LINE;
    return;
  }
  *(address + size++) = number;
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
    std::cout << *(address + i) << " ";
  }
  std::cout << NEW_LINE;
}
