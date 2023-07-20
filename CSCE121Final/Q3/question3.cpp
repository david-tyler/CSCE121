#include <iostream>
using std::cout, std::endl;

struct Node {
 public:
	double value; 
	Node* next;
	Node(double num) : value{num}, next{nullptr} {}
};
 
class CircList {
 private:
	Node* listptr;
 public:
    // Constructor
	CircList() : listptr{nullptr} {}

    // The insertNode function inserts a node with num copied to its value
	// member so that the list remains sorted in non-decreasing order.                 
	void insertNode(double num)
    {
        Node* new_node = new Node(num);
        if(listptr == nullptr) //if the head is null then we do not need to compare anything or loop so just set the head to the new node
        {
            listptr = new_node;
            listptr->next = listptr;
        }
        else if(new_node->value < listptr->value)//if the new value is the smallest we have to make it the head of the list and set the tail to point to the new head
        {
            new_node->next = listptr;
            Node* tail = listptr->next;//variable to point to the end or last node of the list
            while(tail->next != listptr)//loop through the list and get to the tail
            {
                tail = tail->next;
            }//at the end of the loop we have gotten to the last node
            tail->next = new_node; //set the tail's next to the new head keeping it circular

        }
        else
        {//since the list is circular we need to loop until we reach the head, listptr, again
            Node* temp = listptr->next; //set temp to the next value of listptr
            Node* prev = listptr; //create previous Node for inserting
            while(temp != listptr)
            {
                if(new_node->value < temp->value) //compare the values if the new node's value is less than the current node, insert it before the current node
                {
                    new_node->next = temp; //make the next of the new node point to the current node
                    prev->next = new_node; //make the next of the previous node point to the new node finishing the insertion
                    break; //just break out of the loop as we don't need to do anything else
                }
                
                prev = prev->next; //increment the previous node
                temp = temp->next; //increment the current node
            }
        }
        
    }
	// TODO(student): implement this function
 
	void print(std::ostream& os=std::cout) const {
    	// assumed to exist
    	// prints the list to the output stream (default: stdout)
	}
 
	// The mergeArray function merges the array passed into dArray into the
	//  ordered list.     	 
	void mergeArray(double dArray[], size_t size)
	// TODO(student): implement this function
    {
        for(size_t i = 0; i < size; i++)//loop to insert and compare each value in the array
        {
            insertNode(dArray[i]);//insert each value in the array into the node
            //we take care of comparisons and insertions in insertNode so nothing else is needed to be done
        }
        
    }
 
};

int main()
{

}