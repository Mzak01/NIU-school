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
Title: String convert (const string& infix)

Argument: i - increment value (decribes value of current integer of
	      stack)
	  infix - infix string of equation
	  postfix - postfix string of equation
	  opstack - has stack of stuff from mystack

Use: converts the expression from infix to postfix so eval can do the
     math portion.

Return: postfix expression
***********************************************************************/
string convert (const string& infix)
{
	//incremental value
	int i = 0;

	//sets postfix string empty
	//(will have things after conversion :)
	string postfix = "";
	mystack opstack;

	while(infix[i]!= '\0')
	{
		//if not letter
		 if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        	{
            		postfix += infix[i];
            		postfix += " ";
            		i++;
        	}
        	else if(isspace(infix[i]))
        	{
        		opstack.push(' ');
        		i++;
        	}
        	// push the stack
        	else if(infix[i]=='(')
        	{
            		opstack.push(infix[i]);
            		postfix += " ";
            		i++;
        	}
        	//keep popping from stack until
        	// closing a pair opening bracket no more
        	else if(infix[i]==')')
        	{
            		while(opstack.top()!='(')
            		{
            			postfix += opstack.top();
            			postfix += " ";
                		opstack.pop();
            		}

            		opstack.pop();
            		postfix += " ";
            		i++;
        	}
        	else
        	{
        		//if none of that put it to top and pop
            		while (!opstack.empty() && prec(infix[i]) <= prec(opstack.top()))
            		{
                		postfix += opstack.top();
                		postfix += " ";
                		opstack.pop();
            		}

            		opstack.push(infix[i]);
            		postfix += " ";
           		i++;
        	}
    	}

    	//if not empty put to top and pop
    	while(!opstack.empty())
    	{
        	postfix += opstack.top();
        	postfix += " ";
        	opstack.pop();
    	}

	//return
    	return postfix;
}

//this is when we realized we had to rewrite because we got the infamous wall of errors
//we refused to look on stack overflow for help on this wall because of their STUPID APRIL FOOLS PRANK! >:(

//We hate hot dog theme!!!!!
//All our homies hate hot dog theme!!! >:(

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
/*string convert(const string& infix)
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
*/
/***************************************************************************
Function: int prec(char x)

Argument: x - array of operators being seen by the code

Use: scans infix from left to right, extracting and processing one token at
     a time,skipping whitespace

Return: 0, 1, 2, 3
***************************************************************************/
int prec(char x)
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


