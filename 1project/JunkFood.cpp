#include <iostream>
#include <string>
#include "JunkFood.hpp"

JunkFood :: JunkFood  (std:: string name, double price, double weight ): Grocery(name, price, weight){          
    updateCost();   //calls updateCost upon creation
};

void JunkFood :: updateCost(){
    total_price_ = quantity_ * unit_price_;
}