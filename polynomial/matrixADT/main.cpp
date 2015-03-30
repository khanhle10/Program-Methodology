/*
    Khanh Le
    CSC 340 Programming Methodology
    HW#4
    Creating a Matrix and Prompt User to input specific options
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
by a scalar variable. ! An overloaded subtraction operator (-) as a member function to subtract one matrix
from another if their dimensionality matches.
! An overloaded “put” operator (<<) to output a matrix on an output stream.
*/


#include "matrixADT.h"
#include "matrixADT.cpp"
#include <iostream>

using namespace std;

void createMatrix(matrixADT &matrix);
void actions(matrixADT &matrix);
int main()
{
    cout << "Hello world!" << endl;
    int size;
     cout<<"Please Enter Matrix Size: ";
    while(cin >> size){
        if( size > 0){
            break;
        }
    cout<< "Error!\n Please Enter Dimension of Matrix: ";
    }   // loop to make sure input value is greater than 0
     // object function member calls to assign dimensions and assign all element to 0
    matrixADT matrix(size);   // create object matrix class
    createMatrix(matrix);   // function call prompt user
    actions(matrix);    // prompt user for specific actions
    return 0;
}
// prompt user to into matrix variables
void createMatrix(matrixADT &matrix){
     int value;
    cout<< "Enter Matrix Value: \n";
    for( int i = 0; i < matrix.getSize(); i++){
        cout << "Row:\n";
        for(int j = 0; j < matrix.getSize(); j++){
        while(!(cin >> value)){
            cout<< "Error!\nPlease Enter Value: ";
        }   // loop to check input is an int
            matrix.setMatrixValue(i,j,value);   // object member function all to set value at passed positions
    }// end for loop to input Matrix
    }
    cout << "Matrix:\n";    // diplace matrix
    cout<<matrix<<endl;
    /*for( int i = 0; i < matrix.getSize(); i++){
        cout<<" |  ";
        for( int j = 0; j < matrix.getSize(); j++){
            cout<< matrix.getMatrixValue(i,j)<< "  |  ";
        }
        cout << "\n";
    }*/
}
// function call prompt user input options
void actions(matrixADT &matrix)
{
    matrixADT result(matrix.getSize());  // intializes objects matrix for result and second
    matrixADT second(matrix.getSize());
    int enter, choice;
    do{
        // prompt user input
        cout<<"\n*********************************************\n";
        cout << "1\tTranspose"<<endl;
        cout << "2\tOverloading Operations Multiply Matrices"<< endl;
        cout << "3\tOverloading Operations Multiply Scalar"<<endl;
        cout << "4\tOverloading Operations Negation"<<endl;
        cout << "5\tOverloading Operations Substraction"<<endl;
        cout << "6\tQuit"<<endl;
         cout<<"********************************************\n";
        cout <<"Enter Choice: ";
        while(cin >> choice){   // break options if within prompt
            if ( choice < 6 && choice > 0){
                break;
            }
            cin.clear();    // clear input if input fail condition
        cout << "Error!\n Please Enter Again:";
        }
       enter = 0;
        switch(choice){ // switch statement to implement user options
            case 1:
                    cout << "Transpose Matrix\n";
                    cout << "Matrix\n"<< matrix << endl;    // overload operator print
                    result = matrix.transpose();  // switch columns and rows
                    cout << "New Matrix\n"<<(result) << endl; // overload operator to print
                    break;  // break out switch
            case 2:
                    cout << "Overloading Operations Multiply Matrix\n";
                    createMatrix(second);   // create matrix
                    cout<<"Second Matrix:\n"<<second<<endl;
                    result = matrix.operator*(second);  // multiply two matrix and assign to result object
                    cout <<"Multiply Result:\n"<<(result)<<endl;    // overload operator print
                    break;  // break out switch
            case 3:
                    cout <<"Overloading Scalar Multiplication"<<endl;
                    cout<<"Matrix\n"<<matrix<<endl; //
                    cout << "Please Enter A Scalar Value: ";
                    while(!(cin >> enter)){
                    cout << "Error!\n Please Enter Scalar Again: ";
                    }   // loop to check for int input
                    cout<<"Matrix\n"<<matrix<<endl;
                    result = matrix.operator*(enter);   // assign overload operator scalar multiplication to result object
                    cout << "Scalar Result:\n"<< (result) << endl;    // overload operation print
                    break;  // break out switch loop
            case 4:
                    cout << "Negative Overload"<<endl;
                    cout<<"Matrix\n"<<matrix<<endl;
                    result = matrix.operator-();     //  overload operator object negation by assigning negative to all variables in matrix
                    cout << "Negative Overload Result:\n"<<result <<endl;   // overload operation print
                    break;  // break out of switch
            case 5:
                    cout << "Overloading SubStraction" <<endl;
                    createMatrix(second);   // create matrix
                    cout<<"Matrix\n"<<matrix<<endl; //
                    result = matrix.operator-(second);   // assign overload operator subtract object and second object to result object
                    cout << "New Matrix\n"<<result << endl;    // overload operation print
                    break; // break out of switch
            case 6:
                    cout <<"End Program."<<endl;
                    break;
            default:
                cout<< choice <<"Invalid Input!"<<endl;   // display message
        }   // end switch
    }while (choice != 5);   // exit loop if choice is 8
}// end of actions prompt

