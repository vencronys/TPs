// TextBuffer.cpp : Defines the entry point for the application.
//

#include "TextBuffer.h"
#include "String.h"
#include <cstring>
#include <iostream>

TextBuffer::TextBuffer(const char *other_buffer) {
    int size = 1, i = 0;
    while (*(other_buffer + i++) && size++) {
    }
    m_buffer = new char[size];
    i = -1;
    while (*(other_buffer + ++i)) {
        *(m_buffer + i) = *(other_buffer + i);
    }
    *(m_buffer + size) = '\0';
    {}
}

TextBuffer::TextBuffer(const TextBuffer &other) {
    int size = other.length(), i = -1;
    m_buffer = new char[size + 1];
    while (*(other.m_buffer + ++i)) {
        *(m_buffer + i) = *(other.m_buffer + i);
    }
    *(m_buffer + size) = '\0';
}

TextBuffer::~TextBuffer() { delete[] m_buffer; }

TextBuffer &TextBuffer::operator=(const TextBuffer &other) {
    delete[] m_buffer;
    int size = other.length(), i = -1;
    m_buffer = new char[size + 1];
    while (*(other.m_buffer + ++i)) {
        *(m_buffer + i) = *(other.m_buffer + i);
    }
    *(m_buffer + size) = '\0';
    return *this;
}

void TextBuffer::display() const { std::cout << m_buffer << NEW_LINE;
}

int TextBuffer::length() const {
    int size = 1, i = 0;
    while (*(m_buffer + i++) && size++) {
    }
    return --size;
}

void TextBuffer::insert(const char &c, const int &index) {
    int size = length(), i = -1;
    if (index < 0) {
        std::cout << "ERROR: inserting at a negative index" << NEW_LINE;
    }
    char *temp = new char[size + 1];
    while (*(m_buffer + ++i)) {
        *(temp + i) = *(m_buffer + i);
    }
    *(temp + size) = '\0';
    delete[] m_buffer;
    m_buffer = new char[size + 2];
    i = -1;
    while (*(temp + ++i)) {
        *(m_buffer + i) = *(temp + i);
    }
    *(m_buffer + index) = c;
    while (*(temp + index + ++i)) {
        *(m_buffer + index + i + 1) = *(temp + index + i + 1);
    }
    i = -1;
    while (*(temp + ++i)) {
        *(m_buffer + i) = *(temp + i);
    }
    *(m_buffer + size + 1) = '\0';
    delete[] temp;
}

bool TextBuffer::contains(const char &c) const {
    int i = 0;
    while (*(m_buffer + i)) {
        if (*(m_buffer + i++) == c) {
            return true;
        }
    }
    return false;
}

void TextBuffer::remove(const char &c) {
    int size = length(), count = 0, i = -1, j = 0;
    char *temp = new char[size + 1];
    while (*(m_buffer + ++i)) {
        *(temp + i) = *(m_buffer + i);
    }
    *(temp + size) = '\0';
    delete[] m_buffer;
    while (*(temp + i)) {
        if (*(temp + i++) == c) {
            count++;
        }
    }
    m_buffer = new char[size - count + 1];
    i = 0;
    while (*(temp + i)) {
        if (*(temp + i) != c) {
            *(m_buffer + j++) = *(temp + i);
        }
        i++;
    }
    *(m_buffer + size - count) = '\0';
}

TextBuffer &TextBuffer::reverse() const {
    int size = length();
    static TextBuffer res(*this);
    int i = -1;
    while (*(m_buffer + ++i)) {
        *(res.m_buffer + i) = *(m_buffer + size - i - 1);
    }
    return res;
}

bool TextBuffer::operator==(const TextBuffer &other) const {
    int size = length(), other_size = other.length(), i = -1;
    if (size != other_size) {
        return false;
    }
    while (*(m_buffer + ++i)) {
        if (*(m_buffer + i) != *(other.m_buffer + i)) {
            return false;
        }
    }
    return true;
}

TextBuffer &TextBuffer::operator+(const TextBuffer &other) {
    int size = length(), other_size = other.length(), i = -1, j = -1;
    char *buffer_res = new char[size + other_size + 1];
    std::cout << size + other_size + 1 << NEW_LINE;
    while (*(m_buffer + ++i)) {
        *(buffer_res + i) = *(m_buffer + i);
        std::cout << i << " " << *(buffer_res + i) << NEW_LINE;
    }
    while (*(other.m_buffer + ++j)) {
        *(buffer_res + i++) = *(other.m_buffer + j);
        std::cout << j << " " << i << " " << *(buffer_res + (i - 1))
                  << NEW_LINE;
    }
    *(buffer_res + size + other_size) = '\0';
    static TextBuffer res(buffer_res);
    return res;
}

char TextBuffer::operator[](const int &index) const { return *(m_buffer + index); }

std::ostream &operator<<(std::ostream &os, const TextBuffer &str) {
    os << str.m_buffer;
    return os;
}

std::istream &operator>>(std::istream &is, TextBuffer &str) {
    char temp[1024];
    is >> temp;
    delete[] str.m_buffer;
    int size = 1, i = 0;
    while (*(temp + i++) && size++) {
    }
    str.m_buffer = new char[size + 1];
    i = -1;
    while (*(temp + ++i)) {
        *(str.m_buffer + i) = *(temp + i);
    }
    *(str.m_buffer + size) = '\0';
    return is;
}
