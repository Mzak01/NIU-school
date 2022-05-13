/***************************************************************
CSCI 240         Program 5    Fall 2021

Programmer: Milo Zak, Sebastian Lesny

Section: CSCI 240

Date Due: Oct. 8, 2021

Purpose: This program will allows the user to select an option
		 from a menu and then, based on the option, ask for 
		 more information and perform the arithmetic.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	
//variable
char selection;

int firstnum,
	secondnum,
	num,
	ans,
	modans,
	result = 1.0,
	fact = 1;

//menu selection

cout<<"\n      Menu";

cout<<"\n=================";

cout<<"\n + Addition";

cout<<"\n - Subtraction";

cout<<"\n * Multiplication";

cout<<"\n / Division";

cout<<"\n ^ Number to Power";

cout<<"\n ! Factorial";

cout<<"\n q Quit";

cout<<"\n Enter operation: ";

// read the input
cin>>selection;

//looping switch statment
while (selection != 'q' && selection != 'Q')
{

//switch statements 
switch(selection)
	{
		
	//addition
	
	case '+' :
		{
		cout<<"\nWhat is the first number to add?\n";
		cin>>firstnum;
		
		cout<<"\nWhat is the second number to add?\n";
		cin>>secondnum;
	
		ans = firstnum + secondnum;
		
		cout<<firstnum<<" + "<<secondnum<<" = "<<ans<<"\n";
		}
	break;

	//subtraction
	
	case '-' :
		{
		cout<<"\nWhat is the first number to subtract?\n";
		cin>>firstnum;
		
		cout<<"\nWhat is the second number to subtract?\n";
		cin>>secondnum;
	
		ans = firstnum - secondnum;
		
		cout<<firstnum<<" - "<<secondnum<<" = "<<ans<<"\n";
		}
	break;
	
	//multiplication
	
	case '*' :
		{
		cout<<"\nWhat is the first number to multiply?\n";
		cin>>firstnum;
		
		cout<<"\nWhat is the second number to multiply?\n";
		cin>>secondnum;
		
		ans = firstnum * secondnum;
		
		cout<<firstnum<<" * "<<secondnum<<" = "<<ans<<"\n";
		}
	break;

	//division
	
	case '/' :
		{
		cout<<"\nWhat is the dividen?\n";
		cin>>firstnum;
		
		cout<<"\nWhat is the divisor?\n";
		cin>>secondnum;
		
		ans = firstnum / secondnum;
		modans = firstnum % secondnum;
		
		cout<<firstnum<<" / "<<secondnum<<" = "<<ans<<"\n";
		cout<<firstnum<<" % "<<secondnum<< " = "<<modans<<"\n";
		}
	break;

	//Power
	
	case '^' :
		{
		cout<<"\nWhat is the base?\n";
		cin>>firstnum;
		
		cout<<"\nWhat is the power?\n";
		cin>>secondnum;
		
		for(int i = 0; i < secondnum; i++)
           result= result * firstnum;
        
		cout<<"\n"<<firstnum<<" ^ "<<secondnum<<" = "<<result<<"\n";
		}
	break;

	//factorial
	
	case '!':
		{
		cout<<"\nWhat is the number\n";
		cin>>num;
		
		if(num < 0)
			{ 
			cout<<"\n***ERROR: Factorial cannot be a negative number.***\n";
			}
		else if(num == 0)
			{
			cout<<"\n0! = 1";
			}
		else
			{
			for(int i = 1; i<=num; i++)
			fact *= i;
			
			cout<<"\n"<<num<<"! = "<<fact<<"\n";
			}
	break;		
	}
	
	case 'Q' : 
	case 'q' :	
	break;

	// other than +, -, *, /...

	default : cout<<"\n ***ERROR: Invalid selection***\n";

	}

//menu will show up if q is not input

cout<<"\n      Menu";

cout<<"\n=================";

cout<<"\n + Addition";

cout<<"\n - Subtraction";

cout<<"\n * Multiplication";

cout<<"\n / Division";

cout<<"\n ^ Number to Power";

cout<<"\n ! Factorial";

cout<<"\n q Quit";

cout<<"\n Enter operation: ";

// read the input
cin>>selection;
}

//making it look pretty
cout<<"\n";

return 0;
}
