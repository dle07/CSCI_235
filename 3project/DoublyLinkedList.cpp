#include "DoublyLinkedList.hpp"

/*
    Project 3
    Author: Daniel Le
    DoublyLinkedList Implementation Project

*/

/*
Creates a Deep copy of a DoublyLinkedList by looping through the given List

*/
//Default no-args constructor
template<typename xType>
DoublyLinkedList <xType> :: DoublyLinkedList():
head(nullptr),tail(nullptr), itemCount(0){
    
}

/** Deep Copy Constructor */
template <typename xType>
DoublyLinkedList <xType> :: DoublyLinkedList(const DoublyLinkedList<xType> &target){
this->itemCount = target.itemCount;
// Case 1) Copy List has 0 items
if( target.head == nullptr){
    head = nullptr;
    tail = nullptr;
    return;
}
//creates a node on, head is set to that node
head = new DoubleNode<xType>(target.head->getItem());
//Case 2) Copy List has only 1 item
//Checks to see if the List has only one node, if so, set the tail to the head,return;
if( target.head->getNext == nullptr ){
    tail = head;
    return;
}
/* Case 3) Copy List's itemCount >1
    */
DoubleNode <xType> * prev=head;
DoubleNode <xType> * currOriginalPtr=target.head;
    while(currOriginalPtr->getNext()){
        //Creates a new DoubleNode, advances the next node, 
        currOriginalPtr = currOriginalPtr->getNext();
        DoubleNode<xType> temp = new DoubleNode<xType>(currOriginalPtr->getItem());
        temp.setPrevious(prev);
        prev ->setNext(temp);
        prev = prev->getNext();

    }
    tail=currOriginalPtr;
}

/** Destructor To clear up memory once a DoublyLinkedList goes out of scope */
template <typename xType>
DoublyLinkedList <xType> :: ~DoublyLinkedList(){
    // No need to check for these conditions as the loop takes care of these cases
    /* if(itemCount == 0 ) return;
    if(itemCount == 1 ) { delete head; return;}  */
    //Loop through List, deleting each node
    DoubleNode<xType>* curr = head;
    while(curr){
        DoubleNode<xType>* tempNext = curr->getNext();
        delete curr;
        curr = tempNext;
    }
}

//Insert has quite the number of edge cases, be wary young one.
template<typename xType>
bool DoublyLinkedList <xType> :: insert(const xType &item, const int &position){

    //No position exists, return false
    if(position > itemCount+1 || position <=0 )return false;
    //Edge Case 1) Where the insertion node is at the beginning and the position is at 1, no need to check for positoin ==1, as it's implied by out first if statement above
    else if( head == nullptr ){
        head = new DoubleNode<xType>(item);
        tail = head;
    }
    //Edge Case 1) If the insertion position is at the beginning, creates a pointer to the head node, sets the head to a newly created DoubleNode, sets head-> next to the temp, and finally established the link by setting temp's prev to the head
    else if( position ==1 ){
        DoubleNode<xType>* temp = head;
        head= new DoubleNode<xType>(item);
        head->setNext(temp);
        temp->setPrevious(head);
    }
    //Edge case 2) If the insertion position is at the very end of the list, traverse to the last node, create a new node, set the last node's next field to the address of the newly created node, set the newly created node's prev field to the curr node, set tail  to the newly created node
    else if(position == itemCount +1){
        DoubleNode <xType> * curr = head;
        // To traverse to the end, we can do the classic while(curr->getNext()) method, or we can use a for loop, for( int i=1; i<itemCount; i++){ curr = curr->getNext();}
        while(curr->getNext()){
            curr = curr->getNext();
        }
        DoubleNode<xType>* temp = new DoubleNode<xType>(item);
        curr->setNext(temp);
        temp->setPrevious(curr);
        tail=temp;
    }
    //Majority of the case, where the insertion position is between two adjacent DoubleNodes
    else{
        DoubleNode <xType>* curr = head;
        for( int i = 1; i< position; i++){
        curr = curr->getNext();
        }
        DoubleNode<xType> temp = new DoubleNode<xType>(item);
        temp->setPrevious(curr->getPrevious());
        temp->setNext(curr->getNext());
        curr->getPrevious()->setNext(temp);
        curr->getNext()->setPrevious(temp);
    }
    itemCount ++;
    return true;

};


