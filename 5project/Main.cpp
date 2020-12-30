
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


#include"Sorter.hpp"
#include"Sorter.cpp"
int main(){
    int arr[5] = {3, 6, 9, 10, 2};
   Sorter test(PREDETERMINED,5,arr);
   
    test.runSorts(INCREASING);
    cout<<test.getMergeCount()<<endl;

}


/*
bool binarySearch ( int target, vector<int> & input){
        int start,middle, end;
        start = 0;
        end = input.size();
        middle = (start+end)/2;
        while( start <= end){
            if( input[middle] == target)  return true;
            else if( target > input[middle]){
                start = middle +1;
                middle = (start+end)/2;
            }else {
                end = middle-1;
                middle = (start+end)/2;
            }
        }
        return false;
    }



*/