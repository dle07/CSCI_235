#include <iostream>
#include "Vegetable.hpp"
#include <string>





Vegetable :: Vegetable(std :: string name, double price, double weight): Grocery(name,price,weight){
    this -> updateCost();           //calls updateCost upon creation
}
void Vegetable :: updateCost(){
    total_price_ = quantity_ * unit_weight_ * unit_price_;
}

