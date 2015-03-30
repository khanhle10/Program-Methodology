
#include "recursionADT.h"
#include <iostream>
using namespace std;
/*
    A default constructor that initializes all the elements in this array to 0.

*/
recursionADT::recursionADT()
{
    size = 0;
    ary[0];
    index = 0;
    //ctor
}
/*
    initalize array size
*/
void recursionADT::setArraySize(int input)
{
    size = input;
}
/*
    accessor get size of array
*/
int recursionADT::getSize() const
{
    return size;
}
/*
    mutator set array elements
*/
void recursionADT::setElements(int index, int input)
{
    ary[index] = input;
}
/*
    accessor to get elememt of Array
*/
int recursionADT::getElementArray(int index) const
{
    return ary[index];

}
/*
    pass index variables for input
*/
void recursionADT::setIndex(int n)
{
    index = n;
}

int recursionADT::passIndex() const
{
    return index;
}
/*
    A member function that asks an end user to provide a list of integers from the keyboard and stores
    these numbers into the fixed-size array.
*/
void recursionADT::promptInput()
{
    int enter;
    int tempSize = size;
   for( int i = 0; i < tempSize; i++){
    cout<< "Please Enter A Value: ";
        while(!(cin >> enter)){
            cin.clear();
            cout<< "Error!\nPlease Re-enter A Value:  ";
        }
        ary[i] = enter;
    }
    size = tempSize;
}
/*
    A member function that recursively prints out the array in reverse order.
    For example, if the array contains the number 4, 19, and 17. Your function will print out: 17, 19, 4.

*/
void recursionADT::printReverseArray(int n)
{
    n = n-1;
    if(n < 0){
      cout<< "\nEnd of Array."<<endl;
    }else{
        cout<< " "<< ary[n];
        printReverseArray(n);
    }
}
/*
    A member function that recursively searches the largest number in the array.
    This function will return not only the value of the largest number but also its index in the array.
*/
void recursionADT::searchLargest(int &value, int &index)
{
    if(index >= size){
        cout<<"End of Search "<<passIndex()<< endl;
        index = passIndex();
    }else{
        if( ary[index] > value){
            value = ary[index];
            setIndex(index);
            index++;
            searchLargest(value, index);
        }else {
         index++;
         searchLargest(value, index);
        }
        }
}
/*
    A member function that recursively finds the k-th largest number in the array,
    where k is provided by the end-user.
*/
int recursionADT::searchLargestK(int k, int first, int last)
{
    int pivotIndex;
    int tempSize = size;
    int rank;
    if( k < 1 || k > tempSize){
        return -1;
    }else if(first == last){
        return ary[first];
    }
        pivotIndex = partition(first, last);
        rank = pivotIndex- first+1;
        if(rank == k){
            return ary[pivotIndex];
        }else if(k < rank){
            return searchLargestK( k ,first, pivotIndex-1);
        }else {
            return searchLargestK( k - rank, pivotIndex+1, last);
        }
        size = tempSize;
}
/*
    Partition to of Array
*/
int recursionADT::partition(int first, int last)
{
    int temp;
    int pivotIndex = ary[last];
    while (first < last){
        while(ary[first]< pivotIndex){
            first++;
        }
        while(ary[last]> pivotIndex){
            last--;
        }
        if(ary[first] == ary[last]){
            pivotIndex++;
        }else if(first < last){
            temp = ary[first];
            ary[first] = ary[last];
            ary[last] = temp;
        }
    }
    return last;
}
/*
Optional:A member function that implements the QuickSort algorithm to sort the array in increasing order.
*/

void recursionADT::quickSort(int first, int last)
{
    int mid;
    if( first < last){
        mid = partition(first, last);
        quickSort(first, mid-1);
        quickSort(mid+1, last);
    }
}
/*
Optional:An overloaded put operator (<<) to recursively print out the elements in the array in order.
*/
std::ostream &operator<<(std::ostream &out, const recursionADT &recur)  // print object
{
    int num;
    if( recur.getSize() == 0){
        out<< "Error!\nEmpty Array\n";
        return out;
    }
    if(recur.passIndex() < recur.getSize()){
        out <<recur.getElementArray(recur.passIndex())<< " ";
        num = recur.passIndex();  // incrementing index
        num++;
    //    recur.setIndex(num);    // set new index
        out<<recur; // recursion ostream
    }
     return out;    // return out
}
