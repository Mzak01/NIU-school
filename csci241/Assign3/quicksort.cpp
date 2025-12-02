/****************************************************************************
 Quicksort.cpp
 Assignment 3   Csci241

 Author: Milo Zak (z1917365)
         Sebastian Lesny (z1868275)

 Purpose: Insert an array of numbers and sort
          the numbers back out.
****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;
int build_array(int);
void print_array(int[], int);
void quick_sort(int[], int, int);
int partition(int[], int, int);
/***************************************************************************
Function: int build_array

Use: reads num from input into AR

Arguments int n = 0

Returns: Number of values read
***************************************************************************/

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
/**************************************************************************
Function: void print_array()

Use: Prints numbers into an Array

Arguments: array--> array of integers
           n--> num of values in array

Returns: none
**************************************************************************/

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
                cout<<"       \n";
        }
}

/**************************************************************************
Function: int quick_sort()

Use: Reorders the values so numbers lower than the pivot point come before
     the pivot, and values higher go after. This goes into the sorting and
     will be sorted from there.

Arguments: array[] -> array to partition
           start -> first element of array
           end -> last element of array
           pivot -> Where the pivot occurs while sorting

Returns: pivot_index
**************************************************************************/

void quick_sort(int array[], int start, int end)
{
	//where to pivot
	int pivot;

	if( start < end)
	{
		//pivot equals where to pivot
		pivot = partition(array, start, end);

		//sorting after pivot
		quick_sort(array, start, pivot - 1);
		quick_sort(array, pivot + 1, end);
	}
}

/**************************************************************************
Function: int partition()

Use: Reorders the values so numbers lower than the pivot point come before
     the pivot, and values higher go after. This goes into the sorting and
     will be sorted from there.

Arguments: array[] -> array to partition
	   start -> first element of array
	   end -> last element of array
	   pivot_index -> The point where the pivot point is placed the int.
	   pivot_value -> The value of the pivot point
	   scan-> scans value to see where to place the pivot_index
	   temp -> holder value to swap
	   mid -> middle of the array

Returns: pivot_index
**************************************************************************/

int partition(int array[], int start, int end)
{
	//variables being used
	int pivot_index;
	int pivot_value;
	int scan;
	int temp;
	int mid;

	//finds the middle
	mid = (start + end) / 2;

	//swaps start and mid array
	temp = array[start];
	array[start] = array[mid];
	array[mid] = temp;

	pivot_index = start;
	pivot_value = array[start];

	scan = start + 1;

	//while loop to loop the sorting
	while(scan <= end)
	{
		//shows the code where to pivot the sorting
		//if that makes sense :)
		if(array[scan] < pivot_value)
		{
			pivot_index = pivot_index + 1;

			//swap pivot_index and scan
			temp = array[pivot_index];
			array[pivot_index] = array[scan];
			array[scan] = temp;
		}
		//increases scan value
		scan = scan + 1;
	}

	//swap start and pivot_index
	temp = array[start];
	array[start] = array[pivot_index];
	array[pivot_index] = temp;

	return pivot_index;
}

int main()
{
	//variable array, and num of integers being used
	int num[1000];
	int n;

	//makes n equal number of values in the array
	n = build_array(num);

	cout<<"array before sorting:"<<endl;

	print_array(num, n);

	//sorts the values in the text files
	quick_sort(num, 0, n - 1);

	cout<<"array after sorting:"<<endl;

	print_array(num, n);

	return 0;
}
