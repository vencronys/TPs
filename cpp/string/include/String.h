#pragma once

#include <cwchar>
#include <ostream>
#define NEW_LINE '\n'

class String {
public:
  String(const char * = "NULL");
  String(const String &);
  ~String();
  String &operator=(const String &);
  void print() const;
  int length() const;
  void insert(const char &, const int &);
  void remove(const char &);
  bool contains(const char &) const;
  String &reverse() const;
  bool operator==(const String &) const;
  String &operator+(const String &);
  char operator[](const int &) const;
  friend std::ostream &operator<<(std::ostream &, const String &);
  friend std::istream &operator>>(std::istream &, String &);

private:
  char *buffer;
};
