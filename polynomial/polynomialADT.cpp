#include "polynomialADT.h"
#include <iostream>
#include <vector>
using namespace std;
// defalut constructor initializing all elements to 0
polynomialADT::polynomialADT()
{
    for( int i = 0; i < maxSize; i++){
    coeffi[i] = 0.0;
    }
    degree = -1;
    //ctor
}
void polynomialADT::setDegree(int power)
{
    degree = power;
}
// return degree as an assessor
int polynomialADT::getDegree() const{
    return degree;
}
// taking 2 parameter and updating coefficient using the index of the array as power and element as coefficient
void polynomialADT::changeCoefficient(double newCoeffi, int power )
{
    coeffi[power] = newCoeffi;
}
// return an int coefficient of a power parameter that points to the index of the array
double polynomialADT::getCoefficient(int power) const
{
    if ( power <= degree ){
        return coeffi[power];
    }else {
        return 0;
    }
}
//
// print out polynomial using cout looping through array
void polynomialADT::print()
{
    int i = 0;
    while(i < degree ){
        if( coeffi[i] != 0){
        cout<< coeffi[i] << "x^"<<i << " + ";
        }   // only print coefficients and powers of elements that does not contain 0
        i++;
    }   // loop through array of coefficient
    cout << coeffi[degree]<< "x^"<<degree<< endl;  // print at the end of the array with the highest co
}

// return ostream of a polynomial using object operator function
ostream &operator<<(ostream &out , const polynomialADT &poly)
{
    int i = 0;
    if ( poly.getDegree() == -1 ){
            cout << 0.0 << endl;
            return out;
   }    // check statement of degree exists
   while( poly.getDegree() > i){
    if(poly.getCoefficient(i) != 0.0){
        out<< poly.getCoefficient(i)<<"x^"<<i<< " + ";
   }    // if statement to print out only elements that doesnot contains 0
    i++;
   }// loop throughout polynomial array
   out << poly.getCoefficient(poly.getDegree())<<"x^"<<poly.getDegree()<<endl;     // printing out last and highest power of array
   return out;  // return the out ostream with printout polynomial
}

// return object of scalar multiple polynomial
polynomialADT polynomialADT::multPoly(int scalar){
    polynomialADT result;
    result.degree = degree;
    for(int i = 0; i <= result.getDegree(); i++){
        result.changeCoefficient( (coeffi[i]*scalar),i);    // if element is 0* scalar will return 0
    }   // loop through coefficient array and multiply each coefficient by scalar
    return result;
}
// add poly 2 polynomials and reassigned to local object
polynomialADT polynomialADT::addPoly(const polynomialADT &rhs){
    polynomialADT result;
    if(degree >= rhs.getDegree() ){
        result.degree = degree;
    }else{
        result.degree = rhs.getDegree();
    }
    for( int i = 0; i <= result.getDegree(); i++){
    result.changeCoefficient(coeffi[i] + rhs.getCoefficient(i), i);
    }   // add two coefficient by index loop and reassign to array coefficient
    return result; // return result
}
// return object of two polynomial sum
polynomialADT polynomialADT::operator+ (const polynomialADT &rightSide)
{
    polynomialADT sumPoly;
    if( degree >= rightSide.getDegree()){    // if statement to find largest polynomial
    sumPoly.degree = degree;  // assign largest polynomial
    }else {
        sumPoly.degree = rightSide.getDegree();
    }
    for ( int i = 0; i <= sumPoly.getDegree(); i++){
        sumPoly.changeCoefficient( (coeffi[i] + rightSide.getCoefficient(i)), i);
    }   // loop assign all coefficient to new object polynomial
    return sumPoly;
}
// return polynomial after multiplying parameter scalar to polynomial
polynomialADT polynomialADT::operator*(int scalar)
{
    polynomialADT sum;
    sum.degree = degree;// assign highest degree to sum polynomial object
    for( int i = 0; i<= degree; i++){
    sum.changeCoefficient(( coeffi[i]*scalar), i);   // assigning scalar to coefficient of polynomial
    }// loop
    return sum;
}// end scalar multiple overloading
// return a negative value of polynomial object
polynomialADT polynomialADT::operator-(){
    polynomialADT result;
    result.degree = degree;   // assigh highest degree to local polynomial
    for(int i = 0; i <= degree;i++){
          result.changeCoefficient( coeffi[i]*(-1), i); // change coefficient of result
    }// loop to change all coefficient of polynomial to negative value
    return result; // return new polynomial
}
