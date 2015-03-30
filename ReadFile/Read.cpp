/*
    Khanh Le
    CSCS 340
    HW Problem 2
    File I/Os:Given three text files, each of which contains a a sorted list of integers (one integer per line) in
    non-decreasing order, write a C++ program to merge these three input files into a fourth file in which all the
    numbers remain their sorted order. Your program will include the main() function and another function that merges
    the three files. Specifically, the main() function will ask a user to type in the names of the three input files.
    It will then call the merging function to merge the three files. Finally, it informs the user the name of the merged
    file. Note that you are not allowed to load all the numbers into an array or vector then apply a sorting algorithm to
    this array.
    having 3 files
    file1 : -100 -10 0 2 3 6    file2: 0 3 4 6 10  file3: 0 2 3 4 5 6 7 8
    outputfile one integer per line
    -100    2(1)    3(3)    6(2)
    -10     2(2)    4(2)    6(3)
    0(1)    2(3)    4(3)    7(3)
    0(2)    3(1)    5(3)    8(3)
    0(3)    3(2)    6(1)

*/
#include <iostream>
#include <limits>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
void readFile(ifstream &file1, ifstream &file2, ifstream &file3, ofstream &writeFile);
void openFile(ifstream &file, int &count);
void outWriteFile(ofstream &writeFile);
//void openFile(ifstream &file, string input);
//void openWriteFile(ofstream &writeFile, string input);
void updateFile(ifstream &file, int &small );

int main(){

    //string input1 = "readfile1.txt", input2 = "readfile2.txt", input3 = "readfile3.txt", write = "writefile.txt";
    int count = 1;
    ifstream firstFile;
    ifstream secondFile;
    ifstream thirdFile;
    ofstream writeFile;
    // loop to check if all the files are opened
    while (true){
    openFile(firstFile, count);
    openFile(secondFile, count);
    openFile(thirdFile, count);
    outWriteFile(writeFile);
    if( firstFile.is_open() && secondFile.is_open() && thirdFile.is_open() && writeFile.is_open()){
        cout<< "All Read Files Are Opened"<< endl;
        break;
    }
    cout << "Error, One or More File Have Not Been Opened"<< endl;
    }
     /*
    openFile(firstFile, input1);
    openFile(secondFile, input2);
    openFile(thirdFile, input3);
    cout << "Open Output File"<< endl;
    cout << "Opening Write File: writefile.txt"<< endl;
    openWriteFile(writeFile, write);
    */
    readFile(firstFile, secondFile, thirdFile, writeFile);
    cout<< "\nAll Opened Files Are Closed"<< endl;
    firstFile.close();
    secondFile.close();
    thirdFile.close();
    writeFile.close();
    return 0;
}
/*
    Pre: Pass be reference the ifstream of all three read file and also ofstream outfile
    Function: To loop through each read files and find the smallest integer variable before calling an update function to increment to the next
    integer in the specific file with the smallest integer variables until the end of the file. Once all three files have reach the end of the file the loop will end.
*/
void readFile(ifstream &file1, ifstream &file2, ifstream &file3, ofstream &writeFile){
    int num1 = 0, num2 = 0, num3 = 0;
    if ( !file1.eof() && !file2.eof() && !file3.eof()){
        //initializing num variables
            file1 >> num1;
            file2 >> num2;
            file3 >> num3;
           // loop through each files as increments of each integer in each files
           while(true){
            // if statement to find lowest value and write it to outfile then call update function (updateFile) to update increments of file1 to next integer
            if( num1 <= num2 && num1 <= num3){
                writeFile << num1 << endl;      // write to outfile
                updateFile(file1, num1);        // call function to update num value to next integer in the read file
                if ( file1.eof() && !file2.eof() && !file3.eof()){       // if statement to check if the first file have reach the end, assuming the other two files is also about to reach the end
                    if( num2 <= num3){                                      // program will assumed the other two files variables only contains the last two largest values
                        writeFile << num2 << endl;          // if statement to write the largest value last
                        writeFile << num3<< endl;
                    }else {
                    writeFile << num3<< endl;
                    writeFile << num2 << endl;
                    }
                    break;
                }// if statement to check for end of files and to write two largest values to outfile, then break from loop
            }else if (num2 <= num3 && num2 <= num1){
                   writeFile << num2 << endl;           // if statement to write smallest value to to outfile
                updateFile(file2, num2);        // if statement to update num variables to next integer in file2
                if (!file1.eof() && file2.eof() && !file3.eof()){    // if statement to check for the largest value assuming file1 and file3 is also about to reach end of file
                    if ( num1 <= num3){                     // if statement will check and write the smallest of the two largest value into the outfile assuming file2 have reach the end and only file1 and file3 holds the
                    writeFile << num1 << endl;              // last two large variables.
                    writeFile << num3 << endl;
                    }else{
                    writeFile << num3 << endl;
                    writeFile << num1 << endl;
                    }
                    break;                      // program to break out of the while loop once all last value of all three filess have been read and write to the third file
                }
            }else if (num3 <= num1 && num3 <= num2){    // if statement to find the smallest value of three variables
                writeFile << num3 << endl;  // the smallest value is then written into the outfile
                updateFile(file3, num3);    // the file with the smallest variable is incremented to the next variable
                if (!file1.eof() && !file2.eof() && file3.eof()){        // if statement will check if the file had reach end of file
                   if ( num1 <= num2){      // if statement tries to determine the largest value to which will be written last in the output file.
                    writeFile << num1 << endl;      // the biggest assumption is the fact that the file3 is at the end of the file and file1 and file2 is also about to reach the end of the file and only their largest values remains
                    writeFile << num2 << endl;
                    }else{
                    writeFile << num2 << endl;
                    writeFile << num1 << endl;
                    }
                    break;  // break out of the while loop once the last largest variables have been written into the outfile
                    }// if statement did not reach then the continue the loop as end of file have not been reached.
            }   // end of if statement assuming all variables have been incremented and have not exited the loop

            if ( !file1.eof() && file2.eof() && file3.eof()){    // re-assigning an end of file variables so the largest value will appeared more the once increase the possibility of existing the program faster
                num2 = num1;        // assuming num2 and num3 contains the two smallest variables where both files has reached end of file then any last variables will be put into the outfile at the end of the loop
                num3 = num1;
            }else if ( file1.eof() && !file2.eof() && file3.eof()){
                num1 = num2;        // assuming file1 and file3 have reached the end, then re-assigned num1 and num3 to num2 as a way to exist the program faster once the last variables is written into the outfile.
                num3 = num2;
            }else if ( file1.eof() && file2.eof() && !file3.eof()){
                num1 = num3;    // assuming file1 and file2 have reached the end of file then any variables that still exist in file3 will be reassigned to the other two as a way to exist the program faster since all three variables are the same
                num2 = num3;
            } // if statements to check for end of files and reassign the other two end of
           } // end of looping through the program to write to outfile
           }else{
                cout<< "File seemed to be empty.\n";
            }
    }// end of readfile and write file
