#include "ArrayADT.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    ArrayADT ary;
    int end, tempSize = 5;
    double element;
    double temp[] = {23.43 , 113.54 , 2143.42 , 65.98 , 2.23};
    cout << "Test I\nThe Insertion And Erase\n";
    ary.insert(0, 12.12);
    ary.insert(1, 32.32);
    ary.insert(2, 123.123);
    ary.insert(3, 3.23);
    cout <<"Print Array After Insertion:\n";
    cout << ary;
    ary.erase(2);
    cout<< "Print Array After Erase:\n";
    cout << ary;
    cout<<"Test II\nInsert And Delete More Than One Elements\n";
    ary.insert(temp, tempSize, 2);
    cout<< "Print Array After New Insert:\n";
    cout << ary;
    ary.erase(2,4);
    cout<<"Print Array After Deleting Elements\n";
    ary.shrinkToFit();  // resize array to all filled element indexes only
    cout << ary; // print
    cout << "Overload Operators\n";
    ArrayADT newAry = ary;
    cout <<"Array:\n";
    cout <<  ary;
    cout <<"Assigned:\n";
    cout << newAry;
    return 0;
}
