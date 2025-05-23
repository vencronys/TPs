#include "TextFloatBuffer.h"
#include <iostream>

TextFloatBuffer::TextFloatBuffer() {
    m_isFloat = false;
    m_value = 0;
}

TextFloatBuffer::TextFloatBuffer(const char *m_buffer) : TextBuffer(m_buffer) {
    m_isFloat = 0;
    m_value = 0;
}

TextFloatBuffer::TextFloatBuffer(const TextFloatBuffer &other)
    : TextBuffer(other) {
    m_isFloat = other.m_isFloat;
    m_value = other.m_value;
}

TextFloatBuffer::~TextFloatBuffer() {}

TextFloatBuffer &TextFloatBuffer::operator=(const TextFloatBuffer &other) {
    TextBuffer::operator=(other);
    m_isFloat = other.m_isFloat;
    m_value = other.m_value;
    return *this;
}

void TextFloatBuffer::display() const {
    TextBuffer::display();
    std::cout << "isFlaot: " << m_isFloat << NEW_LINE << "value: " << m_value
              << NEW_LINE;
}

// TODO: MAKE YOUR OWN float atof(const char *buffer)
void TextFloatBuffer::calculateValue() {
    float val = atof(m_buffer);
    if (val != 0) {
        m_isFloat = true;
        m_value = val;
    }
}