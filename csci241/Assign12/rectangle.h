/****************************************************************************
Title: rectangle.h

Course: CSCI241 Assign12

Programmer: Milo Zak (z1917365)

Use: contains the class definition for the rectangle class.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "shape.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class rectangle:
	public shape
{
	private:
		int height;
		int width;
	public:
		//default cosnt
		rectangle() = default;

		//initalize const
		rectangle(const string&, int, int);

		//deconstructor
		~rectangle();

		//print
		virtual void print();

		//area
		virtual double get_area();

};

#endif
