#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList list;

    // Test: Insert at start
    list.insertAtStart("Node3");
    list.insertAtStart("Node2");
    list.insertAtStart("Node1");
    std::cout << "After inserting at start:\n";
    list.display();

    // Test: Insert at end
    list.insertAtEnd("Node4");
    std::cout << "\nAfter inserting at end:\n";
    list.display();

    // Test: Insert at position (insert "Node2.5" at position 2)
    list.insertAtPosition("Node2.5", 2);
    std::cout << "\nAfter inserting at position 2:\n";
    list.display();

    // Test: Delete at start
    list.deleteAtStart();
    std::cout << "\nAfter deleting at start:\n";
    list.display();

    // Test: Delete at position (delete node at position 3)
    list.deleteAtPosition(2);
    std::cout << "\nAfter deleting at position 2:\n";
    list.display();

    // Test: Copy constructor
    LinkedList copyList(list);
    std::cout << "\nCopy of the list (using copy constructor):\n";
    copyList.display();

    // Test: Assignment operator
    LinkedList assignedList;
    assignedList = list;
    std::cout << "\nAssigned list (using assignment operator):\n";
    assignedList.display();

    return 0;
}