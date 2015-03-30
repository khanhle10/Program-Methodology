#ifndef MATRIXADT_H
#define MATRIXADT_H
#include <vector>
#include <iostream>
using namespace std;
class matrixADT
{
    public:
        matrixADT(); // default constructor
        matrixADT(int); // constructor
        int getMatrixValue(int, int) const;   // pass position
        matrixADT transpose() const;   //switch columns and rows
        int getSize() const;  // return size of matrix
        void setMatrixValue(int, int ,int); // passing value to matrix
        matrixADT operator-() const;    // negate negative to all matrix variables
        matrixADT operator* (int) const;  // scalar multiple by parameter
        matrixADT operator* (const matrixADT & rhs) const;   // matrix mult
         matrixADT operator- (const matrixADT &rhs) const;   // subtract Matrix
         friend ostream &operator<<(ostream &out, const matrixADT &rhs); // overload operator print matrix
    private:
        int size;
        vector < vector< int> > matrix;
};
#endif // 2DMATRIX_H
