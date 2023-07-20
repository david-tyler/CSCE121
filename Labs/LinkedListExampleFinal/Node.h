#ifndef NODE_H
#define NODE_H

class Node { // could also use a struct here
public:
    char letter;
    Node* next;
    Node* prev;
    Node(char letter) : letter(letter), next(nullptr), prev(nullptr) {}
};

#endif 

// doubly linked list