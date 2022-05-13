/***************************************************************
CSCI 240         Program 6    Fall 2021

Programmer: Milo Zak, Sebastian Lesny

Section: CSCI 240

Date Due: Oct. 15, 2021

Purpose: For this assignment, modify program 5 so that it uses
		 functions and does error checking with the data that is
		 used in the calculations.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//function declaration

/***************************************************************
Function: addition

Use: This function calculates the sum of two integer values

Arguments: fisrtnum - an integer that is used in the addition
           secondnum - the second integer that is used in the 
		   addition

Returns: the sum of the two integer values

Note: None
***************************************************************/
int add (int firstnum, int secondnum)
{
	int ans;
	
	ans = firstnum + secondnum;
		
	cout<<firstnum<<" + "<<secondnum<<" = "<<ans<<"\n";
}

/***************************************************************
Function: subtract

Use: This function calculates the difference of two integer values

Arguments: firstnum - an integer that is used in the subtraction
           secondnum - the second integer that is used in the 
		   subtraction

Returns: the difference of the two integer values

Note: None
***************************************************************/
int subtract( int firstnum, int secondnum)
{
	int ans; 

	ans = firstnum - secondnum;
	
	cout<<firstnum<<" - "<<secondnum<<" = "<<ans<<"\n";
}

/***************************************************************
Function: multiply

Use: This function calculates the product of two integer values

Arguments: firstnum - an integer that is used in the multiplication
           secondnum - the second integer that is used in the 
		   multiplication

Returns: the product of the two integer values

Note: None
***************************************************************/
int multiply (int firstnum, int secondnum)
{
	int ans;
		
	ans = firstnum * secondnum;
	
	cout<<firstnum<<" * "<<secondnum<<" = "<<ans<<"\n";
}

/***************************************************************
Function: quotiant

Use: This function calculates the division of two integer values

Arguments: firstnum - an integer that is used in the quotient
           secondnum - the second integer that is used in the 
		   quotient

Returns: the division of the two integer values

Note: None
***************************************************************/
int quotiant (int firstnum, int secondnum)
{
	int ans;
	
	ans = firstnum / secondnum;
		
	cout<<firstnum<<" / "<<secondnum<<" = "<<ans<<"\n";
}

/***************************************************************
Function: remainder

Use: This function calculates the remainder of the two integers.

Arguments: firstnum - an integer that is used in the quotient
           secondnum - the second integer that is used in the 
		   quotient

Returns: the remainder of the two integer values

Note: None
***************************************************************/
int remainder (int firstnum, int secondnum)
{
	int modans;
	
	modans = firstnum % secondnum;
	
	cout<<firstnum<<" % "<<secondnum<<" = "<<modans<<endl;
}

/***************************************************************
Function: power

Use: This function raises the given base to the given power

Arguments: firstnum - an integer that is used in the power
           secondnum - the second integer that is used in the
		   power

Returns: the result after raising the given base to the given 
	     power

Note: None
***************************************************************/
int power (int firstnum, int secondnum)
{
	int result = 1.0;

	for(int i = 0; i < secondnum; i++)
        result= result * firstnum;
        
	cout<<"\n"<<firstnum<<" ^ "<<secondnum<<" = "<<result<<"\n";
}

/***************************************************************
Function: factorial

Use: This function calculates the factorial of the integer value

Arguments: firstnum - an integer that is used in the factorial

Returns: the result of factorial of value

Note: None
***************************************************************/
int factorial (int firstnum)
{
	int fact = 1;
		
	if(firstnum < 0)
		{ 
			cout<<"\n***ERROR: Factorial cannot be a negative number.***\n";
		}
	else if(firstnum == 0)
		{
			cout<<"\n0! = 1";
		}
	else
		{
			for(int i = 1; i<=firstnum; i++)
			fact *= i;
			
			cout<<"\n"<<firstnum<<"! = "<<fact<<"\n";
		}
}

/***************************************************************
Function: getValue

Use: This function accepts user input for integer value

Arguments: prompt - the message to ask user for input

Returns: the value entered by the user

Note: None
***************************************************************/
int getValue (string prompt)
{
    int value;
    
    cout<<prompt;
    cin>>value;
    cout<<"\n";
    
    return value;
}

/***************************************************************
Function: getNonNegativeValue

Use: This function accepts user input for a non-negative integer value

Arguments: prompt - the message to ask user for input

Returns: the value entered by the user

Note: None
***************************************************************/
int getNonNegativeValue (string prompt)
{
	int value;
	
    cout<<prompt;
    cin>>value;
    
    while(value < 0)
    {
        cout<<"Error: the value cannot be negative. Try again: ";
        cin>>value;
    }
    cout<<"\n";
    
    return value;
}

/***************************************************************
Function: getNonZeroValue

Use: This function accepts user input for a non-zero integer value

Arguments: prompt - the message to ask user for input

Returns: the value entered by the user

Note: None
***************************************************************/
int getNonZeroValue (string prompt)
{
	int value;
	
	cout<<prompt;
	cin>>value;
	
	while (value == 0)
	{
		cout<<"Error: the value cannot be zero. Try again: ";
		cin>>value;
	}
	cout<<"\n";
	
	return value;
}


/***************************************************************
Function: menu

Use: This function displays and takes user output on function

Arguments: none

Returns: with more questions based on selection

Note: None
***************************************************************/
char menu()
{
	char selection;
	
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
	cin>>selection;
	
	while (selection != '+' && selection != '-' && selection != '*' && selection != '/' && selection != '^' && selection != '!' && selection != 'q' && selection != 'Q')
	{
		cout<<"Error: Invalid selection. Try again: ";
		cin>>selection;
	}
}

// main function
int main()
{
	int firstnum,
		secondnum,
		ans,
		result = 1.0,
		fact = 1;
		
	char selection;
	
	selection = menu();
	
	//loops menu selection
	while (selection != 'q' && selection != 'Q')
	{
		switch (selection)
		{
			//addition
			case '+' :
				firstnum = getValue ("What is the first number to add?");
				secondnum = getValue ("What is the second number to add?");
				
				ans= add(firstnum, secondnum);
			break;
			
			//subtraction
			case '-' :
				firstnum = getValue ("What is the first number to subtract?");
				secondnum = getValue ("What is the second number to subtract?");
				
				ans= subtract(firstnum, secondnum);
			break;
			
			//multiplication
			case '*' :
				firstnum = getValue ("What is the first number to multiply?");
				secondnum = getValue ("What is the second number to multiply?");
				
				ans= multiply(firstnum, secondnum);
			break;
			
			//division
			case '/' :
				firstnum = getValue ("What is the dividen?");
				secondnum = getNonZeroValue ("What is the divisor?");
				
				ans = quotiant(firstnum, secondnum);
				ans = remainder(firstnum, secondnum);
			break;
			
			//power
			case '^' :
				firstnum = getValue ("What is the base?");
				secondnum = getNonNegativeValue ("What is the power?");
				
				ans= power(firstnum, secondnum);
			break;
			
			//factorial
			case '!' :
				firstnum = getNonNegativeValue ("What is the number?");
			
				ans= factorial(firstnum);
			break;
			
			//quit	
			case 'q' :
			case 'Q' :
			break;
		}
		//reinputs menu selection
		selection = menu();
	}
	
	
	return 0;
}
