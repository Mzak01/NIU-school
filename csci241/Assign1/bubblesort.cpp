/*********************************************
 Bubble_sort
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
void bubble_sort(int[], int);
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
	
        for(i = 0; i < n; i++)
        {
        	cout<<setw(8)<<array[i];

        	if((i+1) % 8 == 0)
        	{
        		cout<<endl;
        	}
	}
        	if(i % 8 != 0)
        	{
        	cout<<"        \n";
        	}
        
}

/**************************************
Function: void bubble_sort

Use: takes values from array and sorts
         them into numerical order.

Arguments: i --> integers
           j --> a good boy
           swapping --> variable for swapping
           n --> list of items

Returns: none
**************************************/

void bubble_sort(int array[], int n)
{
	int temp,
	    i,
	    swapped;

	do
	{
		swapped = false;
		i = 1;

		while(i < n)
		{
			if(array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;

				swapped = true;
			}
			i = i + 1;
		}
	}
	while(swapped);
}



int main()
{
	int n;
	int num[1000];
	
	n = build_array(num);

        cout<<"Array before sorting"<<endl;

        print_array(num, n);

        bubble_sort(num, n);

        cout<<"Array after sorting"<<endl;

        print_array(num, n);

        cout<<"\n";

	return 0;
}

