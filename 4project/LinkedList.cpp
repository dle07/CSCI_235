//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  Modified by Tiziana Ligorio & Nigel Ferrer for Hunter College CSCI 235
//  modified position s.t. 0 <= position < item_count_
//  some style modification, mainly variable names
//  added getHeadPtr()

/** ADT list: Singly linked list implementation.

 Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.hpp" // Header file
#include <iostream>
#include <cassert>

// constructor
template <class T>
LinkedList<T>::LinkedList() : head_ptr_(nullptr), item_count_(0)
{
} // end default constructor

// copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &a_list) : item_count_(a_list.item_count_)
{
   Node<T> *orig_chain_pointer = a_list.head_ptr_; // Points to nodes in original chain

   if (orig_chain_pointer == nullptr)
      head_ptr_ = nullptr; // Original list is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_pointer->getItem());

      // Copy remaining nodes
      Node<T> *new_chain_ptr = head_ptr_;                 // Points to last node in new chain
      orig_chain_pointer = orig_chain_pointer->getNext(); // Advance original-chain pointer
      while (orig_chain_pointer != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_pointer->getItem();

         // Create a new node containing the next item
         Node<T> *new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_pointer = orig_chain_pointer->getNext();
      } // end while

      new_chain_ptr->setNext(nullptr); // Flag end of chain
   }                                   // end if
} // end copy constructor

// destructor
template <class T>
LinkedList<T>::~LinkedList()
{
   clear();
} // end destructor

/**@return true if list is empty - item_count_ == 0 */
template <class T>
bool LinkedList<T>::isEmpty() const
{
   return item_count_ == 0;
} // end isEmpty

/**@return the number of items in the list - item_count_ */
template <class T>
int LinkedList<T>::getLength() const
{
   return item_count_;
} // end getLength

/**
 @pre list positions follow traditional indexing from 0 to item_count_ -1
 @param position indicating point of insertion
 @param new_entry to be inserted in list
 @post new_entry is added at position in list (the node previously at that position is now at position+1)
 @return true if valid position (0 <= position <= item_count_) */
template <class T>
bool LinkedList<T>::insert(int positions, const T &new_entry)
{
   bool able_to_insert = (positions >= 0) && (positions <= item_count_);
   if (able_to_insert)
   {
      // Create a new node containing the new entry
      Node<T> *new_node_ptr = new Node<T>(new_entry);

      // Attach new node to chain
      if (positions == 0)
      {
         // Insert new node at beginning of chain
         new_node_ptr->setNext(head_ptr_);
         head_ptr_ = new_node_ptr;
      }
      else
      {
         // Find node that will be before new node
         Node<T> *prev_ptr = getNodeAt(positions - 1);

         // Insert new node after node to which prev_ptr points
         new_node_ptr->setNext(prev_ptr->getNext());
         prev_ptr->setNext(new_node_ptr);
      } // end if

      item_count_++; // Increase count of entries
   }                 // end if

   return able_to_insert;
} // end insert

/**
 @pre list positions follow traditional indexing from 0 to item_count_ -1
 @param position indicating point of deletion
 @post node at position is deleted, if any. List order is retains
 @return true if there is a node at position to be deleted, false otherwise */
template <class T>
bool LinkedList<T>::remove(int position)
{
   bool able_to_remove = (position >= 0) && (position < item_count_);
   if (able_to_remove)
   {
      Node<T> *cur_ptr = nullptr;
      if (position == 0)
      {
         // Remove the first node in the chain
         cur_ptr = head_ptr_; // Save pointer to node
         head_ptr_ = head_ptr_->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<T> *prev_ptr = getNodeAt(position - 1);

         // Point to node to delete
         cur_ptr = prev_ptr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prev_ptr->setNext(cur_ptr->getNext());
      } // end if

      // Return node to system
      cur_ptr->setNext(nullptr);
      delete cur_ptr;
      cur_ptr = nullptr;

      item_count_--; // Decrease count of entries
   }                 // end if

   return able_to_remove;
} // end remove

/**@post the list is empty and item_count_ == 0*/
template <class T>
void LinkedList<T>::clear()
{
   while (!isEmpty())
      remove(0);
} // end clear

template <class T>
Node<T> *LinkedList<T>::getHeadPtr() const
{
   return head_ptr_;
}

/**
 @pre list positions follow traditional indexing from 0 to item_count_ -1
 @param position indicating the position of the data to be retrieved
 @return data item found at position. If position is not a valid position < item_count_
 throws  PrecondViolatedExcep */
template <class T>
T LinkedList<T>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 0) && (position < item_count_);
   if (ableToGet)
   {
      Node<T> *nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   } // end if
} // end getEntry

/************* PRIVATE METHODS ************/

// Locates a specified node in this linked list.
// @pre list positions follow traditional indexing from 0 to item_count_ -1
// @param position the index of the desired node
//       0 <= position < item_count_
// @return  A pointer to the node at the given position or nullptr if position is >= item_count_
template <class T>
Node<T> *LinkedList<T>::getNodeAt(int position) const
{
   // Count from the beginning of the chain
   Node<T> *cur_ptr = head_ptr_;
   for (int skip = 0; skip < position; skip++)
      cur_ptr = cur_ptr->getNext();

   return cur_ptr;
} // end getNodeAt





template <class T>
void LinkedList<T> :: invert(){
   this->invertRest(this->getHeadPtr());
}


/*


*/

template <class T>
void LinkedList<T> :: invertRest (Node<T>* current_first_ptr){
    
if( current_first_ptr == nullptr) return;    // if the ptr is null, return, nothing to invert

   if( current_first_ptr->getNext() == nullptr){         //same here, if the ptr->next is nullptr, return, nothing to invert, 
            head_ptr_ = current_first_ptr;            //This solves two problems, 1) an edge case (nothing to invert) 
            return;                                   //2) Exit condition for recursion
        }
    
    invertRest(current_first_ptr->getNext());         //calls itself again
    Node<T>* temp = current_first_ptr->getNext();     //Creates a reference to the next pointer
    temp->setNext(current_first_ptr);              //sets the next pointer to the itself,
    current_first_ptr->setNext(nullptr);        //sets the current pointer to nullptr, this is okay because if a pointer exists before it (Like a link from a prev pointer points to it, it will modify it's nextPtr)
                                                //It's also needed b/c we eventually need to set the tail's nextPtr to nullptr inorder to signify the end of the list
}





template <class T>
void LinkedList<T> :: rotate(int k){
   Node<T>* tempHead = this->getHeadPtr();
    if(!tempHead)return;                     //if headPtr is empty (implies list is empty) or head->next() == nullptr, rotation makes no sense, return;
    if(tempHead->getNext() == nullptr)return;

   
   Node<T>* curr = tempHead;

   int n = 0;
      while( curr ){                   //gets size of the list
            n++;
            if( curr->getNext() == nullptr)break;
            curr = curr->getNext();
            
        }                              //traverses to the end of the list
      curr->setNext(tempHead );             //set the last node's next link to the head
      k = k%n;                                   // if k>n, we should assign k to k%n b/c if it's over k>n, 
      curr = getHeadPtr();                          //we're just doing irrelevent rotations that bring us to the same point, (this is akin to terminal angles in circles)
                                                   //but we will always perform k%n b/c it'll always give us a right answer(it's safe)
        for( int i=0;i<n-k-1  ; i++){        //traverse to the approriate node where we want to break/esablish new links to correctly perform the rotation
            curr = curr ->getNext();
        }
        this->head_ptr_  = curr ->getNext();     //sets the new links
        curr->setNext(nullptr);



        
}

//  End of implementation file.
