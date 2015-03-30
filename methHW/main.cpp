/*
    Khanh Le
    CSC 340-02
    2:10-3:20
    HomeWork 1
Problem 1. Implement a C++ program that has the following functions:
Reads in a paragraph of English text up to 100 words from the keyboard and stores this paragraph in a string object.
Feel free to include this task in the main() function.
Identifies the most frequent letter (case insensitive) in the above paragraph. Implement a separate function getFreqLetter()
for this task. The main function then calls this function to find out the most frequent letter and its frequency.
Calculate the frequency of each unique word (case insensitive). Implement a second function countWordFreq() for this task.
Use white spaces and punctuation marks such as comma, period, semicolon and question mark as word delimiters.
Please define a global struct that contains two fields, word and its count for this task. You can then define an array of this
struct to store all the unique words and its counts. The main() function will call this function to print out each word and its
corresponding frequency.

*/
    // declare libraries
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;
struct wordFreqAry {
    // declare variables
    string word;
    int arrayCount;
};
string paragraph;
void getFreqLetter( );
void getFreqWord( wordFreqAry words[], int size);
int main()
{
    string paragraph;
    int maxFreq = 0;
    int size = 100;
    vector<char> topFreq(26);
    wordFreqAry words[size];

    cout << "Hello world!" << endl;
    cout<< "Please Write A Paragraph: "<< endl;

    getline(cin, paragraph);

    getFreqLetter();
    getFreqWord( words, size);
    return 0;
}

void getFreqLetter( int maxFreq ){
    int letterSize = 26;
    int letterFreqAry[letterSize];

    vector<char> maxLetter;
    for( int i = 0; i < letterSize; i++){
        letterFreqAry[i] = 0;
    }
   //for (int c = 0; c < paragraph.length(); c++){
     for( char c: paragraph){
        letterFreqAry[toupper(paragraph[c]) - 'A'] +=1;
    }
    for ( int i = 0; i < letterSize; i++){
        if( letterFreqAry[i] > maxFreq){
        maxFreq = letterFreqAry[i];
        maxLetter[i] = letterFreqAry[i];
        }
        cout<< maxLetter[i]<< "  " << maxFreq<< "  ";
        }
}



void getFreqWord(wordFreqAry words[], int size )
{
    string temp = "";
    size_t found = paragraph.find_first_of(" .,;?:");
    while(found!=std::string::npos){

        for( int j = 0; j < size; j++){
            for ( int i = 0; i < found; i++){
                temp[i] = paragraph[i];
            }
            if( find(temp.begin(), temp.end(), words[j].word) == temp.end()) ){
                words[j].arrayCount++;
            }else{
                words[j].word = temp;
                words[j].arrayCount++;
            }
            cout<< "  ARRAY|  "<< words[i].word << "  Count  " << words[i].arrayCount;
        }
            found = paragraph.find_first_of(" .,;?:", found+1);
            if(found == paragraph.find_first_of(" .,;?:")){
                found++;
            }
    }
}
