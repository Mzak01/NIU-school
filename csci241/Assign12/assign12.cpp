/****************************************************************************
Title: assign12.cpp

Course: CSCI241  Assign12

Programmer: Milo Zak (z1917365)

Use: contains the main() function, with code to create objects of the
     various classes and test them.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;
int main() {

	cout << "Printing all shapes..." << endl << endl;

	//Create Vector shapes
	vector<shape*> shape_vect;

	//CIRCLE INITIALIZE
	shape_vect.push_back(new circle("Green", 10));
        shape_vect.push_back(new circle("Orange", 5));

	//rect initial
	shape_vect.push_back(new rectangle("Red", 8, 6));
        shape_vect.push_back(new rectangle("Blue", 3, 7));

	//TRIANGLE initial
	shape_vect.push_back(new triangle("Yellow", 8, 4));
	shape_vect.push_back(new triangle("Black", 4, 10));

	//process each element in shapes
	for (size_t i = 0; i < shape_vect.size(); i++)
	{
		//Dynamic pointers
		circle* circ = dynamic_cast<circle*>(shape_vect[i]);
		rectangle* rect = dynamic_cast<rectangle*>(shape_vect[i]);
		triangle* tri = dynamic_cast<triangle*>(shape_vect[i]);

		if (circ != nullptr)
		{
			circ->print();
		}

		if (rect != nullptr)
		{
			rect->print();
		}

		if (tri != nullptr)
		{
			tri->print();
		}

	}

	cout << endl;
	cout << "Printing only circles..." << endl << endl;

	//Go through and print only circles
	for (size_t i = 0; i < shape_vect.size(); i++)
	{

		//Downcast pointers
		circle* circ2 = dynamic_cast<circle*>(shape_vect[i]);

		if (circ2 != nullptr)
		{
			circ2->print();
		}

	}

	//Go through and release memory held by vector
	for (size_t i = 0; i < shape_vect.size(); i++)
	{
		delete shape_vect[i];
	}

	return 0;

}
