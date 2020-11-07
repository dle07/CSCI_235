#include "DoublyLinkedList.hpp"
#include <unordered_set>
#include <iostream>
using std :: cout;
using std :: endl;
using std :: unordered_set;



template<typename xType>
DoublyLinkedList<xType> ::DoublyLinkedList(){
    head_ = nullptr;
    size = 0;
}


//Copy Csontructor
template <typename xType>
DoublyLinkedList <xType> :: DoublyLinkedList(const DoublyLinkedList<xType> &target){

    this->size = target.size;
    //Traverses through calling list, stores next ptr, deletes curr, sets curr to next ptr;
    DoubleNode<xType>* curr;
    DoubleNode<xType>* rhsPtr = target.head_;
    if(rhsPtr){
        DoubleNode<xType>* temp = new DoubleNode<xType>(rhsPtr->getItem());
        head_ = temp;
        rhsPtr = rhsPtr->getNext();
        curr = temp;
    }
    while(rhsPtr){
        DoubleNode<xType>*temp = new DoubleNode<xType>(rhsPtr->getItem());
        temp->setPrevious(curr);
        curr ->setNext(temp);
        curr = temp;
        rhsPtr = rhsPtr->getNext();
    }
    
}

template <typename xType>
DoublyLinkedList<xType> ::~DoublyLinkedList(){
    DoubleNode<xType>* curr = head_;
    while( curr){
        DoubleNode<xType>* temp = curr ->getNext();
        delete curr;
        curr = temp;
    }
}



template <typename xType>
bool DoublyLinkedList<xType> :: insert(const xType &item, const int &position){
    DoubleNode<xType>* temp = new DoubleNode<xType>(item);
    if( position <=0 || position > size + 1){
        return false;
    }else if(head_ == nullptr && position == 1){
        head_= temp;
        
    }else if( position == 1 && head_ != nullptr){
        head_->setPrevious(temp);
        temp->setNext(head_);
        head_ = temp;
    }else if( position == size +1){
        DoubleNode<xType>* curr = head_;
        while( curr->getNext()){
            curr = curr ->getNext();
        }
        curr ->setNext(temp);
        temp->setPrevious(curr);
    }else{
        DoubleNode<xType>* curr = head_;
        for( int i=1; i< position; i++){
            curr = curr ->getNext();
        }
        temp->setPrevious(curr->getPrevious());
        temp->setNext(curr);
        curr->getPrevious()->setNext(temp);
        curr->setPrevious(temp);
    }


    size++;
    return true;

}

//simmilar logic to insert()
template <typename xType>
bool DoublyLinkedList<xType>::remove(const int &position){
    DoubleNode<xType>* curr = head_;
    if(position <=0 || position> size)return false;
    else if( position == 1 && head_ == nullptr){
        return false;
    }
    else if( position == 1 && head_->getNext() == nullptr){
        delete head_;
        head_ = nullptr;
    }
    else if( position == 1 && head_->getNext()){
        DoubleNode<xType>* temp = head_;
        head_ = head_->getNext();
        delete temp;
    }else{
        for( int i=1 ; i<position; i++){    
            curr= curr->getNext();
        }
        if( position==size){
            curr->getPrevious()->setNext(nullptr);
            delete curr;
        }else{
            curr->getPrevious()->setNext(curr->getNext());
            curr->getNext()->setPrevious(curr->getPrevious());
            delete curr;
        }
    }

    
    size--;
    return true;
    

}

template <typename xType>
int DoublyLinkedList<xType> :: getSize() const{
    return this->size;
}


template <typename xType>
DoubleNode<xType>* DoublyLinkedList<xType> :: getHeadPtr() const {
    return this->head_;
}

//loops through, if pos <0 or pos > size, no item exists, return nullptr, loop through, if match is found return the position
template <typename xType>
DoubleNode<xType>* DoublyLinkedList<xType>:: getAtPos( const int &pos) const{
    if( pos <=0 || pos > size ) return nullptr;
    DoubleNode<xType>* curr = head_;
    for( int i=1; i<pos; i++){
        curr = curr->getNext();
    }
    return curr;
}


