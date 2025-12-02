/****************************************************************************
Title: shape.h

Course: CSCI 241   Assign12

Programmer: Milo Zak (z1917365)

Use: Contains the class definition for the abstract shape class.
****************************************************************************/

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;
class shape
{
	private:
		//shapes color
		string color;

	public:
		//default construction
		shape() = default;

		//color construction
		shape(const string& color);

		//deconstructor
		virtual ~shape();

		//print color
		virtual void print() const;

		//get area
		virtual double get_area() = 0;
};

#endif
