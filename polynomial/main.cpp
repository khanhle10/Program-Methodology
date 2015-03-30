/*
    Khanh Le
    CSC 340
    HW#4 Polynomial
    Create a Polynomial by prompting the USer to input
Use separate compilation to implement a polynomial ADT that manipulates polynomials
in a single variable x (e.g., p = 4 x5
 + 7 x 3 – x2
 + 9 ). For this problem, consider only
polynomials whose exponents are nonnegative integers. You are required to identify a
proper data representation schema to store such polynomials and hide such data from
external users of this ADT. Additionally, your ADT will at least include the following
member functions:
! One default constructor.
! One method allowing one to get an entire polynomial by interacting with the user
to obtain the degree and coefficient of each term in a polynomial.
! degree() // Returns the degree of a polynomial, which is the highest power
 // of a term with a nonzero coefficient. E.g., p.degree()=5
! coefficient(power) // Returns the coefficient of the x p o w e r term.
! changeCoefficient(newCoefficient, power) // Replaces the coefficient of
 // the x p o w e r term with newCoefficient.
! A method that multiplies a polynomial by a scalar variable
! A method that adds two polynomials.
! A method that prints out a polynomial.
! Overload the division operator (/) as a member function to multiple divide a
polynomial by a scalar variable.
! Overload the negation operator (-) as a member function to negate a polynomial
! Overload the “put” operator (<<) to output a polynomial on an output stream.
*/
#include "polynomialADT.h"
#include "polynomialADT.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void actions(polynomialADT &poly1);
void createPoly(polynomialADT &poly);
int main()
{
    cout << "Hello world!" << endl;
    polynomialADT poly; // create object function
    createPoly(poly);   // call function to prompt user input
    actions(poly);  // call function to begin implemeting options
    return EXIT_SUCCESS;    // exiting program
}
/*
    Pass by reference polynomialADT
    Function: prompt user to input polynomial size and input coefficient
*/
void createPoly(polynomialADT &poly){
    int power, check = -1, length;
    double value;
    cout << "Enter Number of Degree For Polynomial (5): ";  // user input the length of
    while(cin >> length){
        if( length > 0){
            break;
        }   // check to obtain the length of polynomial
    cout << "Error! Please Enter A Positive Value For Polynomial Length: ";
    }   // check of the imput is an int
    while (length != 0){
    cout << "Please Enter Powers In Increasing Order\n";
    cout << "Enter the Power: x^";
     while(cin >>power){
         if (power > check){   // if statement to check if the power input is in increasing order of power
             check = power;
             break; // break out of loop if power value is greater than previous
         }
        cout << "Error!\nPlease Enter the Power In Increasing Order: x^";
        }  // continue loop if power is less than
     cout<< "Enter Coefficient for x^"<<power<<": ";    // prompt coefficient
    while(!(cin >> value)){
         cout << "Error! Please Enter Coefficient For x^"<<power<<": ";
    }  // check if value is an doule
        poly.changeCoefficient(value, power);// pass value and power to member function to update initial polynomial
        length--;   // decrement polynomial length
    }
    poly.setDegree(power); // highest power assign to degree
}
/*
    Pass by reference object of polynomialADT
    Function: Prompt usering to add, multiply, print, or scalar multiply polynomial
*/
void actions(polynomialADT &poly)
{
    polynomialADT poly2;
    polynomialADT result;
    int choice = 0, value;
    do{
        // prompt
        cout<<"***********************************\n";
        cout << "1\tAdd"<<endl;
        cout << "2\tMultiply Scalar"<<endl;
        cout << "3\tPrint"<<endl;
        cout << "4\tOverloading Scalar Operation"<< endl;
        cout << "5\tNegation Operation"<<endl;
        cout << "6\tQuit"<<endl;
        cout<<"***********************************\n";
        cout <<"Enter Choice: ";
        while(cin >> choice){
            if ( choice <= 6 && choice > 0){
                break;
            }   // loop to check valid input between the expected condition break if so
        cout << "Error!\n Please Enter Again:";
        }//
        value = 0;
        switch(choice){ // switch statement for options
            case 1:
                    cout << "Adding Two Polynomial\n";
                    cout << "First Polynomial:\n"<<poly << endl;    // overloading operator to print polynomial
                    cout << "Set Second Polynomial:\n";
                    createPoly(poly2);    // prompt user to input second polynomial
                    cout << "First Polynomial:\n"<<poly << endl;    // overloading operator to print polynomial
                    cout << "Second Polynomial:\n"<<poly2 <<endl;   // overloading operator to print second polynomial
                    result = poly.addPoly(poly2); // object function to add two polynomial
                    cout << "Result: "<<result <<endl;   // overload operator to print polynomial result
                    break;  // break out of switch statement
            case 2:
                    cout << "Multiply Scalar\n";
                    cout << "Please Enter A Scalar Value: ";
                    while( !(cin >> value)){  // prompt user to input a value as scalar
                        cout<< "Error!\n Please Enter A Value: ";
                    }
                    cout << "First Polynomial:\n"<<(poly) << endl;    // overload operator print polynomial

                    result = poly.multPoly(value);   // object member function all to multiply scalar
                    cout << "Result: "<<result<< endl; // overload operator to print result from multiplying scalar
                    break;  // break out of switch statement
            case 3:
                    cout << "Print Polynomial:\n";
                    poly.print();   // print by object member function all
                    break;  // break out of switch statement
            case 4:
                    cout <<"Scalar Multiplication Overloading"<<endl;
                    cout << "Please Enter A Scalar Value: ";
                    while( !(cin >> value)){  // prompt user to input scalar value
                        cout<< "Error!\n Please Enter A Value: ";
                    }
                    result = poly.operator*(value); // overloading scalar multiple
                    cout << "Scalar Overload Result: "<<(result) << endl; // overloading operator to print
                    break; // break out of switch statement
            case 5:
                    cout << "Negation Overloading"<<endl;
                    result = poly.operator-();  // overload operator negation function
                    cout << "Negative Overload Result: "<<(result) <<endl;   // overloading operator to print result
                    break;  // break out od switch statement
            case 6:
                    cout << "End Program."<<endl;
            default:
                cout<< choice <<" is Invalid."<<endl;   // message default
        }
    }while (choice != 6);   // break out of loop to
}
