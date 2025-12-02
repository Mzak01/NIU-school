/*************************************************************************
Title: inpost.cpp

Course: CSCI241 Assign7

Author: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: Contains your convert() function
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <cctype>

#include "inpost.h"
#include "mystack.h"

using namespace std;
/***********************************************************************
Function: string convert(const string& infix)

Argument: opstack - hold operators during conversion
	  output - output of the conversion
	  infix - string containing the infix expression tokens
	  n - holder temp of size
	  i - variable size of array
	  ch - holder of stack capacity
	  p1 - holder of postfix(ch)
	  p2 - holder of postfix(opstack.top())
	  postfix - string where output postfix expression will be
	  	    constructed

Use: converts infix expression passed to it as a c++ string to a
     equivalent postfix string stores into a mystring object
     expression stored in a string.

Returns: output
***********************************************************************/
string convert(const string& infix)
{
	mystack opstack;
	opstack.reserve(10);
	opstack.push('(');

	string output = " ";
	int n = infix.size();

	for(int i=0; i < n; i++)
	{
		char ch = infix[i];
		if(isalnum(ch))
		{
			output = output + ch;
		}
		else if(ch == '(')
		{
			opstack.push('(');
		}
		else if(ch == ')')
		{
			while(opstack.top() != '(')
			{
				output = output + opstack.top();
				opstack.pop();
			}

			opstack.pop();
		}
		else
		{
			int p1 = postfix(ch);
			int p2 = postfix(opstack.top());

			while(p1 <= p2)
			{
				output = output + opstack.top();
				opstack.pop();
				p2 = postfix(opstack.top());
			}

			opstack.push(ch);
		}
	}
	while(opstack.top()!= '(')
	{
		output = output + opstack.top();
		opstack.pop();
	}
	return output;
}

/***************************************************************************
Function: int postfix(char x)

Argument: x - array of operators being seen by the code

Use: scans infix from left to right, extracting and processing one token at
     a time,skipping whitespace

Return: 0, 1, 2, 3
***************************************************************************/
int postfix(char x)
{
	switch(x)
	{
		case '(':
			return 0;
		break;

		case '+':
		case '-':
			return 1;
		break;

		case '*':
		case '/':
			return 2;
		break;

		case '^':
		case '~':
			return 3;
		break;

		default: return 999;
	}
}

