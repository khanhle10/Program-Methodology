/*
    Khanh Le
    CSC 340
    2:10-3:20
Problem 2: Impleent another C++ program to sort a list of integers using the selection sort algorithm.
You are required to (1) use vector to store the input numbers typed from the keyboard; and
(2) implement a separate function called selectionSort(), where the input vector will be passed to this function by reference.
vector library
vector is a class
vector<double> vect_d(10); // declare a vector with default constructors.
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
    /*
        Pre: input vector by reference, returns vector of sorted integers in decending order.
        Function will take vector inputs and seletion sort in descending order. And return vector to main for display.
    */

vector<int> selectionSort(vector<int>& v)
{
    int tempV, min, first;
    for ( int i = v.size()-1;i > 0; i--){
        min = 0;    //0
        for ( int j = 1; j <= i; j++){
            if ( v[j] < v[min]){
                min = j;// 3
            }// if to find index of lower value
        tempV = v[min]; //86 ,3
        v[min] = v[i];  //534, 0->3
        v[i]= tempV;    //86 3-> 0
        }// loop and reassign the elements of highest to lowest value
    }
return v;
}// return vectors of sorted integers

int main()
{
vector <int> vect;
    int nums, count = 0;
    cout << "Enter 10 integers: \n";

    while (true){
        cout<< "Please Enter the number # " <<count +1<< ": ";
        while(!(cin>>nums)){
        cout<< " ERROR! Please Enter Only Numbers: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } // loop to ensure all input are integers
        vect.push_back(nums);   // pushing input to vector
        count++;
        if ( count == 10){
        break;
        } //if state to check for only 10 integers inputs
    } // end while loop
    cout << "\nList of integers: ";
    for (int i = 0; i < vect.size(); i++){
        cout << " "<< vect[i];}
    // call function to sort input integer in descending order
        selectionSort(vect);
    cout<< "\nSorted List: ";
    for (int i = 0; i < vect.size(); i++){
        cout << " " << vect[i];
        }// loop to display sorted integers in descending order
        return 0;
}// end main
/*

*/
