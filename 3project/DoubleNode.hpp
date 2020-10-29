#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_


template<typename xType>
class DoubleNode{

    private:

    xType item_;
    DoubleNode<xType>* next_;
    DoubleNode<xType>* prev_;
    
    public:
DoubleNode();
DoubleNode(xType item);
    // Setter Functions
void setItem(const xType &anItem);
void setPrevious(DoubleNode<xType> *previousNodePtr);
void setNext(DoubleNode<xType> *nextNodePtr);

// Getter Functions
xType getItem() const;
DoubleNode<xType> *getNext() const;
DoubleNode<xType> *getPrevious() const;

    

};  //ends the defintion of the new user defined type
#include "DoubleNode.cpp"
//includes DoubleNode.cpp because this is a generic interface
#endif