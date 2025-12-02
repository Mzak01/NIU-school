/****************************************************************************
Title: rectangle.cpp

Course: CSCI241 Assign12

Programmer: Milo Zak (z1917365)

Use: contains the member function definitions for the rectangle class.
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>

#include "rectangle.h"

using namespace std;

/***************************************************************************
Title: rectangle(const string& color, int height, int width) : shape(color)

Use: a constructor that takes a const string& argument to initialize the
     rectangle's color and two int arguments to initialize the rectangle's
     height and width. The color string should be passed to the shape
     constructor.

Return: n/a
***************************************************************************/
rectangle::rectangle(const string& color, int height, int width) : shape(color)
{
	this->height = height;
	this->width = width;
}

/***************************************************************************
Title: print()

Use: an overridden version of print() that takes no arguments and returns
     nothing. The function should call the base class print() method to
     print the rectangle's color, then print the word "rectangle" followed
     by the rectangle's height, width, and area,

Return: n/a
***************************************************************************/
void rectangle::print()
{
	shape::print();
	cout<<" rectangle, height "<<height<<", width "<<width<<", area "<<get_area()<<endl;
}

/***************************************************************************
Title: get_area()

Use: an overridden version of get_area() that takes no arguments and
     returns a double.

Return: returns the double of the area
***************************************************************************/
double rectangle::get_area()
{
	return (double)height * (double)width;
}
/***************************************************************************
Title: ~rectangle()

Use: deconstructor so it won't throw a warning

Return: n/a
***************************************************************************/
rectangle::~rectangle()
{}
