/****************************************************************************
Title: shape.cpp

Course: CSCI241 Assign12

Programmer: Milo Zak (z1917365)

Use: Contains the member function definitions for the abstract shape class.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "shape.h"

using namespace std;

/***************************************************************************
Title: shape(const string& color)

Use: a constructor that takes a const string& argument and uses it to
     initialize the shape's color

Return: n/a
***************************************************************************/
shape::shape(const string & color)
{
	this->color = color;
}

/***************************************************************************
Title: ~shape()

Use: The method body for this destructor can be empty, since it does not
     need to delete any dynamic storage. However, if you don't have a
     virtual destructor for an abstract base class, the compiler may
     produce a warning message.

Return: n/a
***************************************************************************/
shape::~shape()
{}

/***************************************************************************
Title: void print() const

Use: a virtual member function called print() that takes no arguments and
     returns nothing. It should be const. The function should print the
     color.

Return: n/a
***************************************************************************/
void shape::print() const
{
	cout << color;
}
