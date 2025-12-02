/***************************************************************************
Title: eval.cpp

Course: csci241 Assign8

Programmer: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: stores the evaluate function to be used in main.
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <stack>
#include <bits/stdc++.h>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>

#include "eval.h"
#include "mystack.h"
#include "inpost.h"

using namespace std;

/***************************************************************************
Title: int evaluate(const string& postfix)

Argument: op - token value
	  stringstream ss(postfix) - stringstream variable
	  eval_stack - stack to read
	  t0 - see what thing is
	  right - right side
	  left - left side
	  i - holds number to be negative

Use: evaluates the post fix expression

return: value of eval
**************************************************************************/
int evaluate(const string& postfix)
{
	//token
	string op;

	//stringstream
	stringstream ss(postfix);

	//stack object to read
	mystack eval_stack;

	//goes through one at a time
	while (ss >> op)
	{

		//sees what variable is
		//char t0 = op.at(0);

//		cout << "op: " << op << endl;
//		cout << "op[0]: " << op[0] << endl;
//		cout << "right: " << right << endl;
//		cout << "left: " << left << endl;
//		cout << "eval_stack size: " << eval_stack.size() << endl << endl;

		//If it is a digit, then push the value into the stack
		if (isdigit(op[0]))
		{
			eval_stack.push(std::stoi(op));
		}
		//if letter, push and set num val
		else if (islower(op[0]))
		{
			eval_stack.push(op[0]-'a');
		}
		//if ~ then val = neg
		else if (op[0] == '~')
		{
			//get num
			int i = eval_stack.top();
			//take off
			eval_stack.pop();
			//make neg
			eval_stack.push(-i);
		}
		else
		{
			//right ride
			int right = eval_stack.top();

			//remove val
			eval_stack.pop();

			//left
			int left = eval_stack.top();

			//remove val
			eval_stack.pop();

			//finds operator and pushes equation in
			switch(op[0]) {

				case '+':
					eval_stack.push(left + right);
					break;
				case '-':
					eval_stack.push(left - right);
					break;
				case '*':
					eval_stack.push(left * right);
					break;
				case '/':
					if (right == 0)
					{

						eval_stack.push(0);
						cout<< "*** Division by 0 ***" <<endl;

					}
					else
					{
						eval_stack.push(left / right);
					}

					break;
				case '^':
					eval_stack.push(pow(left, right));
					break;
//				default:
//					std::cerr<< "Error " << op[0] <<endl;
//					assert(0 && "illegal operator");

			}

		}

	}

	//cout<<"top(): " << eval_stack.size() << endl;
	return eval_stack.top();
}
