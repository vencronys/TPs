#include "String.h"
#include <iostream>

int main(int argv, char** argc) {
    String str1("Zed Text Editor");
    str1.print();
    std::cout << str1.length() << NEW_LINE;
    String str2;
    str2.print();
    str2 = str1;
    str2.print();
    str2.insert('N', 3);
    str2.print();
    str2 = str2.reverse();
    str2.print();
    str2 = str2.reverse();
    str2.print();
    str2.remove('N');
    str2.print();
    str2.remove('t');
    str2.print();
    std::cout << str2.length() << NEW_LINE;
    std::cout << (str1 == str2 ? "Equal" : "Not equal") << NEW_LINE;
    str1.print();
    String str3("Hello, ");
    String str4("World!");
    str3 = str3 + str4;
    str3.print();
    std::cout << str3.length() << NEW_LINE;
    return 0;
}
