#include "Liste.h"
#include <cstringt.h>
#include <iostream>

Liste::Liste() {
    m_buffer = NULL;
    std::cout << "Constructor\n";
}

Liste::Liste(const Liste &list) {
    m_buffer = NULL;
    if (list.m_buffer != NULL) {
        this->insertAtStart(list.m_buffer->m_data);
        for (Node *current = list.m_buffer->m_next; current != NULL;
             current = current->m_next) {
            this->insertAtEnd(current->m_data);
        }
    }
}
Liste::~Liste() {
    while (m_buffer != NULL) {
        this->deleteAtStart();
    }
    std::cout << "Desctructor\n";
}
Liste &Liste::operator=(const Liste &liste) {
    if (&liste != this) {
        while (m_buffer != NULL) {
            this->deleteAtStart();
        }
        if (liste.m_buffer != NULL) {
            this->insertAtStart(liste.m_buffer->m_data);
            for (Node *current = liste.m_buffer->m_next; current != NULL;
                 current = current->m_next) {
                this->insertAtEnd(current->m_data);
            }
        }
    }
    std::cout << "Operateur =\n";
    return *this;
}

void Liste::display() const {
    Node *current = m_buffer;
    std::cout << "The list contains:\n";
    while (current != NULL) {
        std::cout << current->m_data << '\n';
        current = current->m_next;
    }
}

Liste &Liste::insertAtStart(const char *data) {
    Node *newNode;
    if ((newNode = new Node) == NULL) {
        return *this;
    }
    if ((newNode->m_data = new char[std::strlen(data)+1]) == NULL) {
        return *this;
    }
    strcpy_s(newNode->m_data, std::strlen(data)+1, data);
    std::cout << data;
    newNode->m_next = m_buffer->m_next;
    m_buffer->m_next = newNode;
    return *this;
}

Liste &Liste::insertAtEnd(const char *data) {
    Node *newNode, *lastNode;
    if ((newNode = new Node) == NULL) {
        return *this;
    }
    if ((newNode->m_data = new char[std::strlen(data) + 1]) == NULL) {
        return *this;
    }
    strcpy_s(newNode->m_data, std::strlen(data) + 1, data);
    lastNode = m_buffer;
    while (lastNode->m_next != NULL) {
        lastNode = lastNode->m_next;
    }
    lastNode->m_next = newNode;
    newNode->m_next = NULL;
    return *this;
}

Liste &Liste::insertAtPosition(const char *data, const int &pos) {
    Node *current, *newNode;
    if ((newNode = new Node) == NULL) {
        return *this;
    }
    if ((newNode->m_data = new char[std::strlen(data) + 1]) == NULL) {
        return *this;
    }
    current = m_buffer;
    for (int i = 1; i < pos; i++) {
        current = current->m_next;
    }
    if (current->m_next != NULL) {
        strcpy_s(newNode->m_data, std::strlen(data) + 1, data);
        newNode->m_next = current->m_next;
        current->m_next = newNode;
    }
    return *this;
}

Liste &Liste::deleteAtStart() {
    Node *nodeToDelete;
    if (m_buffer == NULL) {
        return *this;
    }
    nodeToDelete = m_buffer;
    m_buffer = m_buffer->m_next;
    delete[] nodeToDelete->m_data;
    delete nodeToDelete;
    return *this;
}

Liste &Liste::deleteAtPosition(const int &pos) {
    Node *nodeToDelete, *current;
    current = m_buffer;
    for (int i = 1; i < pos; i++) {
        current = current->m_next;
    }
    nodeToDelete = current->m_next;
    if (nodeToDelete->m_next == NULL) {
        current->m_next = NULL;
        delete[] nodeToDelete->m_data;
        delete nodeToDelete;
        std::cout << "You have deleted a node et the end of the liste.\n";
        return *this;
    } else {
        Node *temp;
        temp = current->m_next;
        current->m_next = temp->m_next;
        delete[] nodeToDelete->m_data;
        delete nodeToDelete;
        std::cout << "You have deleted a node at pos:" << pos << ",\n";
        return *this;
    }
}