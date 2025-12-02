/****************************************************************************
Title: triangle.h

Course: CSCI241 Assign12

Programmer: Milo Zak (z1917365)

Use: contains the class definition for the triangle class.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "shape.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

using namespace std;

class triangle:
	public shape
{
	private:
		int height;
		int base;
	public:
		//default const
		triangle() = default;

		//copy const
		triangle(const std::string&, int, int);

		//deconsy
		~triangle();

		//print
		void print();

		//area
		double get_area();
};

#endif
