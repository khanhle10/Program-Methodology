#include "matrixADT.h"
#include <iostream>
#include <vector>
using namespace std;
/*
    Khanh Le
    CSC 340
    HW # 4
A matrix is a 2D array of numerical values. In this problem, you only need to consider
square matrices. You can add or multiply two matrices to form a third matrix provided
that the two matrices have the same size. You can multiply a matrix by a scalar, and you
can transpose a matrix. Design and implement an ADT using separate compilation to
represents a matrix that has these operations. Specifically, include the following member
functions:
! A default constructor that initializes its size to 0 by 0.
! A constructor that initializes a matrix by using values stored in a vector of vectors.
! A member function to set the number of rows and number of columns of a matrix,
then initializes all the elements to 0.
! A member function that retrieves the value at position (i, j).
! A member function that sets the value at position (i, j) to a specified value.
! A transpose function.
! An overloaded multiplication operator (*) as a member function to multiply two
matrices if their dimensionality matches.
! An overloaded multiplication operator (*) as a member function to multiply a matrix
by a scalar variable.

*/
matrixADT::matrixADT()   // default constructor
{
        matrix.resize(0);   // initialize matrix to 0
}
// initializes all element of matrix variables to 0
matrixADT::matrixADT(int dimen)
{
    matrix.resize(dimen);
    for( int i = 0; i < dimen; i++){
        for( int j = 0; j < dimen; j++){
             matrix[i].push_back(0);    // assign all value in matrix to be zero
        }
    }
    size = dimen;   // set size
}
// return size of matrix
int matrixADT::getSize() const
{
    return size;
}
// set variable to matrix by passing position of matrix
void matrixADT::setMatrixValue(int i, int j, int value)
{
    matrix[i][j] = value;   // assign value to matrix
}
// return variable of matrix
int matrixADT::getMatrixValue(int i, int j) const
{
    return matrix[i][j];    // return location of variable

}
// switch columns and rows of matrix
matrixADT matrixADT::transpose() const
{
    matrixADT copyMatrix(size); // initializes size of matrix
    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            copyMatrix.setMatrixValue(j,i, matrix[i][j]) ;  // switch rows and columns
        }
    }
    return copyMatrix;
}
// return ostream to print matrix
ostream &operator<<(ostream &out, const matrixADT &rhs)
{
    for( int i = 0; i < rhs.getSize(); i++){    // loop through vector matrix
         out << "| ";
        for (int j = 0; j < rhs.getSize(); j++){
            out<< rhs.getMatrixValue(i,j) << " | "; // output ostream with variable
            }
            out<<"\n";
    }
    return out;
}
//  return object of matrix with all negative variables
matrixADT matrixADT::operator-() const
{
    matrixADT result(size);// assign dimensions to new objects
    for( int i = 0; i < size; i++){
        for( int j = 0; j < size; j++){
        result.setMatrixValue(i,j, (-matrix[i][j]));   // assign negative value to matrix object and assign to result object
        }
    }
    return result;  // return result object
}
// return object matrix after multiplying object to scalar parameter
matrixADT matrixADT::operator* (int x)const
{
    matrixADT result(size); // assign dimensions to new object result
    for ( int i = 0; i < size; i++){
        for( int j = 0; j < size; j++){
            result.setMatrixValue(i,j,(x*matrix[i][j]));  // multiply scalar and assign to result object
            }
        }
    return result;  // return result object
}
// return object result by mutiplying object matrix with parameter object
matrixADT matrixADT::operator* (const matrixADT &rhs) const {

    int sum = 0;
    matrixADT result(size);  // assign dimensions to new object result
    if(size == rhs.size){    // checking dimensions of the two objects matrices
    for( int i = 0; i < size; i++){
        for( int j = 0; j < size; j++){
            for ( int x = 0; x < size; x++){
            sum += matrix[i][x] * rhs.getMatrixValue( x , j );  // loop through the matrix and assign to sum variable of sit row and column of matrix after multiplication
             result.setMatrixValue(i , j , sum); // pass value and position to result object
            }// exit loop
        }
   }
   }else{
   cout << "Error! Operator Mismatch Dimensions "<<endl;    // error message if two matrix operator does not match
   }
   return result;   // return result object
}// end of matrix muliply
// return object matrix result after subtracting matrix object with parameter matrix object
matrixADT matrixADT::operator- (const matrixADT &rhs) const{
    matrixADT result(size); // initialize matrix size
    if( size == rhs.getSize()){  // if statement to check dimensions of rhs matrix
        result.size = size;// assign dimensions to new object result
        for( int i = 0; i < rhs.getSize(); i ++){
            for ( int j = 0; j < rhs.getSize(); j++){
                result.setMatrixValue(i,j, matrix[i][j] - rhs.getMatrixValue(i,j));  // subtract object matrix with parameter rhs object and assign to result object
            }
        }
    }else{
        cout << "Error! Mismatch Operator Dimensions"<<endl;   // error message if two object dimensions does not match
    }
    return result;  // return object result
}// end negation matrix
