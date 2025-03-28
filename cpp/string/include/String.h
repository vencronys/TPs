#pragma once

#define NEW_LINE '\n';

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
  void reverse();

private:
  char *buffer;
};
