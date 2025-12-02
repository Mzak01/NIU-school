/*************************************************************************
Title: mystack.h

Course: CSCI241 Assign7

Author: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: Contains the class def for the mystack class
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cstdlib>

//making this usable in cpp files
#ifndef MYSTACK_H
#define MYSTACK_H

using namespace std;

//class definition
class mystack
{
	//variables
	private:
		char *stack_array;
		size_t stack_capacity;
		size_t stack_size;

	//class functions
	public:
		mystack();
		mystack(const mystack& x);
		~mystack();
		mystack& operator=(const mystack& x);
		size_t capacity() const;
		size_t size() const;
		bool empty() const;
		void clear();
		void reserve(size_t n);
		const char& top() const;
		void push(char value);
		void pop();
};

#endif
