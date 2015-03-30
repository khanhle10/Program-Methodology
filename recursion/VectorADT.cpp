/*
    In this homework, you are going to implement your own version of vectors as an ADT to manage doubles using dynamic arrays. (Note that vector is implemented as a template, but you are only required to implement it as a class to manage doubles.) Specifically, your Vector_double ADT should include the following member functions:
a default constructor.
the "Big-3".
the "capacity" function: Returns the number of elements that the vector could store without allocating more storage.
the "empty" function: Tests if the vector container is empty.
the "erase" function: Removes an element or a range of elements in a vector from the specified positions.
the "insert" function: Inserts an element or a number of elements into the vector at a specified position.
the "pop_back" function: Deletes the element at the end of the vector.
the "push_back" function": Adds an element to the end of the vector.
the "resize" function: Specifies a new size for a vector.
the "shrink_to_fit" function: Discards excess capacity.
the "size" function" Returns the number of elements stored in the vector.
the overloaded output operator (<<) to output the elements in a vector.

*/
#include "VectorADT.h"
#include <vector>
#include <iostream>
VectorADT::VectorADT()
{
    size = 0;
    vect = new(10);
    //ctor
}
// one of the big 3 destructor
VectorADT::~VectorADT()
{
    //dtor
}
// big 3 copy constructor
VectorADT::VectorADT(const VectorADT& rhs)
{

}
// big 3 assignment
Vector &VectorADT::operator=(const VectorADT& rhs)
{
    this->vect = rhs.vect;
    return *this;
}
// Returns the number of elements that the vector could contain without allocating more storage
unsigned int VectorADT::capacity()
{
    int count = 0;
    for( int i = 0; i < vect.size(); i++){
        if ( vect[i] != null){
            count++;
        }
    }
    return count;
}
// Test if the vector container is empty
unsigned int VectorADT::isEmpty()
{
    return vect.empty();
}
// Inserts an element or a number of elements into the vector at a specified position
unsigned void VectorADT::insert(int position, double element)
{
    vect[position] = element;

}
// Removes an element or a range of elements in a vector from specified positions.
unsigned void VectorADT::erase(int position, double element)
{
    vect[position] = element;
}
// Deletes the element at the end of the vector.
unsigned void VectorADT::popBack()
{
    vect[size-1] = null;
}
// Add an element to the end of the vector
unsigned void VectorADT::pushBack(double element)
{
    vect[size-1] = element;
}
// Specifies a new size for a vector
unsigned void VectorADT::resize(int newSize)
{
    vector<double> temp = new(newSize);
    temp = vect;
    vect = new(newSize);
    vect = temp;
}
// Discards excess capacity.
unsigned void VectorADT::shrinkToFit()
{
    int count = 0;
    for(int i = 0; i < vect.size(); i++){
        if(vect[i] != null){
            count++;
        }
    }
    vect.resize(count);
}
// Returns the number of elements in the vector.
unsigned void VectorADT::size()
{

}
friend operator<<(ostream&, const VectorADT) const
{

}
