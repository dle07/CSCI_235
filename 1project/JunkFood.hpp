#ifndef JunkFood_
#define JunkFood_

#include "Grocery.hpp"
#include <string>

class JunkFood : public Grocery{
    public:
    JunkFood();
    JunkFood(std:: string name,double price, double weight );
    virtual void updateCost() override;

};






#endif