/*****************************************************************
Title: complex.h

Course: CSCI241  Assign6

Author: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: This represents the class definition for complex.cpp
*****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class complex
{
	private:

		double real_part;
		double imaginary_part;

	public:
		//constructor
		complex();
		complex(double r, double i);

		//setting the complex
		void set_complex(double r, double i);
		void get_complex (double& r, double& i) const;

		//get real number
		void set_real(double r);
		double get_real() const;

		//imaginary numbers
		void set_imaginary(double i);
		double get_imaginary() const;

		//system overload
		friend complex operator+(const complex& lhs, const complex& rhs);
		friend complex operator*(const complex& lhs, const complex& rhs);
		friend bool operator==(const complex& lhs, const complex& rhs);
		friend ostream& operator<<(ostream& os, const complex& c);
		friend istream& operator>>(istream& is, const complex& c);

		string to_string() const;
};

#endif
