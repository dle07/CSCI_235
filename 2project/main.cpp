#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <stack>
#include <set>
#include <cctype>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "ArrayBag.hpp"
using namespace std;



int main(){
    ArrayBag<int> bag1;
    ArrayBag<int> bag2;
    for( int i=0; i< 11; i++){
        bag1.add(i);
    }
    for( int i=0; i< 11; i++){
        bag2.add(i);
    }
    bag2.add(4);
    bag2.add(11);

    if( bag1 != bag2){
        cout<< "Bags aren't equivalent True"<<endl;
        
    }else{
            cout<<"Bags are equivalent False"<<endl;
        }
    
    
    

    return 0;
}

/*


for( int i=0;i<10;i++){
        bag1.add(i);
    }
    for( int i=0; i< bag1.getCurrentSize();i++){
        std:: cout<<bag1.getItems()[i]<<std:: endl;
    }
    std ::cout<<"==============================================================================="<<std:: endl;
    
    bag2.add(2);
    bag2.add(3);
    bag2.add(4);
    bag2.add(5);

    bag1 -=bag2;
    if(bag1.contains(2) ||bag1.contains(3) || bag1.contains(4) || bag1.contains(5)  ){
        std:: cout<< "Something is wrong"<<std:: endl;
    }
    for( int i=0; i< bag1.getCurrentSize(); i++){
        std:: cout<< bag1.getItems()[i]<<std:: endl;
    }
    std:: cout<<"Everything is fine"<<std:: endl;





*/