template <typename xType>
bool DoublyLinkedList<xType> :: isEmpty() const{
    return size == 0? true: false;

}

//Traverse through whole list, keep track of next pointer, delete current pointer, set curr = temp
template <typename xType>
void DoublyLinkedList<xType> :: clear(){
    size = 0;
    DoubleNode<xType>* curr  = this->head_;
    while( curr){
        DoubleNode<xType>* temp = curr->getNext();
        delete curr;
        curr = temp;
    }
    head_ = nullptr;
}

//Set index as 1, traverse through entire list, if data == item, return index, else index ++, if loop ends, no match found, return -1
template <typename xType>
int DoublyLinkedList<xType> :: getIndexOf( const xType & item) const{
    DoubleNode<xType>* curr = head_;
    int index = 1;
    while( curr){
        if( curr ->getItem() == item){
            return index;
        }else{
            index++;
            curr = curr->getNext();
        }
    }
    return -1;
}

//Traverse and print every item along the way
template <typename xType>
void DoublyLinkedList<xType> :: display() const{
    DoubleNode<xType>* curr = this->head_;
    while(curr){
        std :: cout<<curr->getItem();
        curr = curr->getNext();
        if( curr) cout<<" ";
    }
    cout<<endl;
}

//Traverse to the last node, go backwards and print every item on the way
template <typename xType>
void DoublyLinkedList<xType> :: displayBackwards() const {
    DoubleNode<xType>* curr = head_;
    while(curr && curr->getNext()){
        curr = curr->getNext();
    }
    while(curr){
        std :: cout<<curr->getItem();
        curr = curr->getPrevious();
        if( curr)cout<<" ";
    }
    std::cout<<std::endl;
}

/*
Bonus Feature
Define the calling list as a set of ordered nodes, $L1 = {4, 2, 8 ,5, 8}$, and define the list that is passed as a parameter as a set 
of ordered nodes, $L2 = {5, 1, 8, 4, 5, 9}$. L1.interleave(L2) yields the set ${4, 5, 2, 1, 8, 8, 5, 4, 8, 5, 9}$. In other words,
to create the interleaved list, first add a node from L1, then one from L2, and then repeat as many times as necessary.
If there are any nodes left over in L1 or L2 exclusively, append them to the end of the list.

{4, 2, 8 ,5, 8}
{5, 1, 8, 4, 5, 9}
{4, 5, 2, 1, 8, 8, 5, 4, 8, 5, 9}
*/
template <typename xType>
DoublyLinkedList<xType> DoublyLinkedList<xType> :: interleave( 
    const DoublyLinkedList<xType> & a_list){
        
        DoublyLinkedList<xType> result;
        result.size = this->size + a_list.size;
        DoubleNode<xType>* curr;

        DoubleNode<xType>* first = this ->head_;
        DoubleNode<xType>* second = a_list.head_;
        // Checks to see if either one of the lists given is empty or not, assigns the
        //head pointer of result to the first non null head we see
        if( first){
            DoubleNode<xType>* temp = new DoubleNode<xType>(first->getItem());
            result.head_ = temp;
            curr = temp;
            first = first->getNext();
            
        }else if( second ){
            DoubleNode<xType> * temp = new DoubleNode<xType>( second -> getItem());
            result.head_ = temp;
            curr = temp;
            second = second->getNext();

        }
        //In order to be consistent with the swapping pattern we need to check to see if the paramater list has a node,
        //then add that node to our result, and assign prev to that node
        if( second){
            DoubleNode<xType> * temp = new DoubleNode<xType>(second->getItem());
            curr->setNext(temp);
            temp->setPrevious(curr);
            curr = temp;
            second = second ->getNext();
        }
        
        while(first || second){
            if(first)
            {
                DoubleNode<xType>* temp = new DoubleNode<xType>(first->getItem());
                curr->setNext(temp);
                temp->setPrevious(curr);
                curr = temp;
                first = first->getNext();
            }
            if(second)
            { 
                DoubleNode<xType>* temp = new DoubleNode<xType>(second ->getItem());
                curr->setNext(temp);
                temp->setPrevious(curr);
                curr = temp;
                second = second->getNext(); 
            }
        }


        return result;
        
}
