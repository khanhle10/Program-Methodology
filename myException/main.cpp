/*
    Khanh Le
    CSC 340 Methodology
    HW 5-A
    The following code uses two arrays, one to store products and another to store product ID's (a better organization would be to use a singe array of a class or struct,
    but that is not the subject of this Programming Project). The function getProductID takes as input the two arrays, the length of the arrays, and a target product to search for.
    It then loops through the product name array and if a match is found it returns the corresponding product ID:
*/

#include "ExceptionADT.h"
#include <iostream>
#include <exception>
#include <string>
using namespace std;

int getProductID(int ids[], string names[], int num, string key) throw (ExceptionADT_ID_Not_Found);
int main()
{
    cout << "Hello world!" << endl;
    int productIds[]= {4, 5, 8, 10, 13};
    string products[] = { "computer", "flash drive", "mouse", "printer", "camera" };
    try{
	cout << getProductID(productIds, products, 5, "mouse") << endl;
	cout << getProductID(productIds, products, 5, "camera") << endl;
	cout << getProductID(productIds, products, 5, "laptop") << endl;
    }catch (exception &e)
    {
        cerr << e.what() <<endl;  // message exception for not product found
    }catch(...)
    {
        cout <<"Catch Failed!\n";
    }
	return 0;
}
int getProductID(int ids[], string names[], int numProducts, string target) throw (ExceptionADT_ID_Not_Found)
{
	for (int i=0; i < numProducts; i++)
	{
		if (names[i] == target){
			return ids[i];  // return product ID
		}
	}   // loop through product string and returning product ID
	throw msginf;  // if no target string found than prompt exception
}
