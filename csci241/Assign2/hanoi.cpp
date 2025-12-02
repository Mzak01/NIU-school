/*********************************************
 Towers of Hanoi
 Assignment 2   Csci241

 Author: Milo Zak (z1917365)
         Sebastian Lesny (z1868275)

 Purpose: Design an algorithm which prints
 	  the percise sequence of disk
 	  peg-to-peg transfers.
*********************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

//prototype
void move(int, int, int, int);

/*********************************************
Function: void move

Arguments: n--> number of disks
	   peg1--> The first peg the disks 
		   start at
	   peg2--> The second peg of the set
	   peg 3 --> The third peg of the set

use: Move the disks from peg to peg

return: nothing
*********************************************/

void move(int n, int start_peg, int Dest_peg, int temp_peg)
{
	//move start to end if it matched
	if(n == 1)
	{
		cout << n <<"  " <<start_peg<<" -> "<<Dest_peg<<endl;
		return;
	}
	else
	{
	//move n-1 disk from start to temp
	move(n-1,start_peg,temp_peg,Dest_peg);

	cout<<n<<"  "<<start_peg<<" -> "<<Dest_peg<<endl;

	//moves n-1 disks from temp to dest
	move(n-1,temp_peg, Dest_peg,start_peg);
	}
}
//main program
int main(int argc, char* argv[])
{
	//initializing and giving values numbers
	int n;
	int start_peg = 1;
	int temp_peg = 2;
	int Dest_peg = 3;

	//no input there is an error
	if(argc == 1)
	{
		cout<<"Missing argument\n"
		    <<"Usage: hanoi number-of-disks\n";
		exit(1);
	}

	//if it is not a number it generates an error
	for(int i = 0; argv[1][i] != '\0'; i++)
	{
		if(!isdigit(argv[1][i]))
		{
			cout<<"Argument must be a number\n"
			    <<"Usage: hanoi number-of-disks\n";
			exit(1);
		}
	}

	//make n = to the array of disks from command line
	n = stoi(argv[1]);

	//calling function
	move(n, start_peg, temp_peg, Dest_peg);
	return 0;
}
