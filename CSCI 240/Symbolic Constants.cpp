/***************************************************************
CSCI 240         Program 2     Fall 2021

Programmer: Milo Zak

Section: CSCI 240

Date Due: 9/10/21

Purpose: This Program should calculate the number of 
	     slices a pizza can be divided into and the number 
		 of pizzas that a customer should order to feed a 
		 certain number of people.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	// variables
	
	float  Pizza_Area,
		   Pizza_Radius,
		   Num_of_People,
		   Num_of_Slices,
		   Total_Slices,
		   Pizza_Amount,
		   Diameter;
	
	double Slice_Area = 14.125,
		   PI		   = 3.14159,
		   Slices_Eaten = 4;
	
	// user input system
	
	cout << " How many people need to be fed? ";
	cin >> Num_of_People;
	
	cout << " What is the diameter (in inches) of the pizza? ";
	cin>> Diameter;
	cout <<" "<<endl;
	
	//math for system
	
	Pizza_Radius = Diameter/2;
	Pizza_Area = PI * (Pizza_Radius * Pizza_Radius);
	Num_of_Slices = Pizza_Area / Slice_Area;
	Total_Slices = Slices_Eaten * Num_of_People;
	Pizza_Amount = Total_Slices /  Num_of_Slices;
	
	//output
	
	cout << "A "<<Diameter<<" inch pizza has "<< setprecision(3)<<Num_of_Slices<<" slices."<<endl<<endl;
	cout << "To feed "<<Num_of_People <<" people order "<< setprecision(2)<<Pizza_Amount<<" pizzas."<<endl<<endl;
	
	return 0;
	
}
