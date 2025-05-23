#pragma once
struct Node {
    char *m_data;
    Node *m_next;
};

class Liste {
  private:
    Node *m_buffer;

  public:
    Liste();
    Liste(const Liste &);
    virtual ~Liste();
    Liste &operator=(const Liste &);
    void display() const;
    Liste &insertAtStart(const char *);
    Liste &insertAtEnd(const char *);
    Liste &insertAtPosition(const char *, const int &);
    Liste &deleteAtStart();
    Liste &deleteAtPosition(const int &);
};
