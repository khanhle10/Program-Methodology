/*
    Khanh Le
    CSC 340
    Problem 1
    Matrix multiplication: Write a C++ program to compute the product of two matrices. You are required to use the
    template class vector to represent a matrix. Specifically, your program will include the main( ) function and a
    second function multiply_matrices( ). The main() function will allow the end-users to provide the dimensionality
    of the two matrices A and B, and subsequently the content of A and B call the multiply_matrices() function to
    compute the product of A and B print out the multiplication result
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void display( int &row, int &col, int &row2, int &col2);
void createMatrix( vector< vector<int> > &matrix, int row, int col);
void mutiplyMatrix(vector< vector<int> > &matrix1, vector < vector<int> > &matrix2, vector < vector<int> > &matrix, int row, int col, int row2, int col2);
void print(vector< vector<int> > &matrix, int row, int col2);
int checkInput();
int main()
{
    int row = 0, col = 0, row2 = 0, col2 = 0;
    cout << "Hello world!" << endl;
    display(row, col, row2, col2);
    vector< vector<int> > matrix1 (row, vector<int>(col));
    vector< vector<int> > matrix2 (row2, vector<int>(col2));
    vector< vector<int> > matrixMult(row,vector<int>(col2));
    cout << "Creating First Matrix\n";
    createMatrix(matrix1, row, col );
    cout<< "Creating Second Matrix\n";
    createMatrix(matrix2, row2, col2);
    mutiplyMatrix(matrix1, matrix2, matrixMult, row, col, row2, col2);
    cout << "Displaying Result\n";
    print(matrixMult, row, col2);
    return 0;
}
/*
    Pre: Pass by reference of variables integers row, row2, col, col2
    Function: Prompt user to input the rows and columns of matrices and update the passed variables.
*/

void display( int &row, int &col, int &row2, int &col2 ){
    // loop to ensure that inputs are correct
        while (true){
        cout << "Please Enter the size of the Matrix Rows: ";
        row = checkInput();             // call checkfunction to check if input is an integer
        if ( row <= 0){ // if state of input cannot be zero
            cout << "Error, Matrix Row size cannot be less than zero.\n";
            cout << "Please Enter the size of the Matrix Rows: ";
            row = checkInput();
        }
        cout << "\nPlease Enter the size of the Matrix Columns: ";
        col = checkInput();
        if ( col <= 0 ){
         cout << "Error, Matrix Row size cannot be less than zero.\n";
        cout << "\nPlease Enter the size of the Matrix Columns: ";
        col = checkInput();
        }
        cout << "\nPlease Enter the size of the Second Matrix Rows: ";
        row2 = checkInput();
        if ( row2 <= 0){
            cout << "Error, Matrix Row size cannot be less than zero.\n";
        cout << "Please Enter the size of the Second Matrix Rows: ";
        row2 = checkInput();
        }
        cout << "\nPlease Enter the size of the Second Matrix Columns: ";
        col2 = checkInput();
        if ( col2 <= 0){
        cout << "Error, Matrix Row size cannot be less than zero.\n";
        cout << "\nPlease Enter the size of the Second Matrix Columns: ";
        col2 = checkInput();
        }
        if (col == row2){   // if state to ensure that col of first matrix must be equal to row of second matrix or will loop back and prompt user to input values again
         break;
         }
         cout<< "Error! Mismatch Matrices.\n Columns of first Matrix must match Rows of the second Matrix."<< endl;
        }// end if loop for all input values of the two matrices

      }// end of function for initializing all matrices size variables
/*
    Pre: Pass by reference vector or vector integer and the size of the matrix variables row and column
    Function: initializes the matrix by looping through the row of one vector declared matrix and loop through other vector declared column matrix. Prompt user to input an integer in ever element of vector rows and columns
    Resulting a 2D matrix of rows and columns that is then printed as a matrix.
*/
void createMatrix( vector < vector<int> > &matrix, int row, int col){
    int input = 0;
        for (int i = 0; i < row; i++){  // loop rows of vector
            cout<< "Rows: "<< endl;
            for( int j = 0; j < col; j++){  // loop columns of vector
            cout<< "Enter a value: ";
            input = checkInput();
            matrix[i][j] = input; // initialize every elments in the vectors of rows and columns through user input.
            }
            cout<< endl;
        }// end initializing matrix
        for ( int a = 0; a < row; a++){
            cout << "|  ";
            for (int b = 0; b < col; b++){
            cout << matrix[a][b] << "   ";
             } cout << "  | \n";
        }// printing out matrix
    }// end of initializing and printing matrix
/*
    Pre: Pass by reference of matrices and pass by value of matrix size variables by integer.
    Function: looping through vector row and vector columns element and multiply the two matrices and assaigned to the resulting matrix which is a loop addition of all the row in the two matrices multiplication.
*/
void mutiplyMatrix(vector < vector<int> > &matrix1, vector < vector<int> > &matrix2, vector < vector<int> > &matrixMult, int row, int col, int row2, int col2){
        // looping through vector of rows
        for( int i = 0; i != row; i++){
            for (int j = 0; j != col2; j++){    //looping through vector of columns
                for ( int x = 0; x != row2; x++)
                matrixMult[i][j] += (matrix1[i][x])*(matrix2[x][j]); // mutiply the elements of two matrices and assigning the result to the third but also adding all the rows of the two multiplying matrices together
        }
    }
    }   // end of function with resulting multiplied matrix
/*
    Pre: Paasing resulting matrix and its integer size variables
    Functions: Looping through a double vector to access the element and displaying the matrix.
*/
void print(vector< vector<int> > &matrixMult, int row, int col2 ){
        // loop of vector rows
        for ( int i = 0; i < row; i++){
            cout << " | ";
        for (int j = 0; j < col2; j++){ // loop of vector columns
        cout<< matrixMult[i][j]<< " | ";}
        cout<< "\n";}
    }   // end of display result matrix
/*
    Pre: nothing
    Function: Returns an integer after prompting user to input and check if the input is a valid integer type then return that value.
*/
int checkInput(){
    int input = 0;
    //loop to ensure that the input is correct
    while(!(cin >> input)){
            cout << "Error, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return input;   // return an integer
    }// end of check function for integers
