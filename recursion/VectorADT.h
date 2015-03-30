#ifndef VECTORADT_H
#define VECTORADT_H
#include <vector>
#include <ostream>

class VectorADT
{
    public:
        VectorADT();
        virtual ~VectorADT();
        unsigned int capacity();
        unsigned int isEmpty();
        friend operator<<(ostream&, const VectorADT) const;
    protected:
    private:
        unsigned int insert(int);
        unsigned void erase(int);
        unsigned void popBack();
        unsigned void pushBack();
        unsigned void resize(int );
        unsigned void shrinkToFit();
        unsigned void size();
        unsigned vector<double>vect();
        unsigned int size;
};

#endif // VECTORADT_H
