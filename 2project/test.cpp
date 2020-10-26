#include <iostream>
using namespace std;



int main(){
    int myArray[20] = {2,3,4,       //2,3,4,9,6,8,
    5,6,5
    ,5,5,5,
    5,5,1               //8 fives
    ,2,3,4
    ,5,6,7,
    8,9};
    int currentSize = 20;
    int i=0;
    int count=0;
    
    for( int i=0; i< currentSize; i++)
    {   
        if(myArray[i]==5)
        {   
            if( myArray[currentSize-1]==5){--currentSize;}
            myArray[i]= myArray[currentSize-1];
            --currentSize;
        }
    }
    cout<<"Current Size :" <<currentSize<<endl;     //expects 12
    for(int i=0;i<12; i++){
        cout<<myArray[i]<<endl;
    }
    
    return 0;
}
/*should expect 
2,
3,
4
9
6



*/

