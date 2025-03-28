#include "String.h"
#include <cstring>
#include <iostream>

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
    std::strncpy(buffer, str.buffer, size);
    buffer[size + 1] = '\0';
    return *this;
}

void String::print() const { std::cout << buffer << NEW_LINE; }

int String::length() const {
    int size = 1;
    int i = 0;
    while (*(buffer + i++) && size++) {}
    return --size;
}

void String::insert(const char &c, const int &index) {
    int size = length();
    char *temp = new char [size + 1];
    std::strncpy(temp, buffer, size);
    temp[size] = '\0';
    delete[] buffer;
    buffer = new char[size + 2];
    std::strncpy(buffer, temp, index);
    buffer[index] = c;
    std::strncpy(buffer + index + 1, temp + index, size - index);
    delete[] temp;
}

bool String::contains(const char &c) const {
    int i = 0;
    while (*(buffer + i)) {
        if (*(buffer + i++) == c) {
            return true;
        }
    }
    return false;
}

void String::remove(const char &c) {
    int size = length(), count = 0, i = 0;
    char *temp = new char [size + 1];
    std::strncpy(temp, buffer, size);
    temp[size] = '\0';
    delete[] buffer;
    while (*(temp + i)) {
        if (*(temp + i++) == c) {
            count++;
        }
    }
    buffer = new char[size - count + 1];
    i = 0;
    int j = 0;
    while (*(temp + i)) {
        if (*(temp + i) != c) {
            *(buffer + j++) = *(temp + i);
        }
        i++;
    }
}

void String::reverse() {
    int size = length();
    int i = 0;
    while (*(buffer + i*2)) {
        char temp = *(buffer + i);
        *(buffer + i) = *(buffer + size - i - 1);
        *(buffer + size - i - 1) = temp;
        i++;
    }
}
