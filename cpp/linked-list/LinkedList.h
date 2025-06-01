#pragma once
#include "Node.h"
class LinkedList {
  private:
    Node *m_head = nullptr;

  public:
    LinkedList();
    LinkedList(const LinkedList &);
    virtual ~LinkedList();
    LinkedList &operator=(const LinkedList &);
    void display() const;
    LinkedList &insertAtStart(const char *);
    LinkedList &insertAtEnd(const char *);
    LinkedList &insertAtPosition(const char *, const int &);
    LinkedList &deleteAtStart();
    LinkedList &deleteAtPosition(const int &);
};
