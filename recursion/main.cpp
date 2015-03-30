/*
    Khanh Le
    CSC 340 HW #7
A default constructor that initializes all the elements in this array to 0.
A member function that asks an end user to provide a list of integers from the keyboard and stores these numbers into the fixed-size array.
A member function that recursively prints out the array in reverse order. For example, if the array contains the number 4, 19, and 17. Your function will print out: 17, 19, 4.
A member function that recursively searches the largest number in the array. This function will return not only the value of the largest number but also its index in the array.
A member function that recursively finds the k-th largest number in the array, where k is provided by the end-user.
Optional:A member function that implements the QuickSort algorithm to sort the array in increasing order.
Optional:An overloaded put operator (<<) to recursively print out the elements in the array in order.
*/
#include "recursionADT.h"
#include <iostream>

using namespace std;

int main()
{
    int input;
    int i = 0;
    int value = 0;
    recursionADT recur;
    cout << "Hello world!" << endl;
    cout << "Please Enter The Array Size: ";    // prompt for input size of array
    while(! (cin >> input )){
        cin.clear();
        cout<< "Please Enter The Array Size: ";
    }   // check for correct input
     // initialize object
    recur.setArraySize(input);  // initialize the array and size
    recur.promptInput();    // prompt for input elements
    cout<<"Print Array: ";
    for( int j = 0; j < recur.getSize();j++){
    cout<<recur.getElementArray(j)<<" ";
    }
    cout<<"\nPrint Reverse: ";
    recur.printReverseArray(recur.getSize());   //print array in reverse
    input = 0;  // reset input
    recur.searchLargest(value, input);  // pass by reference value and input to search for largest value in array
    cout << "Value: "<< value <<" Index: "<<input<<endl;    //displace value and input
    while(true){
        cout << "Please Enter The Kth Value: "; // prmpt for input kth value
    while(!(cin >> input)){
        cin.clear();
        cout << "Error!\nPlease Enter The Kth Value: ";
    }// check input
     if(input >= 0 && input < recur.getSize()){
        value = recur.searchLargestK(input, 0, recur.getSize()); // assign the largest kth value
        cout<< input<<"^th Value: "<<value<<endl;
        break;
     }
     cout<<"Error!\nK^th Value must be less than Array Size of "<<recur.getSize()<<endl;
    }   // end loop to search for largest k^th value
    recur.quickSort(0, recur.getSize());
    cout<<"Array Value After Sort: ";
    while (i < recur.getSize()){
     cout<<recur.getElementArray(i)<<" ";
    i++;
    }
    recur.setIndex(0);
   // cout<<"Print Array: "<<(recur);
    return 0;
}
