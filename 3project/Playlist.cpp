#include "Playlist.hpp"

#include <unordered_set>


template<typename xType>    //Calls default constructor of doubly Linked list
Playlist<xType> :: Playlist(){
    

};


template<typename xType>
double Playlist<xType> :: getTotalTime() const{
    double result{0};
    DoubleNode<xType>* curr = this->head;
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


template<typename xType>
void Playlist<xType> :: operator-=(Playlist rhs){
    std :: unordered_set <std :: string > mySet();
    DoubleNode<xType>* rhsNode = rhs.head;

    while( rhsNode ){
        mySet.insert(rhsNode->getItem());
        rhsNode = rhsNode ->getNext();
    }

    while(mySet.find(this->head->getItem())){
        if(this->head->getNext() == NULL){
            delete this->head;
            this->head = NULL;
            this->tail = NULL;
        }else{
            DoubleNode<xType>* temp = head ->getNext();
            delete head;
            head = temp;
        }
        this->itemCount --;
    }

    DoubleNode<xType>* curr = this->head;
    while( curr ){
        if( mySet.find(curr->getItem())){
            if( curr == this-> tail){
                curr->getPrevious()->setNext(NULL);
                this->tail = curr->getPrevious();
                delete curr;
                curr = nullptr;

            }else{
                DoubleNode<xType>* temp = curr->getNext();
                curr->getPrevious()->setNext(curr->getNext());
                curr->getNext()->setPrevious(curr->getPrevious());
                delete curr;
                curr = temp;
            }
            itemCount++;
            continue;
        }
        curr = curr ->getNext();
    }
    

}

template<typename xType>
void Playlist<xType> :: skip(){
    //If playlist has one 
    if( head == NULL || head->getNext() == NULL)return;

    //Temporarily stores address of head
    DoubleNode<xType>* temp = head;
    //Sets head to the 2nd node
    this->head = this->head->getNext();

    //Sets the second node previous link to null as it's now the head
    temp->getNext()->setPrevious(nullptr);
    //Destroys all link of the prior head
    temp->setNext(nullptr);
    temp->setPrevious(nullptr);
    //Moves the head node to be the tail by setting the tail node's next to the temp
    tail->setNext(temp);
    //Finalizes the link by setting the temp's prev link to the tail
    temp->setPrevious(this->tail);
    //Sets tail to new tail
    this->tail = temp;

}


template<typename xType>
void Playlist<xType> :: rewind(){

    //Nothing to do
    if(this->head == NULL || this->head->getNext() == NULL)return;

    DoubleNode<xType>* temp = tail;
    this->tail = tail->getPrevious();

    temp->setPrevious(nullptr);
    temp->setNext(head);
    head->setPrevious(temp);
    this->head = temp;
}


template<typename xType>
void Playlist<xType> :: display(){
    DoubleNode<xType>* curr  = head;
    while(curr){
        curr->getItem().display();
        curr = curr->getNext();
    }
}
