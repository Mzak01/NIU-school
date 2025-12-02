/**************************************************************************
Title: mystack.cpp

Course: CSCI241 Assign8

Programmer: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: contains the class definition for the mystack class
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include <cstddef>

#include "mystack.h"

using namespace std;

/*************************************************************************
Function: mystack()

Arguments: stack_size - number of current values stored in the array
           stack_top_pointer - pointer to a node, sets it to empty

Use: Default constructor for the mystack class, initialize new mystack
     object to an empty stack.

Return: none
*************************************************************************/
mystack::mystack()
{
	stack_size = 0;
	stack_top_pointer = nullptr;
}

/*************************************************************************
Function: mystack(const mystack& x)

Argument: stack_size - number of current values stored in the array
          stack_top_pointer - constructs the stack for the pointer
          x - new stack variable
          new_node - contains a temptorary holder of the linked list
           	     after going through development
          last - contains last number of linked list
          ptr - holder of the new linked list from x.stack_top_pointer
          x.stack_top_pointer - new holder of linked lists
          next - next objext in list

Use: copy constructor which initializes a new object to the same values
     for all of its data members

Return: none
*************************************************************************/
mystack::mystack(const mystack& x)
{
	//sets linked list to none
	stack_top_pointer = nullptr;

	//makes x.stack_size
	stack_size = x.stack_size;

	//clones the list :)
	node* last = nullptr;
	node* ptr = x.stack_top_pointer;
	while(ptr != nullptr)
	{
		node* new_node = nullptr;
		new_node->value = ptr->value;
		if(last == nullptr)
		{
			stack_top_pointer = new_node;
		}
		else
		{
			last->next = new_node;
		}
		last = new_node;
		ptr = ptr->next;
	}
}

/*************************************************************************
Function: ~mystack()

Argument: none (clear() clears everything)

Use: clears the linked list

Return: none
*************************************************************************/
mystack::~mystack()
{
	clear();
}

/*************************************************************************
Function: mystack& operator=(const mystack& x)

Argument: stack_size - number of current values stored in the stack
          stack_top_pointer - allocate a pointer to a node for a linked list
          x - new object array variable
          x.stack_size - stack size of object x
          *this - calls the member function
	          new_node - contains a temptorary holder of the linked list
                     after going through development
          last - contains last number of linked list
          ptr - holder of the new linked list from x.stack_top_pointer
          x.stack_top_pointer - new holder of linked lists
          next - next objext in list

Use: overloads copy assignment operator should assign one mystack (object x)
     to another. The state of the data members when the function ends
     should be same as described above for the copy constructor

Return: *this
*************************************************************************/
mystack& mystack::operator=(const mystack& x)
{
	//if not imposter version
	if(this != &x)
	{
		//clears
		clear();

		//sets to new version
		stack_size = x.stack_size;

		//clone sussy
	        node* last = nullptr;
	        node* ptr = x.stack_top_pointer;

	        while(ptr != nullptr)
        	{
                	node* new_node = nullptr;
	                new_node->value = ptr->value;
        	        if(last == nullptr)
                	{
                        	stack_top_pointer = new_node;
                	}
                	else
                	{
                        	last->next = new_node;
                	}
	                last = new_node;
        	        ptr = ptr->next;
        	}
	}

	return *this;
}

/*************************************************************************
Function: size_t size() const

Argument: stack_size - number of current values stored

Use: returns the stack size

Return: stack_size
*************************************************************************/
size_t mystack::size() const
{
	return stack_size;
}

/*************************************************************************
Function: bool empty() const

Argument: stack_size - number of current values stored

Use: this member function returns true if the stack size is 0, else return
     false

Return: true/false
*************************************************************************/
bool mystack::empty() const
{
	//empty
	if(stack_size == 0)
	{
		return true;
	}
	//not empty
	else
	{
		return false;
	}
}

/*************************************************************************
Function: void clear()

Use: clears the linked list stack.

Return: none
*************************************************************************/
void mystack::clear()
{
	//loop to clear
	while(!empty())
	{
		pop();
	}
}

/*************************************************************************
Function: const int& top() const

ArgumentL stack_top_pointer - pointer to linked list
	  value - value of item in linked list (top)

Use: returns the top item in the stack. Function not called if stack is
     empty

Return: stack_top_pointer->value
*************************************************************************/
const int& mystack::top() const
{
		//get top item
		return stack_top_pointer->value;
}

/*************************************************************************
Function: void push(int value)

Argument: stack_size - number of current values stored
          stack_top_pointer - pointer to linked list
          value - value of an element
          new_node - place holder of linked list

Use: push the character value onto the top of the stack.

Return: none
*************************************************************************/
void mystack::push(int value)
{
	//creates new_node and sets values
	struct node* new_node = new node(value, stack_top_pointer);
//	new_node->value = value;	<<-- alternative way
//	new_node->next = stack_top_pointer;

	//sets to new verson and increase num amount
	stack_top_pointer = new_node;
	stack_size++;
}

/*************************************************************************
Function: void pop()

Argument: delete_node - used to decrease the size of stack_top_pointer
	  stack_top_pointer - pointer to linked list
	  stack_size - number of current values stored

Use: pop item off the top of the stack decreasing it
 by one. Will not use
     if it is empty

Return: none
*************************************************************************/
void mystack::pop()
{
	//create node to delete old pointer
	node* delete_node;

	//sets it to current set
	delete_node = stack_top_pointer;

	//goes to next value
	stack_top_pointer = stack_top_pointer->next;

	//deletes old node
	delete delete_node;

	//takes off one in amount of num
	stack_size--;
}

