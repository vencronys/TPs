#pragma once
#include "TextBuffer.h"

class TextFloatBuffer : public TextBuffer {
  public:
    TextFloatBuffer();
    TextFloatBuffer(const char *);
    TextFloatBuffer(const TextFloatBuffer &);
    ~TextFloatBuffer();
    TextFloatBuffer &operator=(const TextFloatBuffer &);
    void display() const;
    void calculateValue();

  private:
    bool m_isFloat;
    float m_value;
};