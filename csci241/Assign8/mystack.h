/*********************************************************************
Title: mystack.h

Course: CSCI241 Assign8

Programmer: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: contains the class definition for the mystack class
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

//makes file useable
#ifndef MYSTACK_H
#define MYSTACK_H

using namespace std;

//class definition
class mystack
{
	private:
struct node
{
    node* next;
    node* ptr;
    node* stack_top_pointer;
    node* last;
//    node* new_node;
    int value;

    node(int value, node* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};
		size_t stack_size;
		node* stack_top_pointer;
	public:
		mystack();
		mystack(const mystack& x);
		~mystack();
		mystack& operator=(const mystack& x);
		size_t size() const;
		bool empty() const;
		void clear();
		const int& top() const;
		void push(int value);
		void pop();
};

#endif
