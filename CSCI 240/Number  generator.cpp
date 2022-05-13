/***************************************************************
CSCI 240         Program 4    Fall 2021

Programmer: Milo Zak, sebastian lesny

Section: CSCI 240

Date Due: Sept. 24, 2021

Purpose: This prgram will generate three sets of random numbers.
***************************************************************/


#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main()
{
	//seed
	srand(23);
	
	//variables
	int number,
		size, 
		i = 1,
		rowsize1 = 5,
		rowsize2 = 7,
		rowsize3 = 8,
		valuemax1 = 25,
		valuemax2 = 50,
		valuemax3 = 250,
		randmax = 100;
		  
	
	//first set of random numbers
	cout<<"First set of numbers. "<<endl<<endl;
	
		//for loop
	for(int cnt = 0; cnt<valuemax1; cnt+=1)
	 { 
	 	//make that number random yeah boyyyyyyyyyyyyyyy
	 number = rand();
	 
	 	//outputs rows
	 size++;
	 cout<<setw(10)<<number<< " ";
	 if (size % rowsize1 == 0) cout<<endl;
	 
	}
	//second set of random numbers
	cout<<endl<<"Second set of numbers."<<endl<<endl;
	
		//setting amount of numbers
	size=rand() % valuemax2 + 1;

		//while loop
	while(i<size)
	{
		number=rand();
		cout<<setw(10)<<number<<" ";	
		i++;
		
		//making rows (maybe its a column i get them confused)
		if(i % rowsize2==0)
		{
			cout<<endl;
		}
	
	}
	//third set of random numbers
	cout<<endl<<"Third set of numbers."<<endl<<endl;
	
		//setting amount of num shown
	size = (rand() % valuemax3 + 41);

	//show number
	i = 1;
		
		//loopy loop
	do
	{
		//makes it show 1-100
		number = 1 + (rand() % (randmax - 1 + 1));
		cout<<setw(10)<<number<<" ";
		
		//rows 
		if(i % rowsize3==0)
		{
			cout<<endl;
		}
		i++;
	}
	while (i <= size);
	
	return 0;	
}




