/*****************************************************************
Title: complex.cpp

Course: CSCI241  Assign6

Author: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: This holds all of the function definitions for the complex
     class. This classes job is to create a new data type to
     process complex numbers. (Because Kurt said so)
*****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <tuple>
#include <regex>
#include "complex.h"

using namespace std;

//I put the constructors in two classes to help with my understanding

/***************************************************************
Class: complex

Arguments: nothing, just setting everything to zero

Use: constructs the class and puts a setting mark to zero

Returns: none
***************************************************************/
complex::complex()
{
	set_complex(0,0);
}

/***************************************************************
Class: complex

Arguments: double r - represents the real part
	   double i - represents the imaginary part

Use: constructs the class and puts a setting mark to (r, i)
     putting r and i to (0,0)

Returns: none
***************************************************************/
complex::complex(double r, double i)
{
	set_complex(r,i);
}

/***************************************************************
Class: set_complex

Arguments: double real_part - represents the real part
           double imaginary_part - represents the imaginary part
	   double r - real number
	   double i - imaginary number

Use: Assign function parameters to data members

Returns: none
***************************************************************/
void complex::set_complex(double r, double i)
{
	imaginary_part = i;
	real_part = r;
}

/***************************************************************
Class: get_complex

Arguments: r - real part of complex num
	   i - imaginary part of complex num

Use: return result by make_tuple(), passing it the real and
     imaginary part. (single return line)

Returns: a tuple
***************************************************************/
void complex::get_complex(double& r, double& i) const
{
	r = get_real();
	i = get_imaginary();
	make_tuple(r, i);
}

/***************************************************************
Class: set_real

Arguments: double r - represents the real num
	   double real_part - represents real part

Use: Assign the function parameter to the real part data mem.
     of the object

Returns: none
***************************************************************/
void complex::set_real(double r)
{
	real_part = r;
}


/***************************************************************
Class: get_real

Arguments: real_part - real part of the complex number

Use: Return the data member representing the real part of the
     complex number.

Returns: real part of complex (double)
***************************************************************/
double complex::get_real() const
{
	return real_part;
}

/***************************************************************
Class: set_imaginary

Arguments: double i - represents the imaginary num
	   double imaginary_part - represents the imagin part

Use: Assign the function parameter to the imaginary part data
     member of the object that called the member function.

Returns: none
***************************************************************/
void complex::set_imaginary(double i)
{
	imaginary_part = i;
}

/***************************************************************
Class: get_imaginary

Arguments: double imaginary_part - represents the imaginary part

Use: Return the data member representing the imaginary part
     of the complex number.

Returns: imaginary part of the complex(double)
***************************************************************/
double complex::get_imaginary() const
{
	return imaginary_part;
}

/***************************************************************
Class: Operator+

Arguments: double i - represents the imaginary number
	   douvle r - real number
	   result - result of addition in ()

Use:  Declare a complex object to hold the result of the
      arithmetic. You will need to set the real part and the
      imaginary part of this result object to the correct values,
      as outlined in the ordered pair version of the addition
      rule shown at the beginning of the assignment sheet.
      Once you've done the arithmetic, return the result object.

Returns: A complex object that holds the result of the arithmetic.
***************************************************************/
complex operator+(const complex& lhs, const complex& rhs)
{
	double r;
	double i;

	r = lhs.get_real() + rhs.get_real();
	i = lhs.get_real() + rhs.get_imaginary();
	complex result(r,i);

	return result;
}

/***************************************************************
Class: operator*

Arguments: double i - represents the imaginary number
           douvle r - real number
           result - product from multiplication

Use: Declare a complex object to hold the result of the arithmetic.
     You will need to set the real part and the imaginary part of
     this result object to the correct values, as outlined in
     the ordered pair version of the multiplication rule shown
     at the beginning of the assignment sheet. Once you've done
     the arithmetic, return the result object.

Returns: a complex object holding the result of the artihmetic
***************************************************************/
complex operator*(const complex& lhs, const complex& rhs)
{
	double r;
	double i;

	r =  lhs.get_real() * rhs.get_real() - lhs.get_imaginary() * rhs.get_imaginary();
	i = lhs.get_real() * rhs.get_imaginary() + lhs.get_imaginary() * rhs.get_imaginary();

	complex result(r,i);
	return result;
}

/***************************************************************
Class: operator==()

Arguments: false - does not output right
	   true - everything matches pretty

Use: The member function should return true if the real part of
     the left operand equals the real part of the right operand
     AND the imaginary part of the left operand equals the
     imaginary part of the right operand. Otherwise, the member
     function should return false.

Returns: boolean value (true or false)
***************************************************************/
bool operator==(const complex& lhs, const complex& rhs)
{
	if(lhs.get_real() != rhs.get_real())
    	{
        	return false;
        }
    	if(lhs.get_imaginary() != rhs.get_imaginary())
        {
        	return false;
        }

    	return true;
}
/***************************************************************
Class: get_string()

Argument: output - the output of the strings

Use: used to show string of the complex number (used in i and o)

Return: string of complex things
***************************************************************/
string complex::to_string() const
{
	ostringstream strs;
    	strs << get_real();
    	string output = "("+strs.str()+",";
    	strs.str("");
    	strs << get_imaginary();

    	output = output+strs.str()+")";

    	return output;
}

/***************************************************************
Class: operator<<()

Arguments: double i - represents the imaginary part
	   os - outstream of the number
	   c - grabs from to stream :)

Use: Prunt a cimplex object as an ordered pair: (real, img)

Returns: referncce to an ostream object
***************************************************************/
ostream& operator<<(ostream& os, const complex& c)
{
	os<<c.to_string()+" ";
	return os;
}

/***************************************************************
Class: operator>>()

Arguments: double i - represents the imaginary number
	   is - in stream file
	   str - string file grabbing from string to help :)
	   vector<double> vect - vector becayse main has it
	   douvle r - real number
	   real_part - real part of complex number
	   imaginary_part - imaginary part of the complex number
	   c - grabs from string

Use: read input entered by the user as an ordrred pair of the
     form: (real, img)

Returns: referncce to an istream object
***************************************************************/
istream& operator>>(istream& is, complex& c)
{
	vector<double> vect;
	string str;
	is >> str;

	int j = 0;
	double i;

	//compare to remove parathesis
	while((unsigned)j<str.size())
	{
		if(str[j] == '(' || str[j] == ')')
		{
			str.erase(j,1);
		}
		else
		{
			//counter to remove
			j++;
		}
	}

	stringstream ss(str);

	//remove comma :()
	while(ss>>i)
	{
		if(ss.peek() == ',')
		{
			ss.ignore();
		}

		vect.push_back(i);
	}

	if(vect.size() == 2)
	{
		c.set_complex(vect[0],vect[1]);
	}
	else
	{
		cout<<"***Error***\n";
		c.set_complex(0,0);
	}
	return is;
}
