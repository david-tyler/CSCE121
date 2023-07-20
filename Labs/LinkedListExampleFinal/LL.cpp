#include <iostream>
#include "Node.h"
#include "LL.h"

using std::string, std::ostream, std::endl;

// constructors
LL::LL() : head(nullptr), tail(nullptr) {}

LL::LL(string str) : head(nullptr), tail(nullptr) {
    for (size_t i = 0; i<str.length(); ++i) {
        insertTail(str.at(i));
    }
}
LL::LL(char*) : head(nullptr), tail(nullptr) {
    // Do on your own
} 
LL::LL(char) : head(nullptr), tail(nullptr) {
    // Do on your own
}
LL::LL(const LL& src) : head(nullptr), tail(nullptr) {
    Node* cur = src.head;
    while(cur != nullptr) {
        insertTail(cur->letter);
        cur = cur->next;
    }
}

// destructor
LL::~LL() {
    clear();
}

void LL::clear() {
    while (head != nullptr) {
        Node* delNode = head;
        head = head->next;
        delete delNode;
    }
    head = nullptr;
    tail = nullptr;
}

// copy constructor
LL& LL::operator=(const LL& src) {
    if (this != &src) {
        clear();
        Node* cur = src.head;
        while(cur != nullptr) {
            insertTail(cur->letter);
            cur = cur->next;
        }
    }
    return *this;
}

// setters and getters
void LL::insertFront(char) {
    // Do on your own
}
void LL::insertTail(char c) {
    Node* newNode = new Node(c);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    // else have a tail
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void LL::insertAfter(char insertChar, char afterChar) {
    // add to end of list if char not found
    Node* node = find(afterChar);
    if (node == nullptr) { // insert at the tail
        insertTail(insertChar);
        return;
    }
    // insert in middle
    Node* newNode = new Node(insertChar);
    newNode->next = node->next;
    newNode->prev = node;
    if (node->next == nullptr) { // new tail
        tail = newNode;
    }
    else {
        node->next->prev = newNode;
    }
    node->next = newNode;
    //

}
void LL::insertBefore(char, char) {
    // Do on your own
}

void LL::deleteChar(char c) {
    Node* node = find(c);
    if (node != nullptr) {
        if (head == node) {
            head = head->next;
        }
        if (tail == node) {
            tail = tail->prev;
        }
        // set prev node's next
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        // set next node's prev
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        delete node;
    }
}

bool LL::hasChar(char c) {
    Node* ptr = find(c);
    if (ptr == nullptr) {
        return false;
    }
    // else
    return true;
}

void LL::print(std::ostream& os) {
    if (head == nullptr) {
        os << "Empty List" << endl;
    }
    Node* cur = head;
    while(cur != nullptr) {
        os << cur->letter;
        cur = cur->next;
    }
    os << endl;
}

Node* LL::find(char c) {
    Node* cur = head;
    while(cur != nullptr && cur->letter != c) {
        cur = cur->next;
    }
    return cur;
}
