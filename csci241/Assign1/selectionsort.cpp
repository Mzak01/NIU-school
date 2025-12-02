/*********************************************
 Selection Sort
 Assignment 1   Csci241

 Author: Milo Zak (z1917365) 
 	 Sebastian Lesny (z1868275)
 	 
 Purpose: Insert an array of numbers and sort
	  the numbers back out.
*********************************************/

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

//function prototypes
void print_array(int[], int);
void selection_sort(int[], int);
int build_array(int[]);

/***********************************
Function: int build_array

Use: reads num from input into AR
	
Arguments int n = 0
	
Returns: Number of values read
************************************/

int build_array(int array[])
{
	int n = 0;
	
	//puts values into array until
	//end of input
	
	while(cin>>array[n])
	{
		n++;
	}
	
	return n;
}
/************************************
Function: void print_array()

Use: Prints numbers into an Array

Arguments: array--> array of integers
		   n--> num of values in array

Returns: none
**************************************/

void print_array(int array[], int n)
{
	int i;

	//prints rows of 8
	for(i = 0; i<n; i++)
	{
		cout<<setw(8)<<array[i];

		if((i + 1) % 8 == 0)
		{
			cout<<endl;
		}
	}

	//adds spaces and enters for a
	//row when it hits 8.
	if(i % 8 != 0)
	{
		cout<<"  \n";
	}
}

/**************************************
Function: void selection_sort

Use: takes values from array and sorts
	 them into numerical order.

Arguments: i --> integers
		   j --> a good boy
		   imin --> minimum int value
		   n --> list of items

Returns: none
**************************************/

void selection_sort(int array[], int n)
{
	int i,
	    j,
	    imin,
	    temp;

	i = 0;

	//looping sorting :)
	while(i<n-1)
	{
		imin = i;
		j = i + 1;
		
		while(j<n)
		{
			if(array[j] < array[imin])
			{
				imin = j;
			}
		j = j+1;
		}
		//swap
		temp = array[i];
		array[i] = array[imin];
		array[imin] = temp;

		//very important
		i = i + 1;
	}
}


int main()
{
	int num[1000];
	int n;

	//n is the txt file so it says the 
	//num is the array
	n = build_array(num);

	cout<<"Array before sorting"<<endl;

	print_array(num, n);

	selection_sort(num, n);

	cout<<"Array after sorting"<<endl;
	
	print_array(num, n);

	cout<<"\n";
	
	return 0;
}

