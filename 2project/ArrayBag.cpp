#include "ArrayBag.hpp"
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;



template <typename ItemType>
int ArrayBag<ItemType> :: getIndexOf ( const ItemType & target) const
{
                                                //O(n)
    for( int i=0; i< item_count_; i++){         //loops through, returns index if found
        if( items_[i] == target) return i;
    }
    return -1;          //returns -1 by default, signifes target isn't in bag

}

template <typename ItemType>
ArrayBag<ItemType>::ArrayBag():item_count_(0)
{      //constructor , sets item_count_ to 0 as the bag is now empty

}
template <typename ItemType>
int ArrayBag<ItemType> :: getCurrentSize() const
{
    return this -> item_count_;
}

template <typename ItemType>
bool ArrayBag<ItemType> :: isEmpty() const
{
    if(item_count_ > 0 )return false;     //if item_count_ is greater than 0, return true, else return false by default
    return true;                   //O(1)
}

template <typename ItemType>
bool ArrayBag<ItemType> :: add(const ItemType & new_entry)
{
    if( item_count_ <=200){     //item_count_ signifes the location of next element if item_count_ is greater than 200, we can't add an item, thus return false
        items_[item_count_] = new_entry;    //O(1)
        item_count_ ++;
        return true;
    }
    return false;
}

template <typename ItemType>
bool ArrayBag<ItemType> :: remove(const ItemType &an_entry)
{
    for( int i=0; i< item_count_; i++){ //O(n)
        if( items_[i] == an_entry){     //Removal is only possible if target item is found in the bag, if found we override its value with the last item in our bag and decremet item_count_ by one, this is valid because order doesn't matter.
                                        //This is is faster than if order did matter
            items_[i] = items_[item_count_-1];
            item_count_--;
            return true;
        }
    }
    return false;
}

template <typename ItemType>            //O(1)
void ArrayBag<ItemType> :: clear()      //setting item_count_ to 0 effectively clears the bag because item_count_ marks the boundary between useful items and irrelevent garbage data
{
    item_count_=0;
}


template <typename ItemType>
bool ArrayBag<ItemType> :: contains(const ItemType &an_entry) const
{
    for( int i=0; i< item_count_; i++){                //O(n)
        if( items_[i] == an_entry)return true;      //simple looping to find target element
    }
    return false;

}

template <typename ItemType>
int ArrayBag<ItemType> :: getFrequencyOf (const ItemType &an_entry )const
{                                   //O(n)
    int result{0};                  //stores counter variable, set to 0, loops through bag, if item is found, increment result, return result when loop ends
    for( int i=0; i < item_count_; i++){
        if( items_[i] == an_entry)result++;
    }
    return result;
}


template <typename ItemType>
void ArrayBag<ItemType> :: operator+=(const ArrayBag<ItemType> & a_bag)
{
    
    unordered_set< ItemType > mySet;            //use a set to keep track of elements we've already added
    for( auto el: items_){
        mySet.insert(el);
    }

    for(int i=0; i< a_bag.item_count_ ; i++){
        if( item_count_>200)break;                      //if bag is at capacity we break
        if( mySet.count(a_bag.items_[i] ) ){        //if we've already added that item to the bag we continue
            continue;
        }
        items_[item_count_] = a_bag.items_[i] ;
        item_count_ ++;
    }
        



}

template <typename ItemType>
void ArrayBag <ItemType> :: operator -=(const ArrayBag<ItemType> &a_bag)
{
   
    
    //A faster algorithmn can be achieved at the expense of O(m) memory, the algorithm would take O(n*log(m) + a_bag.item_count ) => O(nlog(a_bag.item_count)) time which is faster through the use of a data structure called a set
    //#include <unordered_set>   // we'll use unordered_set because order does not matter, this set also only takes unique values 
    unordered_set <ItemType> mySet; 
    for( int i=0; i< a_bag.item_count_; i++){

        mySet.insert(a_bag.items_[i]);
    }
    for( int i=0; i< this->item_count_; i++){
        if( mySet.count(items_[i])){
            items_[i] = items_[item_count_-1];
            item_count_--;
        }
    }
    
    
  

}


