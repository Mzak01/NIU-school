/****************************************************************************
Title: triangle.cpp

Course: CSCI241 Assign12

Programmer: Milo Zak (z1917365)

Use: contains the member function definitions for the triangle class.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>

#include "triangle.h"
using namespace std;

/***************************************************************************
Title: triangle(const string& color, int height, int base) : shape(color)

Use: a constructor that takes a const string& argument to initialize the
     triangle's color and two int arguments to initialize the triangle's
     height and base. The color string should be passed to the shape
     constructor.

Return: n/a
***************************************************************************/
triangle::triangle(const string& color, int height, int base) : shape(color)
{
	this->height = height;
	this->base = base;
}

/***************************************************************************
Title: print()

Use: an overridden version of print() that takes no arguments and returns
     nothing. The method should call the base class print() method to print
     the triangle's color, then print the word "triangle" followed by the
     triangle's height, base, and area

Return: n/a
***************************************************************************/
void triangle::print()
{
	shape::print();

	cout<<" triangle, height "<<height<<", base "<<base<<", area "<<get_area()<<endl;
}

/***************************************************************************
Title: get_area()

Use: an overridden version of get_area() that takes no arguments and returns
     a double. This method should compute and return the rectangle's area
     based on its height and width.

Return: double of the area of the triangle
***************************************************************************/
double triangle::get_area()
{
	return double(height)*double(base)/2.0;
}
/***************************************************************************
Title: ~triangle()

Use: deconstructor to make sure there is no error thrown

Return: n/a
***************************************************************************/
triangle::~triangle()
{}
