#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_

#include "DoubleNode.hpp"

template <typename xType>
class DoublyLinkedList{

    protected:
    DoubleNode<xType>* head_;
    int size;

    public:
//Default Constructor
DoublyLinkedList();
//Copy Constructor 
DoublyLinkedList(const DoublyLinkedList<xType> &target);
//Destructor
~DoublyLinkedList();

bool insert(const xType &item, const int &position); 
   //inserts item at position in caller list
	
bool remove(const int &position);           
   //removes the node at position

int getSize() const;                        
   // returns the number of the nodes in the calling list
				
DoubleNode<xType> *getHeadPtr() const;   
   // returns a copy of the headPtr

DoubleNode<xType> *getAtPos(const int &pos) const; 
   // returns a pointer to the node located at pos

bool isEmpty() const;                       
   // returns whether the calling list is empty

void clear();                               
   // clears the list

int getIndexOf(const xType &item) const; 
   // returns the position of the given item in the list, -1 otherwise

void display() const;                    
   // prints the contents of the calling list in order

void displayBackwards() const;           
   // prints the contents of the calling list in reverse order

DoublyLinkedList<xType> interleave(const DoublyLinkedList<xType> &a_list);
    // returns the interleaved list of the calling and parameter lists



};

#include "DoublyLinkedList.cpp"





#endif