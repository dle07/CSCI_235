/*
    Project 3
    Author: Daniel Le
    Student Doublly Linked List Implememntation Project

*/
#include "DoubleNode.hpp"
template <typename xType> 
DoubleNode <xType> ::DoubleNode(){

};





template <typename xType> 
DoubleNode <xType> :: DoubleNode(xType item){
    this->item_ = item;
    prev=nullptr;
    next=nullptr;
    
}
template<typename xType>
void DoubleNode <xType> :: setItem(const xType &anItem){
    this->item_ = anItem;
};


template<typename xType>
void DoubleNode <xType> :: setPrevious(DoubleNode<xType> *previousNodePtr){
    this->prev = previousNodePtr;
}

template<typename xType>
void DoubleNode <xType> :: setNext(DoubleNode<xType> *nextNodePtr){
    this->next = nextNodePtr;
}



template<typename xType>
xType DoubleNode <xType>  :: getItem() const {
    return this->item_;
}

template<typename xType>
DoubleNode<xType>* DoubleNode <xType> :: getNext() const{
    return this->next;
}

template<typename xType>
DoubleNode<xType>* DoubleNode <xType> :: getPrevious() const{
    return this->prev;
}





