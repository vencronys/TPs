#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() { m_head = nullptr; }

LinkedList::LinkedList(const LinkedList &other) {
    m_head = nullptr;
    if (other.m_head == nullptr) {
        return;
    }
    this->insertAtStart(other.m_head->data);
    for (Node *current = other.m_head->next; current != nullptr;
         current = current->next) {
        this->insertAtEnd(current->data);
    }
}

LinkedList::~LinkedList() {
    while (m_head != nullptr) {
        this->deleteAtStart();
    }
}

LinkedList &LinkedList::operator=(const LinkedList &other) {
    if (&other == this) {
        return *this;
    }
    while (m_head != nullptr) {
        this->deleteAtStart();
    }
    if (other.m_head != nullptr) {
        this->insertAtStart(other.m_head->data);
        for (Node *current = other.m_head->next; current != nullptr;
             current = current->next) {
            this->insertAtEnd(current->data);
        }
    }
    return *this;
}

LinkedList &LinkedList::insertAtStart(const char *data) {
    Node *newNode;
    if ((newNode = new Node) == nullptr) {
        return *this;
    }
    if ((newNode->data = new char[std::strlen(data) + 1]) == nullptr) {
        return *this;
    }
    strcpy_s(newNode->data, std::strlen(data) + 1, data);
    std::cout << data;
    newNode->next = m_head;
    m_head = newNode;
    return *this;
}

LinkedList &LinkedList::insertAtEnd(const char *data) {
    Node *newNode, *lastNode;
    if ((newNode = new Node) == nullptr) {
        return *this;
    }
    if ((newNode->data = new char[std::strlen(data) + 1]) == nullptr) {
        return *this;
    }
    strcpy_s(newNode->data, std::strlen(data) + 1, data);
    lastNode = m_head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->next = nullptr;
    return *this;
}

LinkedList &LinkedList::insertAtPosition(const char *data, const int &pos) {
    Node *current, *newNode;
    if ((newNode = new Node) == nullptr) {
        return *this;
    }
    if ((newNode->data = new char[std::strlen(data) + 1]) == nullptr) {
        return *this;
    }
    current = m_head;
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }
    if (current->next != nullptr) {
        strcpy_s(newNode->data, std::strlen(data) + 1, data);
        newNode->next = current->next;
        current->next = newNode;
    }
    return *this;
}

LinkedList &LinkedList::deleteAtStart() {
    Node *nodeToDelete;
    if (m_head == nullptr) {
        return *this;
    }
    nodeToDelete = m_head;
    m_head = m_head->next;
    delete[] nodeToDelete->data;
    delete nodeToDelete;
    return *this;
}

LinkedList &LinkedList::deleteAtPosition(const int &pos) {
    Node *nodeToDelete, *current;
    current = m_head;
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }
    nodeToDelete = current->next;
    if (nodeToDelete->next == nullptr) {
        current->next = nullptr;
        delete[] nodeToDelete->data;
        delete nodeToDelete;
        std::cout << "You have deleted a node et the end of the liste.\n";
    } else {
        Node *temp;
        temp = current->next;
        current->next = temp->next;
        delete[] nodeToDelete->data;
        delete nodeToDelete;
        std::cout << "You have deleted a node at pos:" << pos << ",\n";
    }
    return *this;
}

void LinkedList::display() const {
    Node *current = m_head;
    std::cout << "The list contains:\n";
    while (current != NULL) {
        std::cout << current->data << '\n';
        current = current->next;
    }
}