#ifndef EXCEPTIONADT_H
#define EXCEPTIONADT_H
#include <stdexcept>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class ExceptionADT_ID_Not_Found:public exception
{
    public:
        virtual const char* what() const throw()
        {
            return "ID Not Found Exception!\n";
        }
}msginf;  // exception to return message

#endif // EXCEPTIONADT_H
