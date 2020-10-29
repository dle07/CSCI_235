#include "Playlist.hpp"


#include <unordered_set>
#include <string>
using std :: string;
using std :: unordered_set;
Playlist ::Playlist():DoublyLinkedList(){

}


double Playlist :: getTotalTime() const{
    double result = 0;
    DoubleNode<PlaylistItem*>* curr = head_;
    while(curr){
        result += curr->getItem()->getLength();
        curr = curr->getNext();
    }
    return result;

}

//Two cases, where calling list is empty, and second case, where its not empty;
void Playlist :: operator +=(Playlist rhs){
    this->size += rhs.size;
    DoubleNode<PlaylistItem*>* rhsPtr = rhs.head_;
    DoubleNode<PlaylistItem*>* curr = head_;
    if( curr == nullptr){
        DoubleNode<PlaylistItem*>* temp = new DoubleNode<PlaylistItem*>(rhsPtr->getItem());
        head_=temp;
        curr=temp;
        rhsPtr = rhsPtr->getNext();
        while(rhsPtr){
            DoubleNode<PlaylistItem*>* temp = new DoubleNode<PlaylistItem*>(rhsPtr->getItem());
            curr->setNext(temp);
            temp->setPrevious(curr);
            curr = temp;
            rhsPtr = rhsPtr->getNext();
            
        }
    }
    else    //Case 2) Calling list is not empty;
    {
        while(curr->getNext()){
            curr = curr ->getNext();
        }

        while( rhsPtr ){
            DoubleNode<PlaylistItem*>* temp = new DoubleNode<PlaylistItem*>(rhsPtr->getItem());
            curr->setNext(temp);
            temp->setPrevious(curr);
            curr = temp;
            rhsPtr = rhsPtr->getNext();
        }
    }
}

void Playlist :: operator -=(Playlist rhs){
    /*
    unordered_set<std::string> mySet;
    DoubleNode<PlaylistItem*>* curr = rhs.head_;
    while(curr){
        mySet.insert(curr->getItem()->getTitle());
    }
    curr = this->head_;
    while(curr){
        if( mySet.count(curr ->getItem()->getTitle())){

            if( curr==head_ && head_->getNext()==nullptr){
                delete head_;
                head_ = nullptr;
            }else if( curr ==head_ && head_->getNext()){
                DoubleNode<PlaylistItem*>* temp = head_;
                head_->getNext()->setPrevious(nullptr);
                head_ = head_->getNext();
                delete temp;
            }else if( curr->getNext()==nullptr){
                curr->getPrevious()->setNext(nullptr);
                delete curr;
            }else{
                curr->getPrevious()->setNext(curr->getNext());
                curr->getNext()->setPrevious(curr->getNext());
                delete curr;
            }
            size--;
        }
    } */
    return ;

}
    

void Playlist ::skip(){
    if(head_->getNext() == nullptr || head_ == nullptr) return;
    DoubleNode<PlaylistItem*>* temp = head_;
    DoubleNode<PlaylistItem*>* curr =head_;
    while(curr->getNext()){
        curr= curr->getNext();
    }
    head_ = head_->getNext();
    head_->setPrevious(nullptr);

    temp->setNext(nullptr);
    curr->setNext(temp);
    temp->setPrevious(temp);
    

}
void Playlist :: rewind(){
    if(head_->getNext() == nullptr || head_ == nullptr) return;
    DoubleNode<PlaylistItem*>* curr =head_;
    while( curr->getNext()){
        curr = curr->getNext();
    }
    curr->getPrevious()->setNext(nullptr);
    curr->setPrevious(nullptr);
    curr->setNext(head_);
    head_->setPrevious(curr);
    head_ = curr;
}

void Playlist ::display(){
    DoubleNode<PlaylistItem*>* curr = head_;
    while(curr){
        curr->getItem()->display();
        curr =curr->getNext();
    }
}