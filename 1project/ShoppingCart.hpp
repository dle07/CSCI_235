#ifndef ShoppingCart_
#define ShoppingCart_
#include <iostream>
#include <string>
#include "Grocery.hpp"
#include "DynamicArray.hpp"
#include <iomanip>



class ShoppingCart  : public DynamicArray <Grocery*> {
    private:
    double curr_contents_weight_;

    public:
    ShoppingCart();
    ~ShoppingCart();
    
    bool add(Grocery * new_entry);
    bool remove(Grocery * an_item);                 
    void garbageClear();
    double getCurrentWeight();
    double checkout();
};


#endif