/*
    do{
        // prompt user input
        cout<<"\n*********************************************\n";
        cout << "1\tGet Value In Matrix By Position"<<endl;
        cout << "2\tSet Value In Matrix By Position"<<endl;
        cout << "3\tTranspose"<<endl;
        cout << "4\tOverloading Operations Multiply Matrices"<< endl;
        cout << "5\tOverloading Operations Multiply Scalar"<<endl;
        cout << "6\tOverloading Operations Substract"<<endl;
        cout << "7\tOverloading Operations Negation"<<endl;
        cout << "8\tQuit"<<endl;
         cout<<"********************************************\n";
        cout <<"Enter Choice: ";
        while(cin >> choice){   // break options if within prompt
            if ( choice < 9 && choice > 0){
                break;
            }
        cout << "Error!\n Please Enter Again:";
        }
        x = 0, y = 0, enter = 0;
        switch(choice){ // switch statement to implement user options
            case 1:
                    cout << "Get Value In Matrix\n";
                    cout << matrix << endl; // overload opertator print matrix
                    cout << "Please Enter Position In Matrix (R: 2 C: 2 ):  ";
                    cin >> x >> y; // prompt user to input the position
                    cout << " The Value At Position "<<x<< " "<<y<<" Is: ";
                    cout << matrix.getMatrixValue(x,y); // print out result of input matrix position
                    break;  // break switch options
            case 2:
                    cout << "Set Value In Matrix\n";
                    cout << matrix << endl; // overload opertator print matrix
                    cout << "Please Enter Position In Matrix (R: 2 C: 2 ):  ";
                    cin >> x >> y; // prompt user to input matrix position to change
                    cout << "Please Enter The New Value: ";
                    while( !(cin >> enter)){
                        cout << "Error!\n Please Enter New Value Again:";
                    }   // loop check of input is an int
                    cout << " The Value At Position "<<x<< " "<<y<<" Change To: "<< enter<<endl;
                    matrix.setMatrixValue(x , y , enter); // object member function to set new matrix value
                    cout << "New Matrix\n";
                     cout <<(matrix) <<endl; // overload operator to print
                    break;  // break out of switch
            case 3:
                    cout << "Transpose Matrix\n";
                    cout << "Matrix\n"<< matrix << endl;    // overload operator print
                    result = matrix.transpose();  // switch columns and rows
                    cout << "New Matrix\n"<<(result) << endl; // overload operator to print
                    break;  // break out switch
            case 4:
                    cout << "Overloading Operations Multiply Matrix\n";
                    createMatrix(second);   // create matrix
                    result = matrix.operator*(second);  // multiply two matrix and assign to result object
                    cout <<(result)<<endl;    // overload operator print
                    break;  // break out switch
            case 5:
                    cout <<"Overloading Scalar Multiplication"<<endl;
                    cout << "Please Enter A Scalar Value: ";
                    while(!(cin >> enter)){
                    cout << "Error!\n Please Enter Scalar Again: ";
                    }   // loop to check for int input
                    result = matrix.operator*(enter);   // assign overload operator scalar multiplication to result object
                    cout << "New Matrix\n"<< (result) << endl;    // overload operation print
                    break;  // break out switch loop
            case 6:
                    cout << "Overloading SubStraction" <<endl;
                    createMatrix(second);   // create matrix
                    result = matrix.operator-(second);   // assign overload operator subtract object and second object to result object
                    cout << "New Matrix\n"<<result << endl;    // overload operation print
                    break; // break out of switch
            case 7:
                    cout << "Negative Overload"<<endl;
                    result = matrix.operator-();     //  overload operator object negation by assigning negative to all variables in matrix
                    cout << "Negative Overload Result: "<<result <<endl;   // overload operation print
                    break;  // break out of switch
            case 8:
                    cout <<"End Program."<<endl;
                    break;
            default:
                cout<< choice <<"Invalid Input!"<<endl;   // display message
        }   // end switch
    }while (choice != 8);   // exit loop if choice is 8
}// end of actions prompt
*/
