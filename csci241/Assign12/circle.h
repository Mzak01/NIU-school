/****************************************************************************
Title: circle.h

Course: CSCI 241   Assign12

Programmer: Milo Zak (z1917365)

Use: contains the class definition for the circle class.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

using namespace std;

class circle:
	public shape
{
	private:
		//radius of circle
		int radius;
	public:
		//default const
		circle() = default;

		//color and radius const
		circle(const string &, int);

		//deconstruct
		~circle();

		//print
		void print();

		//finding the area
		double get_area();

};

#endif
