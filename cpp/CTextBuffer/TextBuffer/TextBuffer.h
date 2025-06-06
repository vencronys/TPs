﻿// TextBuffer.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <iostream>
#include <cwchar>
constexpr auto NEW_LINE = '\n';

class TextBuffer {
  public:
    TextBuffer(const char * = "NULL");
    TextBuffer(const TextBuffer &);
    ~TextBuffer();
    TextBuffer &operator=(const TextBuffer &);
    void display() const;
    int length() const;
    void insert(const char &, const int &);
    void remove(const char &);
    bool contains(const char &) const;
    TextBuffer &reverse() const;
    bool operator==(const TextBuffer &) const;
    TextBuffer &operator+(const TextBuffer &);
    char operator[](const int &) const;
    friend std::ostream &operator<<(std::ostream &, const TextBuffer &);
    friend std::istream &operator>>(std::istream &, TextBuffer &);

  protected:
    char *m_buffer;
};


// TODO: Reference additional headers your program requires here.
