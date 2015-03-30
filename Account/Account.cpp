#include "Account.h"

Account::Account():balance{0.0}
{
    //ctor
}
/*
    Pass by value of amount to initialize balance
    Function: initialize balance
*/
Account::Account(double amount)
{
    balance = amount;
}
double Account::getBalance() const
{
    return balance; // return balance
}
/*
    pass by value of the amount deposit
    Function: updating the balance by adding adding the amount deposit or return throw exception if amount deposit is negative
*/
void Account::setBalance(double amount)
{
    ExceptionADT_Negative_Deposit msgd;
    if (amount > 0){
			balance += amount;  // update new balance
	}else{
			throw msgd; // throw error of amount is less than zero
	}
}
/*
    Pass by value of amount withdraw
    Function: update new balance by substracting amount withdraw from balance and return new balance or return thrown exception if amount is negative or amount is larger than balance
*/
void Account::setWithDraw(double amount)
{
    ExceptionADT_Negative_Withdraw msgw;
    ExceptionADT__Overdraw msgo;
    if(amount > balance){
       throw msgo;  // exception for withdraw amount larger than balance
    }else if (amount < 0){
        throw msgw; // exception for amount less than zero
    }else {
			balance -= amount;  // update balance after withdraw
        }
}/*
ExceptionADT_Negative_Deposit::ExceptionADT_Negative_Deposit()
{
    error = "Caught Negative Deposit Exception!\n";
}
string ExceptionADT_Negative_Deposit::what()
{
    return error;
}
ExceptionADT_Negative_Withdraw::ExceptionADT_Negative_Withdraw()
{
    error = "Caught Negative Withdraw Exception!\n";
}
string ExceptionADT_Negative_Withdraw::what()
{
    return error;
}
ExceptionADT_Negative_Overdraw::ExceptionADT_Negative_Overdraw()
{
    error = "Caught Overdrawn Exception!\n";
}
string ExceptionADT_Negative_Overdrawn::what()
{
    return error;
}
ExceptionADT_Input_Error::ExceptionADT_Input_Error()
{
    error = "Caught Invalid Input\n";
}
string ExceptionADT_Input_Error::what()
{
    return error;
}
*/
