#include <iostream>
#include "TextFloatBuffer.h"

TextFloatBuffer::TextFloatBuffer() {
    isFloat = false;
    value = 0;
}

TextFloatBuffer::TextFloatBuffer(const char* m_buffer) : TextBuffer(m_buffer) {
    isFloat = 0;
    value = 0;
}

TextFloatBuffer::TextFloatBuffer(const TextFloatBuffer& other) : TextBuffer(other) {
    isFloat = other.isFloat;
    value = other.value;
}

TextFloatBuffer::~TextFloatBuffer() {}

TextFloatBuffer &TextFloatBuffer::operator=(const TextFloatBuffer& other) {
    TextBuffer::operator=(other);
    isFloat = other.isFloat;
    value = other.value;
    return *this;
}

void TextFloatBuffer::display() const { TextBuffer::display(); 
std::cout << "isFlaot: " << isFloat << NEW_LINE << "value: " << value
              << NEW_LINE;
}

void TextFloatBuffer::calculateValue() { 
    float val = atof(m_buffer);
    if (val != 0) {
        isFloat = true;
        value = val;
    }

}