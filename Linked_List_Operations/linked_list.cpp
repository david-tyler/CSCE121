#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    // TODO(student)
    MyNode* newNode = new MyNode(name, score);
    if(_head == nullptr)
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        _tail->next = newNode;
        newNode->prev = _tail;
        _tail = newNode;
    }
    _size++;
}

void MyList::clear() {
    // TODO(student)
    while(_head != nullptr)
    {
        MyNode* delNode = _head;
        _head = _head->next;
        delete delNode;
    }
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

bool MyList::remove(const std::string& name) {
    // TODO(student)
    return false;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO(student)
    return false;
}

MyList::MyList()
  : _size(0), _head(nullptr), _tail(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}


