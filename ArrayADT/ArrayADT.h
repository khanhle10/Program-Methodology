#ifndef ARRAYADT_H
#define ARRAYADT_H
#include <ostream>

class ArrayADT
{
    public:
        ArrayADT();
        virtual ~ArrayADT();
        ArrayADT(const ArrayADT&);
        ArrayADT& operator=(const ArrayADT&);
        int capacity();
        bool isEmpty();
        friend std::ostream &operator<<(std::ostream&, const ArrayADT&);
        void insert(int, double );  // insert a value at an index position in the array pointer
        void insert(double[], int, int);    // inserting a array starting at a position in the array pointer
        void erase(int);    // erasing a value in the array pointer at an index position.
        void erase(int, int);  // erasing a large chuck of the array pointer starting from a fixed size array.
        void popBack();
        void pushBack(double);
        void reSize(int);
        void shrinkToFit();
        int arySize();
        double getElement(int);
    protected:
    private:
        double *ptrAry;
        int  size;
        int  elementSize;
};

#endif // ARRAYADT_H
