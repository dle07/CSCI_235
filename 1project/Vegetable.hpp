#ifndef Vegetable_
#define Vegetable_

#include "Grocery.hpp"
#include <string>


class Vegetable : public Grocery{

    public:
    Vegetable();
    Vegetable(std:: string name,double price, double weight);
    virtual void updateCost() override;

    



};






#endif