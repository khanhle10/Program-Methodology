#ifndef RECURSIONADT_H
#define RECURSIONADT_H
#include <iostream>
using namespace std;
class recursionADT
{
    public:

        recursionADT();//constructor
        void setArraySize(int); //mutator
        int getSize() const;  //acessor
        int passIndex() const;
        void setIndex(int);
        int getElementArray(int index) const; //accessor
        void setElements(int index, int input); // mutator
        void promptInput(); // promt
        void printReverseArray(int);
        void searchLargest(int&, int&);
        int searchLargestK(int, int, int);
        int partition(int, int);
        void quickSort(int, int );
      //  friend ostream &operator<<(ostream &out, const recursionADT &recur);  // print object

    private:
        int ary[];
        int size;
        int index;
};

#endif // RECURSIONADT_H
