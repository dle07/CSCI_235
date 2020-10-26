#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){


    

    
    return 0;
}

/*



    int  temp1 [200]= {
    1,2,2,2,2,
    2,2,2,2,2,
    2,2,3,4,5,
    6,7,8,9,10};     
    int item_count_ =20;  
    
    int temp2[20]={0};
    int two_size{0};
    bool toggle {true};
    for( int i=0; i< item_count_;i++){
        toggle = true;
        for( int j= 0; j< two_size;j++){
            if(temp1[i] == temp2[j] ){
                toggle =false;
                break;
            }
        }
        if( toggle){
            temp2[two_size]= temp1[i];
            two_size++;
        }
    }
    cout<<"temp2 size: "<<two_size<<endl;

    for( auto el: temp2){
        cout<<el<<endl;
    }
vector<int> myVector= {2,3,4,       //2,3,4,9,6,8,
    5,6,5
    ,5,5,5,
    5,5,1
    ,2,3,4
    ,5,6,7,
    8,9};
    for(auto it=myVector.begin(); it< myVector.end();it++){
        if(myVector[*it] ==5){
            it= myVector.erase(myVector.begin()+ *it);
        }
    }
    for(auto el: myVector){
        cout<<el<<endl;
    }

*/