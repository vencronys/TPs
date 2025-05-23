#include "String.h"
#include <cstring>
#include <string.h>
#include <iostream>

String::String(const char *other_buffer) {
    int size = 1, i = 0;
    while (*(other_buffer + i++) && size++) {}
    buffer = new char[size + 1];
    i = -1;
    while (*(other_buffer + ++i)) {
        *(buffer + i) = *(other_buffer + i);
    }
    *(buffer + size) = '\0';
}

String::String(const String &other) {
    int size = other.length(), i = -1;
    buffer = new char[size + 1];
    while (*(other.buffer + ++i)) {
        *(buffer + i) = *(other.buffer + i);
    }
    *(buffer + size) = '\0';
}

String::~String() { delete[] buffer; }

String &String::operator=(const String &other) {
    delete[] buffer;
    int size = other.length(), i = -1;
    buffer = new char[size + 1];
    while (*(other.buffer + ++i)) {
        *(buffer + i) = *(other.buffer + i);
    }
    *(buffer + size) = '\0';
    return *this;
}

void String::print() const { std::cout << buffer << NEW_LINE; }

int String::length() const {
    int size = 1, i = 0;
    while (*(buffer + i++) && size++) {
    }
    return --size;
}

void String::insert(const char &c, const int &index) {
    int size = length(), i = -1;
    if (index < 0) {
        std::cout << "ERROR: inserting at a negative index" << NEW_LINE;
    }
    char *temp = new char[size + 1];
    while (*(buffer + ++i)) {
        *(temp + i) = *(buffer + i);
    }
    *(temp + size) = '\0';
    delete[] buffer;
    buffer = new char[size + 2];
    i = -1;
    while (*(temp + ++i)) {
        *(buffer + i) = *(temp + i);
    }
    *(buffer + index) = c;
    while (*(temp + index + ++i)) {
        *(buffer + index + i + 1) = *(temp + index + i + 1);
    }
    i = -1;
    while (*(temp + ++i)) {
        *(buffer + i) = *(temp + i);
    }
    *(buffer + size + 1) = '\0';
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
    int size = length(), count = 0, i = -1, j = 0;
    char *temp = new char[size + 1];
    while (*(buffer + ++i)) {
        *(temp + i) = *(buffer + i);
    }
    *(temp + size) = '\0';
    delete[] buffer;
    while (*(temp + i)) {
        if (*(temp + i++) == c) {
            count++;
        }
    }
    buffer = new char[size - count + 1];
    i = 0;
    while (*(temp + i)) {
        if (*(temp + i) != c) {
            *(buffer + j++) = *(temp + i);
        }
        i++;
    }
    *(buffer + size - count) = '\0';
}

String &String::reverse() const {
    int size = length();
    static String res(*this);
    int i = -1;
    while (*(buffer + ++i)) {
        *(res.buffer + i) = *(buffer + size - i - 1);
    }
    return res;
}

bool String::operator==(const String &other) const {
    int size = length(), other_size = other.length(), i = -1;
    if (size != other_size) {
        return false;
    }
    while (*(buffer + ++i)) {
        if (*(buffer + i) != *(other.buffer + i)) {
            return false;
        }
    }
    return true;
}

String &String::operator+(const String &other) {
    int size = length(), other_size = other.length(), i = -1, j = -1;
    char *buffer_res = new char[size + other_size + 1];
    std::cout << size + other_size + 1 << NEW_LINE;
    while (*(buffer + ++i)) {
        *(buffer_res + i) = *(buffer + i);
        std::cout << i << " " << *(buffer_res + i) << NEW_LINE;
    }
    while (*(other.buffer + ++j)) {
        *(buffer_res + i++) = *(other.buffer + j);
        std::cout << j << " " << i << " " << *(buffer_res + (i- 1)) << NEW_LINE;
    }
    *(buffer_res + size + other_size) = '\0';
    static String res(buffer_res);
    return res;
}

char String::operator[](const int &index) const {
    return *(buffer + index);
}

std::ostream &operator<<(std::ostream &os, const String &str) {
    os << str.buffer;
    return os;
}

std::istream &operator>>(std::istream &is, String &str) {
    char temp[1024];
    is >> temp;
    delete[] str.buffer;
    int size = 1, i = 0;
    while (*(temp + i++) && size++) {}
    str.buffer = new char[size + 1];
    i = -1;
    while (*(temp + ++i)) {
        *(str.buffer + i) = *(temp + i);
    }
    *(str.buffer + size) = '\0';
    return is;
}