template <typename ItemType>
void ArrayBag<ItemType> ::  operator/=(const ArrayBag<ItemType> &a_bag)
{
    unordered_set<ItemType> setOne;    //uses unordered sets to keep track of unique instances, this of course can be done with arrays but using unordered_sets is more efficent in terms of look up and matching
    unordered_set <ItemType> setTwo;
    for(int i=0; i< item_count_; i++){
        setOne.insert(items_[i]);
    }
    for( int i=0; i< a_bag.getCurrentSize(); i++ ){
        setTwo.insert(a_bag.items_[i]);
    }
    item_count_= 0;
    for(auto it = setOne.begin(); it != setOne.end() ; it++){
        if( setTwo.count(*it)){
            items_[item_count_] = *it;
            item_count_++;
        }
    }
    

}

template <typename ItemType>
bool ArrayBag<ItemType> :: operator==(const ArrayBag<ItemType> &a_bag){
    if( this -> item_count_ != a_bag.item_count_) return false;
    unordered_set<ItemType> setOne;    //uses unordered sets to keep track of unique instances, this of course can be done with arrays but using unordered_sets is more efficent in terms of look up and matching
    unordered_set <ItemType> setTwo;

    for(int i=0; i< item_count_; i++){      //inserts into each set
        setOne.insert(items_[i]);
    }
    for( int i=0; i< a_bag.getCurrentSize(); i++ ){
        setTwo.insert(a_bag.items_[i]);
    }

    if( setOne.size() != setTwo.size()) return false;  //if the sizes of each set aren't equivalent this signifies that there can't be a one to one mapping for each element thus we can save our time looping and comparing each element in one set and return false
    
    for( auto el: setOne){
        if(! setTwo.count(el)){     //loops to see if each set truly is one to one
            return false;
        }
    }


    return true;
}


    template <typename ItemType> 
    bool ArrayBag<ItemType>  :: operator!=(const ArrayBag<ItemType> &a_bag)
    {
    
    unordered_set<ItemType> setOne;    //uses unordered sets to keep track of unique instances, this of course can be done with arrays but using unordered_sets is more efficent in terms of look up and matching
    unordered_set <ItemType> setTwo;
    for(int i=0; i< item_count_; i++){      
        setOne.insert(items_[i]);
    }
    for( int i=0; i< a_bag.getCurrentSize(); i++ ){
        setTwo.insert(a_bag.items_[i]);
    }
    if( setOne.size() != setTwo.size()) return true;    // if sizes are different, a onto one to one mapping is impossible

    for( auto el: setOne){
        if(! setTwo.count(el)){     //loops to see if each set truly is one to one
            return true;
        }
    }

    return false;



    }
    


/*
Set Intersection
ItemType [200] temp1;       
    ItemType [200] temp2;
    ItemType [200] temp3;       
    int one_temp_count{0};
    int two_temp_count{0}; 
    int three_temp_count{0};
    bool toggle {true};
    //filters first array storing unqiue elements in an temp array, temp1
    for( int i=0; i< item_count_ ; i++){
        toggle = true;
        for( int j=0; j< one_temp_count; j++ ){
            if( items_[i] == temp1[j]){
                toggle=false;
                break;
            }
        }
        if( toggle) {
            temp1[one_temp_count] = items_[i];
            one_temp_count++;
        }
    }

    for( int i=0; i< a_bag.item_count_ ; i++){
        toggle = true;
        for( int j=0; j< two_temp_count; j++ ){
            if( a_bag.items_[i] == temp2[j]){
                toggle=false;
                break;
            }
        }
        if( toggle) {
            temp2[two_temp_count] = a_bag.items_[i];
            two_temp_count++;
        }
    }

    for( int i=0; i< one_temp_count; i++){
        for( int j = 0; j< three_temp_count; j++){
            if( temp1[i] == temp2 [j] ){
                temp3[three_temp_count] = temp1[i];
                three_temp_count++;
            }
        }
    }
*/



/*
for( int i=0; i< item_count_ ;i++){
        toggle =true;
        for(int j=0; j< a_bag.item_count_ ;j++){
            if( items_[i] == a_bag.items_[j]){
                toggle = false;
                break;
            }
        }
        if( toggle){
        this -> items_[i] = items_[item_count_ -1] ;
        item_count_ --;
        }
    }

*/