#include <iostream>
#include "Grocery.hpp"
#include "ShoppingCart.hpp"
#include "DynamicArray.hpp"
#include "Vegetable.hpp"
#include "JunkFood.hpp"
#include "Drink.hpp"
#include <vector>

using namespace std;


int main(){
    
   DynamicArray <int> myArray;
   cout<<"Starting Capacity: " << myArray.getCapacity()<<endl;
   for( int i=0; i< 11 ; i++){
       myArray.add(i);
       cout<<"Capacity: " << myArray.getCapacity()<<endl;
   }

    myArray.remove(2);
    myArray.remove(4);
    myArray.remove(5);
    myArray.remove(3);
    myArray.remove(7);
    int * tempArray = myArray.getItems();

    for(int i=0; i< myArray.getOccupiedSpaces();i++){
        cout<< tempArray[i]<<endl;
    }

    

    
    
    


    
    return 0;
    
    }

/*
DynamicArray<int> myArray;


    int * instanceArray = myArray.getItems();
    int occupied = myArray.getOccupiedSpaces();
    int capacity = myArray.getCapacity();

    for( int i=0; i< 11; i++){
        myArray.add(i);
        cout<< myArray.getItems() [i]<<endl;
    }
    cout<<endl;
    cout<< "Number of Items :" << myArray.getOccupiedSpaces()<<endl;
    cout<<myArray.getCapacity() <<endl<<endl;;

    myArray.remove(6);
    cout<<endl<<"AFTER REMOVAL+++++++++++++++"<<endl;

    for( int i=0; i< myArray.getOccupiedSpaces(); i++){
        cout<< myArray.getItems()[i]<<endl;
    }
    cout<<"number of items:"<< myArray.getOccupiedSpaces()<<endl;




for( int i=0; i< 10; i++){
        myArray.add(i);
        cout<< "Items: "<< myArray.getOccupiedSpaces()<<endl;
        cout<< "Capacity : " <<  myArray.getCapacity()<<endl;
    }
    myArray.remove(5);
    
    for( int i=0; i< myArray.getOccupiedSpaces(); i++){
        cout<< myArray.getItems()[i]<<endl;

    }
    cout<< myArray.getCapacity();


*/