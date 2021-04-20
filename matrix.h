#ifndef __MATRIX__
#define __MATRIX__

#include "Rational.h"


typedef RatNum number;

struct index {
    int i;
    int j;
};

class Row {

private:

    number elements[];
    int length;

public:

    Row();
    
    Row operator+(const Row&) const;
    Row operator-(const Row&) const;
    Row operator*(number) const;
    Row operator/(number) const;
    Row operator*(int) const;
    Row operator/(int) const;

    number fold(number) const;            //sums the product of each element with the given integer

};

template <typename number>
class Matrix {

private:

    Row rows[];     //all elements of the matrix
    index size;             //a tuple in the form (numRows, numCols)

public:

    Matrix();               //default

    void read();            //reads terms into an empty matrix
    void print() const;     //prints entire matrix

    Matrix RowReduce(const Matrix&) const;      //returns row-reduced equivalent matrix

};





#endif