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
#include <vector>
using namespace std;
struct letterFreqAry {
    char letter;
    int count;
};
struct wordFreqAry {
    string word;
    int count;
};

    // function prototype and variables
string paragraph;
int wordSize = 100;
int letterSize = 26;
void countWordFreq(wordFreqAry * arrayWord);
void getFreqLetter(letterFreqAry* para);
//void removeDuple(wordFreqAry * arrayWord, int count);
int main()
{
    // create structs
    letterFreqAry * pPara = new letterFreqAry[letterSize];
    wordFreqAry * pArrWord = new wordFreqAry[wordSize];
    int maxCount = 0;
    vector <char> topChar;
    // prompt user to input pararaph and assigned it to paragraph variable
    cout << "Write a paragraph on anything you want.\n" << endl;
    // call getline to assign input to paragraph string/
        getline(cin, paragraph);
    while (paragraph.empty()){
    cout<< "Please write a paragraph: \n";
            getline(cin, paragraph);
    }//loop if there is no input.

    // call get frequency to display most frequent letter or letters and its counts.
    getFreqLetter(pPara);

    // call get frequency to display the most frequent word or words and its counts.
    countWordFreq(pArrWord);
    // end prgram
    return 0;
}// end main
/*
    Pre: string with input paragraph, pointer array of letter struct containing the letter character and count integer
    Function: To get the frequency of each letter and store its count and characters in an array of letter structs. Functions will displace
    the most frequent letter or letters that appeared in the paragraph and its counts.
*/
void getFreqLetter(letterFreqAry* para){
    int count = 0, num = 0, maxFreq = 0;
    char maxLetter = '0';
    letterFreqAry maxFreqArray[15];
    cout<<"\n*******************Letter Frequency*************************\n"<<endl;
      // loop increase count for each letter frequency
      for( int i = 0; i < paragraph.length(); i++){
        if (isalpha(paragraph[i])){
            count = tolower(paragraph[i]) - 'a';
            para[count].count++;
        }// if statement to check for the element of the paragraph string contains an alphabet by calling isalpha() function
            // and increase the count of the array struct by using the ASCII decimal in integers and substract that from the distant of lowerase a which is 97 in decimal
           // also use call tolower() function to covert the character in the array struct to lowercase working between 97-122 instead.
    }
    // loop assigned letter to each element of the array
    for ( int n = 0; n < letterSize; n++){
        if( para[n].count >= 0){
            para[n].letter = n +'a';
        }// loop to create 26 elements of array of letter struct then assigned letter base on the index substracted by the integer of lowercase a which is 97
            // for every distant way from 'a' a letter will be assigned.
    }
    // find frequency of the array of characters
    cout<< " All Letters \t# \tCount   \n"<< endl;
    for (int b = 0; b < letterSize; b++){
    cout << "\t"<<para[b].letter <<" \t"<< b+1<< "\t"<< para[b].count<< endl;
        if( para[b].count > maxFreq){
          maxFreq = para[b].count;
          maxLetter = para[b].letter;
          maxFreqArray[0].count = para[b].count;
          maxFreqArray[0].letter = para[b].letter;
       }// loop and if statement to check for the most frequent letter by the highest counts then store that count and letter to maxFreq, and maxLetter
       }
       for ( int f = 0; f < 15; f++){
            for (int a = 0; a < letterSize; a++) {
                if( maxFreq == para[a].count && maxLetter != para[a].letter){
                    maxFreqArray[f].count = para[a].count;
                    maxFreqArray[f].letter = para[a].letter;
       }// if statement will compare maxFreq with second loop through the letter array struct to find more highest letter count and store them in maxFreqArray
    }
    if( maxFreqArray[f].count == maxFreq){
        num++;
        cout<< "\n Most Frequency Letter     "<<num <<"     :   "<< maxFreqArray[f].letter << "     Frequency:     " << maxFreqArray[f].count<< endl;}
    }   // loop to displace only the most frequent letter or letters and its counts.
    // loop ends with maxFreqArray holding the size of
    }   // end of get frequncy function


