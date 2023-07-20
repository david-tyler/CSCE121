#ifndef LL_H
#define LL_H

#include <string>
#include <iostream>
#include "Node.h"

class LL { 
    Node* head;
    Node* tail;
public:
    // constructors
    LL();
    LL(std::string);
    LL(char*); // c-string
    LL(char);
    LL(const LL&); // copy constructor

    // destructor
    ~LL();

    // copy assignment
    LL& operator=(const LL&);

    // setters and getters
    void insertFront(char);
    void insertTail(char);
    void insertAfter(char, char);
    void insertBefore(char, char);

    void deleteChar(char);
    void clear();

    bool hasChar(char);

    void print(std::ostream& = std::cout);
private:
    Node* find(char);
};

#endif