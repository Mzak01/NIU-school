/****************************************************************************
Title: circle.cpp

Course: CSCI 241   Assign12

Programmer: Milo Zak (z1917365)

Use: contains the member function definitions for the circle class.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "circle.h"

using namespace std;

/***************************************************************************
Title: circle(const sting& color, int radius) : shape(color)

Use: a constructor that takes a const string& argument to initialize the
     circle's color and an int to initialize the circle's radius. The color
     string should be passed to the shape constructor using a constructor
     initialization list.

Return: n/a
***************************************************************************/
circle::circle(const string& color, int radius) : shape(color)
{
	this->radius = radius;
}

/***************************************************************************
Title: ~circle()

Use: deconstructor so warning wont pop up

Return: n/a
***************************************************************************/
circle::~circle()
{}

/***************************************************************************
Title: print()

Use: an overridden version of print() that takes no arguments and returns
     nothing. The member function should call the base class print() method
     to print the circle's color, then print the word "circle", followed by
     the circle's radius and area

Return: n/a
***************************************************************************/
void circle::print()
{
	shape::print();

	//printing things
	cout<<" circle, radius "<<radius<<", area "<<get_area()<<endl;
}

/***************************************************************************
Title: get_area()

Use: an overridden version of get_area() that takes no arguments and returns
     a double. This method should compute and return the circle's area based
     on its radius.

Return: returns a double of the area of the circle
***************************************************************************/
double circle::get_area()
{
	return M_PI * pow(radius, 2);
}

