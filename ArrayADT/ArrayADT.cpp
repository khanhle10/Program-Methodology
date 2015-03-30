#include "ArrayADT.h"
#include <iostream>
using namespace std;
// constructor
ArrayADT::ArrayADT()
{
    size = 0;
    elementSize = 0;
    ptrAry = new double [0];
    //ctor
}
// destrcutor
ArrayADT::~ArrayADT()
{
    delete[] ptrAry;
    ptrAry = NULL;
    //dtor
}
/*
ArrayADT::ArrayADT(int input)
{
    size = input;
    elementSize = 0;
    ptrAry = new double[input];
}*/
// copy constructor
ArrayADT::ArrayADT(const ArrayADT& rhs)
{
    size = rhs.size;
    elementSize = rhs.elementSize;
    double *temp = new double[rhs.size];
    for(int i = 0; i < rhs.size; i++){
        temp[i] = rhs.ptrAry[i];
    }
    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
ArrayADT& ArrayADT::operator=(const ArrayADT & rhs)
{
    if( this == &rhs){
        return *this;
    }
    size = rhs.size;
    elementSize = rhs.elementSize;
    double *temp = new double[rhs.size];
    for(int i = 0; i < rhs.size; i++){
        temp[i] = rhs.ptrAry[i];
    }
    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
    return *this;
}

// Returns the number of elements that the vector could contain without allocating more storage
int ArrayADT::capacity()
{
    return size;    // the maxium size of the array
}
// Test if the vector container is empty
bool ArrayADT::isEmpty()
{
    if(ptrAry > NULL){
        return 1;   // true
    }else{
        return 0;   //false
    }
}   // arySize = sizeof(ptrAray)/sizeof(ptrAry[0])
// Inserts an element or a number of elements into the vector at a specified position
void ArrayADT::insert( int position, double element)
{
    reSize(size+1);
    elementSize +=1;
    double *temp = new double[size];    // temp array
    for( int i = 0; i < size; i++){
        if(i == position){
            temp[i] = element;
            i++;
        }
        temp[i] = ptrAry[i];

    }
    delete[] ptrAry;
    ptrAry = temp;  // reassign array pointer from temp array
    temp = NULL;
}
// Insert a number of elements to the ptrAry pointer
void ArrayADT::insert(double a[], int arraySize, int position)
{
    int ptrSize = size; // set ptr pointer size
    reSize(size+arraySize);
    double *temp = new double[size];
    elementSize += arraySize;
    int pos = 0;
    for(int i = 0; i < size; i++){  // 2  0 1 2<-a,3<-a,4<-a,5<-a
        if( i == (position+1)){
            for( int j = 0; j < arraySize;j++){
                temp[pos] = a[j];
                pos++;
            }
        }
        if(i < ptrSize){    // check if i is greater than the ptr point then nothing is initialized
            temp[i + pos] = ptrAry[i];
        }
     }
    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
// Removes an element or a range of elements in a vector from specified positions.
void ArrayADT::erase( int position)
{
    elementSize -=1;
    double *temp = new double[size];
    int j = 0;
    for(int i = 0; i < size; i++){
        if( i == position){
        j++;
        }
        temp[i] = ptrAry[i+j];
    }

    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
// Remove a range of element in a vector from specified position
void ArrayADT::erase(int start, int end)
{
    int count = 0;
    double *temp = new double[size];
    for(int i = 0; i < size; i++){
        if(i == start){
           count = end-i+1; ;
        }
        temp[i] = ptrAry[i+count];
    }
    elementSize = end-start;
    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
// Deletes the element at the end of the vector.
void ArrayADT::popBack()
{
    elementSize -=1;
    reSize(size-1);
    double *temp = new double[size];
    for(int i = 0; i < size; i++){
        temp[i] = ptrAry[i];
    }

    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
// Add an element to the end of the vector
void ArrayADT::pushBack(double element)
{
    double *temp = new double[size+1];
    reSize(size+1);
    elementSize +=1;
    for(int i = 0; i < size; i++){
        temp[i] = ptrAry[i];
        if(i == (size - 1)){
            temp[i] = element;
        }
    }
    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
// Specifies a new arySize for a vector
void ArrayADT::reSize(int newSize)
{
    double *temp = new double[newSize];
    size = newSize;
    for(int i = 0; i < newSize ; i++){
        temp[i] = ptrAry[i];
    }
    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
// Discards excess capacity.
void ArrayADT::shrinkToFit()
{
    double *temp = new double[elementSize];
    size = elementSize;
    for( int i = 0; i < size; i++){
        temp[i] = ptrAry[i];
    }
    delete[]ptrAry;
    ptrAry = temp;
    temp = NULL;
}
// Returns the number of elements in the vector.
int ArrayADT::arySize()
{
    return elementSize;
}
std::ostream& operator<<(std::ostream& out, const ArrayADT &rhs)
{
    out <<rhs.ptrAry[0]<<" outside\n";
    for(int i = 0; i < rhs.size ;i++){
    out << "[ "<<rhs.ptrAry[i]<<" ]";
    }
    out << "\n";
    out<< "Element Size: "<<rhs.elementSize<<endl;
    out<< "Array Size: "<< rhs.size<<endl;
    return out;
}
double ArrayADT::getElement(int index)
{
    return ptrAry[index];
}
