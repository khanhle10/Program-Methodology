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
#include <cstdio>
#include <string>

using namespace std;
void readFile(ifstream &file1, ifstream &file2, ifstream &file3, ofstream &writeFile);
void openFile(ifstream &file, int &count);
void outWriteFile(ofstream &writeFile);
//void openFile(ifstream &file, string input);
//void openWriteFile(ofstream &writeFile, string input);
//void updateFile(ifstream &file, int &small );

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
    int small = 0;
        //initializing num variables but checking for end of file first
        if(!file1.eof()){
            file1 >> num1;
             }
        if (!file2.eof()){
            file2 >> num2;
            }
        if (!file3.eof()){
            file3 >> num3;
        }
           // loop through each files as increments of each integer in each files by checking for end of files
           while(!file1.eof() || !file2.eof() || !file3.eof()){
            // if statement to find lowest value and write it to outfile then call update function (updateFile) to update increments of file1 to next integer
           if ( num1 <= num2 && num1 <= num3 && !file1.eof()){      // if statement for the lowest num variables
                    writeFile << num1 << endl;      // write to outfile
                    if(!file1.eof()){        // if statement to increment to the next num if the file is not end of file
                        file1 >> num1;          // reassign the next num value from the read file
                    }   // if file reach end of file
           }else if (num2 <= num3 && !file2.eof()){     // if statement assuming num2 is the smallest
                writeFile << num2 << endl;        // write to outfile
               if (!file2.eof()){   // if statement to check that file2 is not at end of file
                    file2 >> num2;              // reassign the next num value from the read file
                }   // if reach end of file
           }else if( num1 <= num2 && num1 <= num3 && file1.eof() && !file2.eof() && !file3.eof()){      // if statement assuming num3 is the smallest or file3 is not at end of file but the other two have
                writeFile << num1<<endl;
           }else if( num2 <= num3 && file2.eof() && !file1.eof()&& !file3.eof()){
                writeFile << num2<<endl;
           }else if( num1 <= num2 && num1 <= num3 && file1.eof() && !file2.eof() && file3.eof()){      // if statement assuming num3 is the smallest or file3 is not at end of file but the other two have
                writeFile << num1<<endl;
                if( num2 <= num3){
                writeFile << num2<< endl;
                }
                 if(!file2.eof()){
                    file2 >> num1;      // update num1 unless file2 is at end of file
                  }
           }else if( num2 <= num3 && file2.eof() && !file1.eof()&& file3.eof()){
                  if( num1 <= num2){        // if only file1 is open then write to file the lowest value
                    writeFile << num1<<endl;
                  }else{
                        writeFile << num2<<endl;
                  }
                if( num1 <= num3){      // input the last two variables into the write file
                    writeFile << num1 << endl;
                    writeFile << num3 << endl;
                }else {
                    writeFile << num3 << endl;
                    writeFile << num1 << endl;
                }
                if(!file1.eof()){     // if statement to update file1 value to the end of file
                    file1 >> num1;
                  }
           }else {
                     if( !file1.eof() && !file2.eof() && !file3.eof()){
                          writeFile << num3 << endl;  // write to outfile
                          if(!file3.eof()){ // if statement to update num3 or else end of file
                          file3 >> num3;
                          }
                    }else if (num3 <= num2 && num3 <= num1 && file1.eof() && !file3.eof()  && file2.eof()){
                            writeFile << num3<< endl;
                                if(!file3.eof()){   // if statement to update num3 or else end of file
                                    file3 >> num3;
                                }   // if file3 reach end of file
                                if(num2 <= num1){   // last two lowest value
                                    writeFile << num2 << endl;
                                    writeFile << num1 << endl;
                                }else {
                                      writeFile << num1 << endl;
                                      writeFile << num2 << endl;
                                }
                    }else if (num2 <= num1 && num3 <= num1 && file1.eof() && file3.eof()  && file2.eof()// if statement if file3 is the last file
                        writeFile << num1 << endl;
                }
           }    // end of while loop if all three files have reached end of file

    }// end of readfile and write file
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
}   // end of writeOutfile

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
