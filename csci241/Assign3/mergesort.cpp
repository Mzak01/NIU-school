/****************************************************************************
 Merge Sort
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
void merge_sort(int[], int, int);
void merge(int[], int, int, int);
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
/************************************************************************
Function: void merge_sort()

Use: Takes numbers and sorts them into sublists. Then uses merge function
     to make one long run at the end.

Arguments: array = array of variables being sorted
           start = starting number of array
           end = last number (largest) of the array
           mid = middle of the array of integers
           merge = function which merges the sublists together from smallest
           to largest

Returns: None
***********************************************************************/

void merge_sort(int array[], int start, int end)
{
	int mid;

	//how to divide into sublists
	if(start < end)
	{
		//find middle of a sublist of array
		mid = (start + end) / 2;

		//seperates the sublists
		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, end);

		//merges sublists back together to one long run
		merge(array, start, end, mid);
	}
}

/*********************************************************************
Function: void merge()

Use: Takes sublists divided by merge sort and puts them into one
     large run of integers. This run uses all int and goes small to large

Arguments: array = array of integers being used
	   start = start of of array
	   mid = middle of array
	   end = end of array
	   temp = temp holder of array
	   i = equivilant to start to put into while loops
	   j = one above the middle to put into while loops (helps find mid)
	   k = subscript of first element in the array. Once it gets filled
	       goes to the next subscript in array.

Returns: None
*********************************************************************/

void merge(int array[], int start, int end, int mid)
{
	//setting variables
	int temp[end-start+1];
	int i = start;
	int j = mid + 1;
	int k = 0;

	//first while loop to figure out first int in array
	while(i <= mid && j <= end)
	{
		if(array[i] < array[j])
		{
			//temp is = to start of array
			temp[k] = array[i];

			k++;
			i++;
		}
		else
		{
			//temp is not = to start
			temp[k] = array[j];

			k++;
			j++;
		}
	}

	//second loop to find next few integers before mid
	while(i <= mid)
	{
		temp[k] = array[i];

		i++;
		k++;
	}

	//finds int from mid to end, one int at a time
	while(j <= end)
	{
		temp[k] = array[j];
		j++;
		k++;
	}

	//copys the array of temp back into main array.
	//completes the orginal array without this there
	//will be a segmentation fault.
	for(i = start; i <= end; i++)
	{
		array[i] = temp[i-start];
	}
}

int main()
{
	//setting variables
	int num[1000];
	int n;

	//n = number or of int in array
	n = build_array(num);

	cout<<"Array before sorting:"<<endl;

	print_array(num, n);

	cout<<"Array after sorting:"<<endl;

	merge_sort(num, 0, n - 1);

	print_array(num, n);

	return 0;
}