/*   Pre: string with input paragraph and array of word struct wordFreqAry containing word string and integer count
     Function: Take the words in the paragraph input assigned them to 100 element of an array of word struct. Each element of the array word struct
     will contains each unique word and its count up to 100.
*/
void countWordFreq(wordFreqAry *arWord){
    string words = "", temp = "";
    bool uniqueWord = true;
    int wordCount = 0, counter = 0, maxCount = 0, start = 0, num = 0,  length = 0;
    size_t found = paragraph.find_first_of(" .,;?:");
     wordFreqAry tempWord[15];
    // loop to assigned character null to each element in the array of struct word and initialize count to 0 in array struct;
    for ( int x = 0; x < wordSize; x++){
        arWord[x].word = '\0';
        arWord[x].count = 0;
        }
        cout<<"\n*******************Words Frequency**************************\n"<<endl;

    // loop through the input paragraph to finf the first delimiter
    while(found!=std::string::npos){
        length = found - start;
        temp = paragraph.substr(start,length);    // calling substr using the starting index and the length of the word to copy and assign to temp string
        transform(temp.begin(), temp.end(),temp.begin(), ::tolower);  //call tolower to convert string to lowercase
            for( int j = 0; j < 100; j++){   // count words
                uniqueWord = false;
                for( int k = j+1; k < 100; k++){
                    if( temp.compare(arWord[k].word) == 0 && temp.length() == arWord[k].word.length()){  // if statement to check for word in word array to increase word counts
                    arWord[k].count++;
                    uniqueWord = true;
                    temp = "";
                    break;
                }   // uniqueWord variable function as the pointer to which a word can or cannot be inputed into the array struct of word and count
            }   // loops to check for words already exist by comparing temp string with each element in the array
                if(!uniqueWord) {
                    if ( temp.length() > 0){
                        arWord[wordCount].word = temp;
                        arWord[wordCount].count++;
                        wordCount++;
                        temp = "";} // check statement to ensure that the input string is not empty
            }   //if statement check if uniqueWord is false indicating new word to be added into array struct.
        }// end of looping through paragraph to grab words
        start = found; // assign the found index of the paragraph string to start to begin scanning for different delimiter.
            found = paragraph.find_first_of(" .,;?:", found+1); // increase the index of words by reassigning a new index using the previous location as a starting point
                 if (found == (start + 1 )){
                     while (true){
                       start = found;
                       found = paragraph.find_first_of(" .,;?:", found+1);
                       if(found != (start +1)){
                            break;
                       }
                     }// loop to make sure there is no more delimiter in the index after starting of the next word to be read in the paragraph string
           }   // check statement will increase the index if another delimiter follows the previous such as a comma follow by a space will reassign the index to a new location
    }   // loop find delimiter using new found location;
    cout<< " All Words \t #\tCount  \n"<< endl;
    for (int b = 0; b < wordCount; b++){
    cout << "  "<<arWord[b].word <<"\t"<< b+1<< "\t"<< arWord[b].count<< endl;
        if( arWord[b].count > maxCount){
            maxCount = arWord[b].count;
            words = arWord[b].word;
            tempWord[0].count = arWord[b].count;
            tempWord[0].word = arWord[b].word;
        }   // assign first most frequent word and its count
    }   // looping through word array to find the highest word count and its word

        for( int f = 0 ; f < 15; f++){
            for (int a = 0; a < wordCount; a++) {
                if( maxCount == arWord[a].count && !words.compare(arWord[a].word)){
                    tempWord[a].count = arWord[a].count;
                    tempWord[a].word = arWord[a].word;
       }    // if statement to assign more max words and it counts to the temp array struct of max words
    }   //  if statement to find another word count and assign word and count to the array of max words
        if (tempWord[f].count == maxCount && !words.compare(arWord[f].word)){
            num++;
            cout<< "\n\tMost Frequency Word\t"<<num <<" :"<< tempWord[f].word << " Frequency:\t" << tempWord[f].count<< endl;}
        }   // loop to displace max word or words and its counts & end of loop through word array

}   // end of get frequency of words Function
