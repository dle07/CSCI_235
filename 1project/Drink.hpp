#ifndef Drink_
#define Drink_

#include "Grocery.hpp"
#include <string>

class Drink : public Grocery{
    public:
    Drink();
    Drink (std:: string name, double price, double weight );        
    virtual void updateCost() override;

};






#endif