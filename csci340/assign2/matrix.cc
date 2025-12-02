/*
    Milo Zak
    Z1917365
    CSCI340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/


#include <iostream>
#include <iomanip>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <cassert>
#include "matrix.h"

using namespace std;

/*
func: matrix::matrix(unsigned int rows, unsigned int cols)

Arg: Initialize the matrix class as needed and use resize() to
     initialize the matrix size using rows and cols.

Ret: none
*/
matrix::matrix(unsigned int rows, unsigned int cols)
{
    resize(rows, cols);
}


/*
func: void matrix::resize(unsigned int rows, unsigned int cols)

Arg: Resize the mat vector to have rows elements and then resize each
     of those elements (which are vectors themselves) to have cols elements.

Ret: none
*/
void matrix::resize(unsigned int rows, unsigned int cols)
{
    mat.resize(rows);

    for(unsigned int amount = 0; amount < rows; ++amount)
    {
        mat[amount].resize(cols);
    }
}


/*
func: void matrix::load(istream &is)

Arg: Read the input values from the given input stream is and store them
     into the two-dimensional matrix mat by using the matrix::at() accessor.
     The number of rows and columns are the pair of values given at the
     beginning of the data file. This will use the resize() method to
     dimension the matrix with the proper number of rows and columns and then
     set the values of the matrix one at-a-time by using the extraction
     operator >> and the matrix::at() accessor.

Ret: none
*/
void matrix::load(istream &is)
{
    unsigned int row;
    unsigned int col;

    is >> row;
    is >> col;

    resize(row, col);

    for(unsigned int num_row = 0; num_row < row; ++num_row)
    {
        for(unsigned int num_col = 0; num_col < col; ++num_col)
        {
            is >> at(num_row, num_col);
        }
    }
}

/*
func: void matrix::print(int colWidth) const

Arg: Print the heading as seen in the reference output, a properly
     sized header line, the values of the matrix elements with vertical
     lines between each one, and a properly sized footer line

Ret: none
*/
void matrix::print(int colWidth) const
{
    colWidth++;

    cout<<getRows()<<" x "<<getCols()<<endl;

    for(unsigned int dashes = 0; dashes < getCols(); ++dashes)
    {
        cout<<"---------";
    }
    cout<<"-\n";

    for(unsigned int dashes = 0; dashes < getRows(); ++dashes)
    {
        for(unsigned int sep = 0; sep < getCols(); ++sep)
        {
            cout<<"|"<<setw(colWidth)<<at(dashes,sep)<<" ";
        }
        cout<<"|\n";
    }

    for(unsigned int dashes = 0; dashes < getCols(); ++dashes)
    {
        cout<<"---------";
    }
    cout<<"-\n";
}


/*
func: matrix matrix::operator*(const matrix &rhs) const

Arg: Implement matrix multiplication using an overloaded operator.

Ret: noen
*/
matrix matrix::operator*(const matrix &rhs) const
{
    unsigned int left_row = (*this).getRows(),
                 right_row = rhs.getRows(),
                 left_col = (*this).getCols(),
                 right_col = rhs.getCols();

    assert(left_col == right_row);

    matrix product(left_row, right_col);

    for(unsigned int i = 0; i < left_row; ++i)
    {
        for(unsigned int j = 0; j < right_col; ++j)
        {
            for(unsigned int k = 0; k < left_col; ++k)
            {
                product.at(i,j) += (*this).at(i,k) * rhs.at(k,j);
            }
        }
    }
    return product;
}
