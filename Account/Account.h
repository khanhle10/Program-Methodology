#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <stdexcept>
#include <iostream>
#include <exception>
using namespace std;
class Account
{
public:
    Account();  // default constructor
    Account(double);    // initialize constructor pass by value
    double getBalance() const;  // return balance
    void setBalance(double);  // deposit
    void setWithDraw(double);   // withdraw
private:
    double balance;
};
/*
    Exception if input was negative with deposit
*/
class ExceptionADT_Negative_Deposit: public exception
{
public:
    virtual const char* what() const throw(){
        return "Caught Negative Deposit Exception!\n";
    }
};
/*
    Exception if input was negative withdraw
*/
class ExceptionADT_Negative_Withdraw: public exception
{
public:
    virtual const char* what() const throw(){
        return "Caught Negative Withdraw Exception!\n";
    }
};
/*
    Exception if input was larger than balance
*/
class ExceptionADT__Overdraw: public exception
{
public:
    virtual const char* what() const throw(){
        return "Caught Overdraw Exception!\n";
    }
};
#endif // ACCOUNT_H
/*
class ExceptionADT_Negative_Deposit: public exception
{
private:
    string error;
public:
    ExceptionADT_Negative_Deposit();
    string what();
};
class ExceptionADT_Negative_Withdraw: public exception
{
private:
    string error;
public:
    ExceptionADT_Negative_Withdraw();
    string what();
};

class ExceptionADT_Overdrawn:public exception
{
private:
    string error;
public:
    ExceptionADT_Overdrawn();
    string what();
};
class ExceptionADT_Input_Error: public exception
{
private:
    string error;
public:
    ExceptionADT_Input_Error();
    string what();
};
class ExceptionADT__Input_Error: public exception
{
public:
    virtual const char* what() const throw(){
    return "Caught Input Error Exception\n";
    }
};
*/

