#include "Liste.h"

int main() {
    Liste A, B = A;
    A.display();
    A.insertAtStart("aaa");
    A.display();
    A.insertAtEnd("ddd");
    B = A;
    B.display();
    A.insertAtPosition("bbb", 1);
    A.display();
    A.insertAtPosition("ccc", 2);
    A.display();
    A.deleteAtPosition(3);
    A.display();
	return 0;
}