//Same logic as insert(), except we're removing
template <typename xType>
bool DoublyLinkedList <xType> :: remove(const int &position){
    //No such DoubleNode exists in the List, return false immediately
    if( position <0 || position > this-> itemCount) return false;
    else if( position == 1){
        if( head-> getNext() == nullptr){
            delete head;
            head == nullptr;
            tail == nullptr;
        }else{
            head->getNext()->setPrevious(nullptr);
            delete head;
        }
    }
    else if(position == itemCount){
        DoubleNode<xType>* curr = head;
        while(curr->getNext()){
            curr=curr->getNext();
            curr->getPrevious()->setNext(nullptr);
            tail = curr->getPrevious();
            delete curr;
        }
    }else{
        DoubleNode<xType>* curr = head;
        for(int i=1; i< position ;i++){
            curr = curr->getNext();
            curr->getPrevious()->setNext(curr->getNext());
            curr->getNext()->setPrevious(curr->getPrevious());
            delete curr;
        }
    }
    
    itemCount --;
    return true;
}


template <typename xType>
int DoublyLinkedList<xType> :: getSize() const{
    return this->itemCount;
}

template <typename xType>
DoubleNode<xType>* DoublyLinkedList<xType> :: getHeadPtr() const{
    return this->head;
}

template <typename xType>
DoubleNode<xType>* DoublyLinkedList<xType> :: getAtPos(const int &pos) const{
    DoubleNode<xType>* curr = head;
    if( pos <0 || pos > itemCount){
        return head;
    }
    for( int i=1; i< pos; i++){
        curr = curr->getNext();
    }
    return curr;
}

template <typename xType>
bool DoublyLinkedList<xType> :: isEmpty() const{
    return itemCount > 0 ? false :true ;
}

template <typename xType>
void DoublyLinkedList<xType> :: clear(){

}

template <typename xType>
int DoublyLinkedList<xType> :: getIndexOf(const xType & item) const{
    DoubleNode<xType>* curr= head;
    int index = 1;
    if( head ==nullptr) return -1;
    while( curr->getNext()){
        if( curr->getItem() == item){
            return index;
        }
        curr = curr->getNext();
        index ++;
    }
    return -1;
}

template <typename xType>
void DoublyLinkedList<xType> ::display() const{
    
        DoubleNode<xType>* curr = head;
        while( curr){
            cout<<curr->getItem()<<endl;
            curr = curr->getNext();
        }

   

}

template <typename xType>
void DoublyLinkedList<xType> :: displayBackwards() const{
    vector <xType> myVector;
    DoubleNode <xType>* curr = head;
    while( curr){
        myVector.push_back(curr->getItem());
        curr = curr->getNext();
    }
    for( int i= myVector.size()-1; i >=0; i++){
        cout<< myVector[i]<<endl;
    }
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
        
        DoublyLinkedList<xType> result();
        
        DoubleNode<xType>* curr;

        DoubleNode<xType>* first = this ->head;
        DoubleNode<xType>* second = a_list.getHeadPtr();
        // Checks to see if either one of the lists given is empty or not, assigns the
        //head pointer of result to the first non null head we see
        if( first !=NULL){
            DoubleNode<xType> * temp = new DoubleNode(this->head->getItem());
            result.setHeadPtr(temp);
            curr = temp;
            first = this -> head ->getNext();
            
        }else if( second != NULL){
            DoubleNode<xType> * temp = new DoubleNode(a_list ->getHeadPtr() -> getItem());
            result.setHeadPtr(temp);
            curr = temp;
            second = second->getNext();

        }
        //In order to be consistent with the swapping pattern we need to check to see if the paramater list has a node,
        //then add that node to our result, and assign prev to that node
        if( second != nullptr){
            DoubleNode<xType> * temp = new DoubleNode(second->getItem());
            curr->setNext(temp);
            temp->setPrevious(curr);
            curr = temp;
            second = second ->getNext();
        }
        
        while(first || second){
            if(first)
            {
                DoubleNode<xType>* temp = new DoubleNode(first->getItem());
                curr->setNext(temp);
                temp->setPrevious(curr);
                curr = temp;
                first = first->getNext();
            }
            if(second)
            { 
                DoubleNode<xType>* temp = new DoubleNode(second ->getItem());
                curr->setNext(temp);
                temp->setPrevious(curr);
                curr = temp;
                second = second->getNext(); 
            }
        }
        result.setSize(this->itemCount + a_list.itemCount);
        result.setTailPtr(curr);
        return result;
}



template <typename xType>
void DoublyLinkedList<xType> :: setHeadPtr(DoubleNode<xType>* node){
    this-> head = node;

}


template <typename xType>
void DoublyLinkedList<xType> :: setTailPtr(DoubleNode<xType>* node){
    this-> tail = node;
}




template <typename xType>
void DoublyLinkedList<xType> :: setSize( int val){
    this->itemCount = val;
}
