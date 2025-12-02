/*************************************************************************
Title: mystack.cpp

Course: CSCI241 Assign7

Author: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: Contains the definitions for the member functions of the mystack
     class
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstddef>
#include "mystack.h"

using namespace std;

/*************************************************************************
Function: mystack()

Arguments: stack_size - number of current values stored in the array
           stack_capacity - number of elements in the stack
           stack_array - allocate an array of char

Use: Default constructor for the mystack class, initialize new mystack
     object to an empty stack.

Return: none
*************************************************************************/
mystack::mystack()
{
	stack_size = 0;
	stack_capacity = 0;
	stack_array = nullptr;
}

/*************************************************************************
Function: mystack(const mystack& x)

Argument: stack_size - number of current values stored in the array
          stack_capacity - number of elements in the stack
          stack_array - allocate an array of char
          x - new object array variable
	  x.stack_capacity - stack capacity of object x
	  x.stack_size - stack size of object x
	  new char - contains same values as the stack array of x. Num of
	  	     elements equal to the stack capacity.

Use: copy constructor which initializes a new object to the same values
     for all of its data members

Return: none
*************************************************************************/
mystack::mystack(const mystack& x)
{
	stack_capacity = x.stack_capacity;
	stack_size = x.stack_size;
	stack_array = new char[stack_capacity];
}

/*************************************************************************
Function: ~mystack()

Argument: stack_array - allocate an array of char

Use: deletes the stack array

Return: none
*************************************************************************/
mystack::~mystack()
{
	delete stack_array;
}

/*************************************************************************
Function: mystack& operator=(const mystack& x)

Argument: stack_size - number of current values stored in the array
          stack_capacity - number of elements in the stack
          stack_array - allocate an array of char
          x - new object array variable
          x.stack_capacity - stack capacity of object x
          x.stack_size - stack size of object x
          new char - contains same values as the stack array of x. Num of
                     elements equal to the stack capacity.
          *this - calls the member function

Use: overloads copy assignment operator should assign one mystack (object x)
     to another. The state of the data members when the function ends
     should be same as described above for the copy constructor

Return: *this
*************************************************************************/
mystack& mystack::operator=(const mystack& x)
{
	stack_capacity = x.stack_capacity;
	stack_size = x.stack_size;
	stack_array = new char[stack_capacity];

	return *this;
}

/*************************************************************************
Function: size_t capacity() const

Argument: stack_capacity - number of elements in the stack

Use: returns the stack capacity

Return: stack_capacity
*************************************************************************/
size_t mystack::capacity() const
{
	return stack_capacity;
}

/*************************************************************************
Function: size_t size() const

Argument: stack_size - number of current values stored in the array

Use: returns the stack size

Return: stack_size
*************************************************************************/
size_t mystack::size() const
{
	return stack_size;
}

/*************************************************************************
Function: bool empty() const

Argument: stack_size - number of current values stored in the array

Use: this member function returns true if the stack size is 0, else return
     false

Return: true/false
*************************************************************************/
bool mystack::empty() const
{
	if(stack_size == 0)
	{
		return true;
	}
	else
	{
	return false;
	}
}

/*************************************************************************
Function: void clear()

Argument: stack_size - number of current values stored in the array

Use: sets stack size to 0

Return: none
*************************************************************************/
void mystack::clear()
{
	stack_size = 0;
}

/*************************************************************************
Function: void reserve(size_t n)

Argument: stack_size - number of current values stored in the array
          stack_capacity - number of elements in the stack
          stack_array - allocate an array of char
	  n - holds stack capacity to be modified
	  i - holder for variable in for loop
	  temp - temporary array holder

Use: modifies an object stack capacity without changing the stack size or
     contents of the stack array

Return: none
*************************************************************************/
void mystack::reserve(size_t n)
{
	if(n < stack_size || n == stack_capacity)
	{
		return;
	}

	stack_capacity = n;
	char *temp = new char[n];

	for(int i = 0; stack_size; i++)
	{
		temp[i] = stack_array[i];
	}

	delete stack_array;

	stack_array = temp;
}

/*************************************************************************
Function: const char& top() const

Argument: stack_size - number of current values stored in the array
          stack_array - allocate an array of char
          C = top item of the stack

Use: returns the top item in the stack. Function not called if stack is
     empty

Return: top item of the stack
*************************************************************************/
const char& mystack::top() const
{

	const char& c = stack_array[stack_size-1];
	return c;
}

/*************************************************************************
Function: void push(char value)

Argument: stack_size - number of current values stored in the array
          stack_capacity - number of elements in the stack
          stack_array - allocate an array of char
          value - value of an element in the array

Use: push the character value onto the top of the stack. 

Return: none
*************************************************************************/
void mystack::push(char value)
{
	if(stack_size == stack_capacity || stack_capacity == 0)
	{
		stack_capacity++;
	}
	else
	{
		stack_capacity += 2;
	}

	stack_array[stack_size] = value;
	stack_size++;
}
/*************************************************************************
Function: void pop()

Argument: stack_size - number of current values stored in the array

Use: pop item off the top of the stack decreasing it by one. Will not use
     if stack is empty.

Return: none
*************************************************************************/
void mystack::pop()
{
	stack_size--;
}

