/*
    Khanh Le
    CSC 340 Methodology
    HW 5-B
    First, use separate compilation to redistribute the information in this class into a header file (.h) and an implementation file (.cpp).
    Next,  modify the deposit() and withdraw() member functions such that they throw appropriate exceptions instead of returning -1 as an error code.
    To this end, please define the following three exception classes as derived classes of the standard exception class: (1) Exception_Negative_Deposit,
    corresponding to the case of depositing a negative amount of money, (2) Exception_Overdraw, corresponding to withdrawing more than the account's balance,
    and (3) Exception_Negative_Withdraw corresponding to withdrawing a negative amount from an account. You can place these three exception classes in one header file.
    Finally, write test code that attempts to withdraw and deposit invalid amounts and catches the exceptions that are thrown.
*/

#include "Account.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

int main()
{
    Account objAccount;
    cout << "Hello world!" << endl;
    double depo = 0, draw = 0;
    cout<< "Balance: " << objAccount.getBalance() << endl;  // initial balance
    while(true){
    try{
        cout<< "Deposit: ";
        cout << "Enter Deposit Ammount: ";
       while(!(cin >> depo)){
            cout << "Input Error!\nPlease Enter Deposit Amount: ";
            cin.clear();    // clear input
            cin.ignore(10000, '\n');    // ignoring all characters to endl
        }   // end check loop for right input
        objAccount.setBalance(depo);
         cout << "New Balance: "<< objAccount.getBalance() << endl;   // set deposit
         break; // break out of loop if everything is fine
    } catch(exception &e){
        cout << e.what() <<endl;    // prompt exception
    } catch(...){
        cout << "Catch Failed!\n";  // default
    }  // throw message
    } // loop if exception occurs
    while(true){
        try{
        cout << "Withdraw:"<< endl;
        cout <<"Enter the Amount Withdraw: ";
        while(!(cin >> draw)){
              cout << "Input Error!\nPlease Enter Withdraw Amount: ";
              cin.clear();  // clear input
              cin.ignore(10000, '\n');  // ignoring all characters to endl
              } // end of check loop for right input
        objAccount.setWithDraw(draw);
        cout << "New Balance: "<< objAccount.getBalance() << endl;  // set withdraw and return the new balance
        break;  // break out of loops if everything is fine
    } catch(exception &e){
        cout << e.what()<<endl; // prompt exception
    } catch (...){
        cout << "Catch Failed\n";   // default check;
    }// throw message
    }   // loop if exception occurs
        cout <<"End OF Programming"<<endl;
        return 0;
}   // end program
