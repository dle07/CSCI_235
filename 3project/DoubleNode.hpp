#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

template<typename xType>
class DoubleNode{

    private:
    xType item_;
    DoubleNode <xType>* prev;
    DoubleNode <xType>* next;
    
    public:
    DoubleNode();
    DoubleNode(xType item);
    void setItem(const xType &anItem);
    void setPrevious(DoubleNode<xType> *previousNodePtr);
    void setNext(DoubleNode<xType> *nextNodePtr);
    xType getItem() const;
    DoubleNode<xType> *getNext() const;
    DoubleNode<xType> *getPrevious() const;

    

};  //ends the defintion of the new user defined type
#include "DoubleNode.cpp"
//includes DoubleNode.cpp because this is a generic interface
#endif