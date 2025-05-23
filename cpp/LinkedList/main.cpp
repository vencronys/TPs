#include <iostream>
#include <string.h>

struct Node {
    char *textBuffer;
    Node *next;
};

void print(Node *);
Node *insertAtStart(Node *, const char *);
Node *insertAtEnd(Node *, const char *);
Node *insertAtPosition(Node *, const char *, const int &);
Node *deleteAtStart(Node *);
Node *deleteAtIndex(Node *, const int &);

int main()
{
    Node *node = NULL;
    node = insertAtStart(node, "Start 1");
    node = insertAtEnd(node, "end 1");
    //node = insertAtPosition(node, "End 1", 1);
    print(node);
    int i = 0;
	return 0;
}

void print(Node* node) { 
    Node *currentNode = node;
    std::cout << "The list contains:\n";
    while (currentNode != NULL) {
        std::cout << node->textBuffer << "\t\n";
        currentNode = currentNode->next;
    }
}

Node* insertAtStart(Node* node, const char* str) { 
    Node *newNode;
    int size = std::strlen(str) + 1;
    if ((newNode = new Node) == NULL)
        return node;
    if ((newNode->textBuffer = new char[size]) == NULL)
        return node;
    //std::strcpy(newNode->textBuffer, str);
    strcpy_s(newNode->textBuffer, size, str);
    //*(newNode->textBuffer + size) = '\0';
    newNode->next = node;
    node = newNode;
    return node;
}

Node* insertAtEnd(Node* node, const char* str) { 
    Node *newNode, *lastNode;
    size_t size = std::strlen(str) + 1;
    if ((newNode = new Node) == NULL)
        return node;
    if ((newNode->textBuffer = new char[size]) == NULL)
        return node;
    strcpy_s(newNode->textBuffer, size, str);
    //*(newNode->textBuffer + size) = '\0';
    lastNode = node;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->next = NULL;
    return node;
}

Node* insertAtPosition(Node* node, const char* str, const int& pos) {
    Node *newNode, *currentNode;
    size_t size = std::strlen(str) + 1;
    if ((newNode = new Node) == NULL)
        return node;
    if ((newNode->textBuffer = new char[size]) == NULL)
        return node;
    currentNode = node;
    for (int i = 0; i < pos; i++)
        currentNode = currentNode->next;
    if (currentNode->next != NULL) {
        std::strcpy(newNode->textBuffer, str);
        //*(newNode->textBuffer + size) = '\0';
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    return node;

}

Node *deleteAtStart(Node *node) {
    Node *nodeToDelete; 
    if (node == NULL)
        return NULL;
    nodeToDelete = new Node;
    nodeToDelete->textBuffer = new char[50];
    nodeToDelete = node;
    node = node->next;
    delete[] nodeToDelete->textBuffer;
    delete nodeToDelete;
    return node;
}

Node* deleteAtIndex(Node *node, const int& pos) {
    Node *nodeToDelete, *currentNode;
    currentNode = node;
    nodeToDelete = new Node;
    nodeToDelete->textBuffer = new char[50];
    for (int i = 0; i < pos; i++)
        currentNode = currentNode->next;
    nodeToDelete = currentNode->next;
    if (nodeToDelete->next == NULL) {
        currentNode->next = NULL;
    }
}
