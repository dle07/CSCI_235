/****************************************************************************************************************************
Title          :   Sorter.cpp
Auhor          :   Nigel Ferrer
Modified By    :   Daniel Le
Description    :   implementation file of an integer array container class that 
                   contains implementations of some sorting algorithms
Dependencies   :   Sorter.cpp
****************************************************************************************************************************/

#include "Sorter.hpp"
#include <ctime>
using namespace std;

Sorter::Sorter(array_type type, size_t array_size, int *arr) : type_(type), SIZE_(array_size), values_(arr)
{
}

/***************************s* Selection Sort ****************************/
template <typename Comparator>
int Sorter::getPosOfMinOrMax(int arr[], int from, int to, const Comparator &comp)
{
    int min_or_max = from;
    for (int i = from + 1; i <= to; i++)
    {
        if (comp(arr[i], arr[min_or_max]))
        {
            min_or_max = i;
        }
    }
    return min_or_max;
}

template <typename Comparator>
int Sorter::selectionSort(int arr[], size_t size, const Comparator &comp)
{   
    //For selction sort, we need to loop through the whole array, 
    //find the smallest element, then swap it with the 
    //current positon, we find the smallest element by using a inner loop
    int curr;
    int index;
    int temp;

    
    for( int i=0; i< size-1; i++){
        curr = arr[i];  
        index = i;
        temp = curr;
        for( int j = i+1 ; j<size ; j++){
            if (comp( arr[j] , curr) ){
                curr = arr[j];
                index = j;
            }
        }
        if( i != index){            //If a swap occurs, meaning if the index that tracks the smallest integer changes, we increment
            arr[i] = curr;
            arr[index] = temp;
            this ->  selectionCount_ ++;
        }
    }
    return selectionCount_;
}
/************************************************************************/

/**************************** Insertion Sort ****************************/
template <typename Comparator>
int Sorter::insertionSort(int arr[], size_t size, const Comparator &comp)
{
    int j;
    int curr;
    // comp(j, temp)
    //We want to increase our insertion space, thus we loop through
    for( int i = 1; i < size; i++){
        j = i;
        curr = arr[i];
        while(  j > 0 && comp(curr, arr[j-1])){ //If the comparison returns true, 
        //that means we swap it, we need to keep swapping until the newly introudced element that was added into our sorting space is in its correct spot, 
        //this shifts all the elements left of it to the right
            insertionCount_++;
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = curr;
        
    }

    return insertionCount_;

}
/************************************************************************/

// /****************************** Merge Sort ******************************/
template <typename Comparator>
void Sorter::merge(int arr[], int from, int mid, int to, const Comparator &comp)
{
    int k = 0;
    int i = from;
    int j = mid;
    //Auxillary array to store the merge sorted array
    int temp[to-from+1];
    //i< mid signifies the left side of the array, j< to signifies the right side of the arary
    while( i < mid && j <= to){
        if(comp( arr[i], arr[j] )){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
        mergeCount_++;
    }
    //If we've reached the end of one array (either the left or the right, we have to keep adding the array that we've 
    //stopped at for there might still be values, this is considered as an edge case)

    while( i < mid){
        temp[k] = arr[i];
        i++;
        k++;
        mergeCount_++;
    }
    while( j <= to){
        temp[k] = arr[j];
        j++;
        k++;
        mergeCount_++;
    }
    //Does the actual copying to the original array
    for( int a = from; a <= to ; a++){
        arr[a] = temp[a-from];
    }


}

template <typename Comparator>
int Sorter::mergeSort(int arr[], int from, int to, const Comparator &comp)
{   
    
    int middle = (from + to +1 )/2;
    if( to- from +1 <2   ) return 0;

    mergeSort(arr, from, middle-1, comp);  //mergeSort the left side
    mergeSort(arr, middle, to,comp);     // right side
    merge(arr, from, middle, to, comp);
    
    
    return this->mergeCount_;
}
// /************************************************************************/

// /****************************** Quick Sort ******************************/
/*
template <typename Comparator>
int Sorter::partition(int arr[], int from, int to, const Comparator &comp)
{
    int pvt = arr[to];
    int index = from;
    for( int i = index; i< to; i++){
        if( arr[i] <= pvt){
            int temp = arr[i];
            arr[i] = pvt;
            arr[index] = temp;
            index ++;
        }
    }
    int temp = arr[index];
    arr[index] = arr[to];
    arr[to] = temp;
    return index;
}
*/
/*
template <typename Comparator>
int Sorter::quickSort(int arr[], int from, int to, const Comparator &comp)
{
    if( from <to){
        int index = partition (arr,from, to,comp );
        quickSort(arr, from, index -1, comp);
        quickSort(arr, index +1,to, comp);
    }

    return 0;
}

*/
// /************************************************************************/

void Sorter::runSorts(sort_order order)
{

    int selectionValues[SIZE_];
    int insertionValues[SIZE_];
    int mergeValues[SIZE_];

    if (type_ == RANDOM)
    {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = rand() % 100;
            insertionValues[i] = rand() % 100;
            mergeValues[i] = rand() % 100;
        }
    }

    else
    {
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = values_[i];
            insertionValues[i] = values_[i];
            mergeValues[i] = values_[i];
        }
    }

    // Selection Sort Display
    std::cout << "******** Selection Sort ********\nOriginal Array:\n";
    displayArr(selectionValues);
    if (order == INCREASING)
    {
        selectionSort(selectionValues, SIZE_, std::less<int>());
    }
    else
    {
        selectionSort(selectionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(selectionValues);
    std::cout << "\nNumber of swaps: " << selectionCount_ << "\n********************************\n\n";

    // Insertion Sort Display
    std::cout << "\n******** Insertion Sort ********\nOriginal Array:\n";
    displayArr(insertionValues);
    if (order == INCREASING)
    {
        insertionSort(insertionValues, SIZE_, std::less<int>());
    }
    else
    {
        insertionSort(insertionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(insertionValues);
    std::cout << "\nNumber of swaps: " << insertionCount_ << "\n********************************\n\n";

    // Merge Sort Display
    std::cout << "\n********** Merge Sort **********\nOriginal Array:\n";
    displayArr(mergeValues);
    if (order == INCREASING)
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::less<int>());
    }
    else
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(mergeValues);
    std::cout << "\nNumber of comparisons: " << mergeCount_ << "\n********************************\n\n";


}

void Sorter::displayArr(const int array[]) const
{
    for (size_t i = 0; i < SIZE_; i++)
    {
        std::cout << array[i];
        (i < SIZE_ - 1) ? (cout << " ") : (cout << "\n");
    }
}