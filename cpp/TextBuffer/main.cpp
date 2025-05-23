#include "TextFloatBuffer.h"

int main(int argc, char **argv) {
    TextBuffer tb1;
    tb1.display();
    TextFloatBuffer tfb1("1337");
    tfb1.display();
    tfb1.calculateValue();
    tfb1.display();
    TextBuffer tb2("Hello");
    tb2.display();
    TextBuffer tb3 = tb2;
    tb3.display();
    tb3.remove('l');
    tb3.display();
    tb3.insert('l', 2);
    tb3.insert('l', 2);
    tb3.display();
    std::cout << tb3.contains('H') << NEW_LINE;
    tb1 = tb3;
    tb1.display();
    tb1 = tb1.reverse();
    std::cout << (tb1 == tb3) << NEW_LINE;
    tb1.display();
    tb1 = tb1 + tb3;
    tb1.display();
    /*std::cin >> tb1;
    tb1.display();*/

    TextFloatBuffer tfb2("123e");
    tfb2.calculateValue();
    tfb2.display();
    return 0;
}