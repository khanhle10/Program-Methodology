#ifndef POLYNOMIALADT_H
#define POLYNOMIALADT_H
#include <vector>
#include <iostream>
using namespace std;
int const maxSize = 100;
class polynomialADT
{
    public:
        polynomialADT();  // constructor
        void setDegree(int);
        double getCoefficient(int) const; // parameter and return int coefficient of power parameter
        void changeCoefficient(double newCoeffi, int power) ;    // position to change coefficient
        int getDegree() const;  // return highest power
        void print() ;   // print polynomial
        polynomialADT multPoly(int scalar);  // parameter use to increase polynomial coefficient
        polynomialADT addPoly(const polynomialADT &rightSide); //    add polynomial with the another polynomial
        polynomialADT operator+ (const polynomialADT &rightSide); // add two obects polynomial
        polynomialADT operator*(int scalar);    // multiply object by scalar
        polynomialADT operator-();  // negation by inputting negative to all coefficient
        friend ostream &operator<<(ostream &out, const polynomialADT &poly);  // print object
    private:
        int degree; // power variable
        double coeffi[maxSize];    // array of coefficient with power as index.

};
#endif // POLYNOM_H
