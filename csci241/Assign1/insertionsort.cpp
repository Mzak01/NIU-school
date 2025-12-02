/**********************************************************
insertion_sort.cpp
CSCI241 Assignment 1

Author: Milo Zak(z1917365)
	Sebastian Lesny (z1868275)

Use: reads integers from input, then sorts the list

Return: 0
**********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void print_array(int[], int);
void insertion_sort(int[], int);
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

      //sets up loop to print 8 intergers
      for(i = 0; i<n; i++)
      {
          cout<<setw(8)<<array[i];

          if((i + 1) % 8 == 0)
          {
                 cout<<endl;
          }
      }

      //sets space between integers
      if(i % 8 != 0)
      {
          cout<<"       \n";
      }
}

/**************************************
Function: void insertion_sort()

Use: takes values from array and sorts
         them into numerical order.

Arguments: i --> integers
           j --> a good boy
           imin --> minimum int value
           n --> list of items
           temp --> for swapping

Returns: none
**************************************/

void insertion_sort(int array[], int n)
{
	int i,
	    j,
	    temp;

	i = 1;

	//sorts integers
	while(i < n)
	{
		j = i;
		while((j > 0) && (array[j - 1] > array [j]))
		{
			//swaps integers between places
			temp = array [j - 1];
			array [j - 1]=array[j];
			array [j]= temp;

			j = j - 1;
		}
		i = i + 1;
	}
}


int main()
{
	int n;
	int num[1000];
	
	
	//n comes from txt so it knows
	//where to get int from
	n = build_array(num);

	cout<<"Array before sorting"<<endl;

	print_array(num, n);

	insertion_sort(num, n);

	cout<<"Array after sorting"<<endl;

	print_array(num, n);


	return 0;
}
