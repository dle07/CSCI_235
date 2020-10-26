#include "Playlist.hpp"




template<typename xType>    //Calls default constructor of doubly Linked list
Playlist<xType> :: Playlist():DoublyLinkedList(){

};


template<typename xType>
double Playlist<xType> :: getTotalTime() const{
    double result{0};
    DoubleNode<xType>* curr = head;
    while( curr ){
        result += curr->getItem().getLength();
    }
    return result;
}

template<typename xType>
void Playlist<xType> :: operator += (Playlist rhs){
    this->itemCount += rhs.getSize();
    if( rhs -> getHeadPtr() == NULL) return;
    else if (this->tail == NULL)
    {
        this->itemCount = rhs.getSize();
        DoubleNode<xType>* curr = new DoubleNode<xType>(rhs.getHeadPtr()->getItem());
        DoubleNode<xType>* rhsNode = rhs.getHeadPtr()->getNext();
        
        this-> head = curr;
        while(rhsNode){
            DoubleNode<xType>* temp = new DoubleNode<xType>( rhsNode->getItem());
            curr->getNext(temp);
            temp->setPrevious(curr);
            curr = temp;
            rhsNode=rhsNode->getNext();
        }
        this->tail = curr;
    
        

    }else{
        this->itemCount += rhs.getSize();
        DoubleNode<xType>* rhsNode = rhs.head;
        DoubleNode<xType>* curr = this->tail;
        while(rhsNode){
            DoubleNode<xType>* temp = new DoubleNode<xType>(rhsNode->getItem());
            curr->setNext(temp);
            temp->setPrevious(curr);
            curr= temp;
        }
    }
}

