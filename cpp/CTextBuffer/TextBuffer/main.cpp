#include "TextFloatBuffer.h"

int main(int argc, char** argv) { 
	TextBuffer TB1;
    TB1.display();
    TextFloatBuffer TFB1("1337");
    TFB1.display();
    TFB1.calculateValue();
    TFB1.display();
	return 0;
}