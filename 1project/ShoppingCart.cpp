#include <iostream>
#include <string>
#include "ShoppingCart.hpp"


using namespace std;


ShoppingCart :: ShoppingCart(){
    curr_contents_weight_=0;
}




ShoppingCart :: ~ShoppingCart(){
    
}



bool ShoppingCart :: add(Grocery *new_entry){
    if( curr_contents_weight_ +  new_entry ->getUnitWeight() > 350.0) {return false;}

    curr_contents_weight_ += new_entry->getUnitWeight();                //we have to ovverride the DynamicArray:: add() function
                                                                    //because we have different constraints
    
    for( int i=0; i< item_count_; i++){
        if(  *getItems()[i] == *new_entry){
             items_[i]->incrementQuantity();
            return true;
        }
    }
    
    resize();   
    this ->items_[this ->item_count_] = new_entry;              //calls resize after adding
    this ->item_count_++;
    
    return true;

   
}

 /**  
      removes the first instance of an_item from the caller; 
      if the entry already exists in the caller, decrement
      quantity_ in the object, and decrement the 
      curr_contents_weight_ of the caller by the 
      unit_weight_ of the added item.
      --> !!!THIS FUNCTION MUST CALL garbageClear()!!! <--
      @return :   true if the addition is successful            
   */

bool ShoppingCart  :: remove(Grocery * an_item){
    
    for( int i=0; i< this-> item_count_ ; i++){
        if( items_ [i] == an_item){
            items_[i]->decrementQuantity();                     //we override DynamicArray::remove() because we have diff constraints
                                                        //additional constraint is the weight constraints
            curr_contents_weight_ -= an_item->getUnitWeight();      //decrements the weight
            garbageClear();
            return true;
        }
    }
    garbageClear();                 //calls garbage clear
    return false;
}



void ShoppingCart :: garbageClear(){
    
    for( int i=0; i< item_count_; i++){
        
        if( items_[i] ->getQuantity() == 0){                //simple remove algorithm
            for( int x=i; x< item_count_ ; x++){
                    items_[x] = items_[x +1 ];
                }
                item_count_ --;
                resize();
            return;
        }
    }

}





double  ShoppingCart :: getCurrentWeight(){
    return curr_contents_weight_;
};



double ShoppingCart::checkout()
{
   if (item_count_ == 0)
   {
      std::cout << "Your cart is empty!" << std::endl;
      return 0;
   }

   double total = 0;
   for (size_t i = 0; i < item_count_; i++)
   {
      std::cout << "\n" << std::setw(10) << std::left << 
            items_[i]->getName() << "\t" << items_[i]->getQuantity() 
            << "\t" << std::fixed << std::setprecision(2) 
            << items_[i]->getTotalPrice();
      total += items_[i]->getTotalPrice();
   }
   std::cout << std::setfill('-') << std::setw(40) << "\n" 
         << std::endl << "Total:                  " 
         << total << std::endl << std::endl;
   clear();
   return total;
}