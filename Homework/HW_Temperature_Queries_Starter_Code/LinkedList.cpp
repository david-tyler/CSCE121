#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "Node.h"
#include <sstream>
#include <fstream>
#include <limits>
#include <cstdlib>

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	while(head != nullptr)
    {
        Node* delNode = head;
        head = head->next;
        delete delNode;
    }
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& source) : head(source.head), tail(source.tail) 
{
	// Implement this function
	delete head;
	delete tail;
	head = nullptr;
	tail = nullptr;
	head = source.getHead();
	tail = source.tail;
	
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if(this != &source)
	{
		this->clear();
		this->head = source.head;
		this->tail = source.tail;
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	Node* newNode = new Node(location, year, month, temperature);
	if(head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else if(head->next == nullptr)
	{
		Node* temp = head;
		if(newNode->data < temp->data)
		{
			newNode->next = temp;
		}
		head = newNode;
	}
	else
	{
		Node* temp = head;
		Node* prev = head;
		while (temp != nullptr)
		{
			if(newNode->data < temp->data)
			{
				newNode->next = temp;
				prev->next = newNode;
				break;
			}
			if(temp != head)
			{
				prev = prev->next;
			}
			temp = temp->next;
		}
		if(prev->data < newNode->data)
		{
			prev->next = newNode;
			newNode->next = temp;
			tail = newNode;
		}
	}
	

}

void LinkedList::clear() {
	// Implement this function
	delete this;
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;
	ostringstream OSS;
	Node* temp = head;
	while(temp!=nullptr)
	{
		OSS << temp->data.id << " " << temp->data.year << " " << temp->data.month
		<< " ";
		//OSS <<  fixed;
		OSS << temp->data.temperature;
		OSS << "\n";
		temp = temp->next;
	}
	outputString = OSS.str();
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
