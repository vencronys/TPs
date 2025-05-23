#pragma once
#include "TextBuffer.h"

class TextFloatBuffer : TextBuffer {
  public:
    TextFloatBuffer();
    TextFloatBuffer(const char *);
    TextFloatBuffer(const TextFloatBuffer &);
    ~TextFloatBuffer();
    TextFloatBuffer &operator=(const TextFloatBuffer &);
    void display() const;
    void calculateValue();

  private:
    bool isFloat;
    float value;
};