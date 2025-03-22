#include "String.h"
#include <cstring>
#include <iostream>

#define NEW_LINE '\n';

String::String(const char *buffer_) {
    int size = std::strlen(buffer_);
    buffer = new char[size + 1];
    std::strncpy(buffer, buffer_, size + 1);
    buffer[size + 1] = '\0';
}

String::String(const String &str) {
    int size = std::strlen(str.buffer);
    buffer = new char[size + 1];
    std::strncpy(buffer, str.buffer, size + 1);
    buffer[size + 1] = '\0';
}

String::~String() { delete[] buffer; }

String &String::operator=(const String &str) {
    delete[] buffer;
    int size = std::strlen(str.buffer);
    buffer = new char[size + 1];
    std::strncpy(buffer, str.buffer, size + 1);
    buffer[size + 1] = '\0';
    return *this;
}

void String::print() const { std::cout << buffer << NEW_LINE; }

int String::length() const {
    int size = 0;
    const char *temp = buffer;
    while (*temp++) {
        size++;
    }
    return size;
}
