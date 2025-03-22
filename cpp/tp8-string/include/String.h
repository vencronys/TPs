#pragma once
class String {
public:
    String(const char * = "NULL");
    String(const String &);
    ~String();
    String &operator=(const String &);
    void print() const;
    int length() const;

private:
    char *buffer;
};
