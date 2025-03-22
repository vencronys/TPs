#include "String.h"
#include <iostream>

#define NEW_LINE '\n';

int main(int argv, char** argc) {
    String str1("Zed Text Editor");
    str1.print();
    std::cout << str1.length() << NEW_LINE;
    String str2;
    str2.print();
    str2 = str1;
    str2.print();
    return 0;
}