/*
    Pre: Pass by reference of ifstream file and the integer small variale of the current file line that is being read.
    Function: Shift the integer variable to the next line to be read and assigned to the small variable.
*/
void updateFile(ifstream &file, int &small ){
    if ( !file.eof()){
    file >> small;
    }
}

/*
void openFile(ifstream &file, string input){

    file.open(input.c_str());
    if(!file){
        cout << "Error! File Could Not Be Opened."<< endl;
        exit(1);
    }
    cout<< "Read File Opened!"<< endl;
}
void openWriteFile (ofstream &writeFile, string input){

    writeFile.open(input.c_str());
    if(!writeFile){
        cout << "Error! File Could not Be Opened."<< endl;
        exit(2);
    }
    cout<< "Write File Opened!"<< endl;
}
*/
/*
    Pre: Pass by reference of an uninitialized ifstream readfile and an integer of count
    Function: Prompt the user to input the read file, check, and open the readfile with the display of which file the user is trying to open.
    Increment the count to 1 so the user may know which read file alread open.

*/
void openFile(ifstream &file, int &count){
    string input = "";
    while (true){
     cout << "Please Enter Text File Name To Be Read(.txt) # " << count << "  : ";
    while(!getline(cin, input)){
        cout << "Error, Please Re-Enter The Text Read File Name(.txt) # "<< count<< "  : ";
    }
    file.open(input.c_str());   // open the file and check of the file is open
    if(!file.is_open()){
        cout << "Error! File Could not Be Opened."<< endl;
    }else {
        cout<< "\n Read File # "<<count<< " Is Opened"<< endl;
        break;  // break out of the loop if file is opened
    }
}   // loop to continue prompting the user to input the text file
    count++;
}   // end of open function
/*
    Pre: Pass by reference of an uninitalized ofstream writeFile
    Function: Prompt the user to input the write outfile, check, and open the file to be written to.
*/
void outWriteFile (ofstream & writeFile){
    string input = "";
    while (true){
      cout << "Please Enter Write Text File Name(.txt): ";
    while(!getline(cin, input)){
        cout << "Error, Please Re-Enter The Write Text File Name: ";
    }
    writeFile.open(input.c_str());  // call function to open file and check if the file is opened
    if(!writeFile.is_open()){
        cout << "Error! File Could not Be Opened."<< endl;
    }else {
        cout << "\n Write File Is Opened"<< endl;
        break;  // break out of the loop if file is opened
    }
    } // loop to continue prompting the user to input the outfile
}
