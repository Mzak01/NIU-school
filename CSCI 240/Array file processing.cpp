/***************************************************************
CSCI 240         Program 7     Fall 2021

Programmer: Milo Zak, Sebastian Lesny

Section: CSCI 240

Date Due: October 22, 2021

Purpose: For this assignment, write a program that will process 
		 two sets of numeric information. The information will
	  	 be needed for later processing, so it will be stored in
		 two arrays that will be displayed, sorted, and
		 displayed (again).
***************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

//const define
#define upperb 250.0
#define lowerb 1.0
#define maxval 75
#define minval 25
#define lineoutput 12

using namespace std;

//function define
double randdouble()
{
	//generating and return rand val
	double randomval = lowerb + ((rand()* 1) / (RAND_MAX / (upperb - lowerb)));
	return randomval;
}

int buildrandom(double array[])
{
	//size and total values
	int totalel = minval + (rand() % (maxval - minval + 1));
	for(int i = 0; i < totalel; i++)
	{
		array[i] = randdouble();
	}
	return totalel;
}

void print(string title, double array[], int numofvalues)
{
	//makes 12 rows
	cout<<title<<endl;
	for(int i = 0; i < numofvalues; i++)
	{
		//actually putting 12 rows per line
		for(int j = i; i + lineoutput && j < numofvalues; ++j)
		{
			cout<<setw(8)<<setprecision(2)<<fixed<<array[j]<<" ";
		}
	i += 11;
	cout<<endl;
	}
}

void sort(double array[], int numofvalues)
{
	 // sorting algorithm
    int minposition;
    for (int i = 0; i < numofvalues; ++i)
	 {
        minposition = i;
        for (int j = i + 1; j < numofvalues; ++j) 
		{
            // set minposition to j if less than
            if (array[j] < array[minposition]) 
			{
                minposition = j;
            }
        }
        // swapping the elements around 
        double temp = array[minposition];
        array[minposition] = array[i];
        array[i] = temp;
	 }
}

int buildfile(double array[])
{
	//input file stream
	ifstream inputFileStream;
	inputFileStream.open("nums.txt");
	//error message for file can't be opened
	if(!inputFileStream.is_open())
	{
		cout<<"File cannot open, please check!";
		exit(0);
	}
	//set index 0
	int subscript = 0;
	while (!inputFileStream.eof())
	{
		//store value
		double currentval;
		inputFileStream >> currentval;
		 array[subscript++] = currentval;
	}
	//closing
	inputFileStream.close();
	//reuturn it cause it has everything
	return subscript;
}

int main()
{
	//random seed
	srand(52);
	
	//create array rando doubles
	double array[maxval];
	double filearray[maxval];
	
	//creates array of random doubles
	int totalel = buildrandom(array);
	
	//showing total number of values
	cout<<"Total number of elements: "<<totalel<<"\n";
	
	string printString = "Array of random numbers";
	print(printString, array, totalel);
	
	cout<<endl;
	
	//sorting the values from array
	sort(array, totalel);
	
	string sortedPrintString = "Sorted array of random numbers";
	print(sortedPrintString, array, totalel);
	
	cout<<endl;
	
	//reading from text file
	int totalfilearrayel = buildfile(filearray);
	
	cout<<"Total number of elements: "<<totalfilearrayel<<endl;
	
	//display
	string printFileString = "Array of file elements";
	print(printFileString, filearray, totalfilearrayel);
	
	//sorting
	sort(filearray, totalfilearrayel);
	
	//display
	string sortedPrintFileString = "Sorted Array of File Elements";
	print(sortedPrintFileString, filearray, totalfilearrayel);
}
