#include <iostream>
#include "LinkedList_structNode.h"

using namespace std;

int main()
{

    List aList = new List;
    aList.insert(0,8);
    aList.insert(1,132);
    aList.insert(2,345);
    aList.insert(3,554);
    cout << "Print List:\n";
    cout << aList;
    aList.reserve();
    cout << "Print Reverse List:\n";
    cout << aList;
    List bList = aList;
    cout << "Print Assigned List:\n";
    cout << bList;
    return 0;
}
