/**************************************************************************
Title: mylist.h

Course: CSCI241   Assign10

Programmer: Milo Zak (z1917365)

Use: all of the code for both the structure and the class should be placed
     in a single file, mylist.h. That includes both structure / class
     definitions as well as the definitions for all of the functions.
**************************************************************************/

#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <stdexcept>
#include <algorithm>

#ifndef MYLIST_H
#define MYLIST_H

using namespace std;

//creating class and template
template <class T>
class mylist;

//create the node for structure
template <class T>
struct node
{
	//value of var
	T value;

	//pointer to next node
	node<T> *next;

	//pointer to node prior
	node<T> *prior;


	//construction working
	node(const T& value, node<T>* prior = nullptr, node<T>* next = nullptr)
	{
		this->value = value;
		this->prior = prior;
		this->next = next;
	}
};

//override operator
template <class T>
ostream& operator<<(ostream&, const mylist<T>&);

//create the class definition for mylist
template <class T>
class mylist
{
	//making friend for overriding function
	friend ostream& operator<< <>(ostream&, const mylist<T>&);


	private:
		//creates pointer nodes for front or back of the list
		//as well as the length of the list
		node<T> *top;
		node<T> *bottom;
		size_t list_length;

	public:
		//list of functions used to move the numbeers and list
		//to their assorted things
		mylist();
		~mylist();
		mylist(const mylist<T>&);
		void clear();
		size_t size() const;
                mylist<T>& operator=(const mylist<T>&);
		bool empty() const;
		const T& front() const;
		T& front();
		const T& back() const;
		T& back();
		void push_front(const T&);
		void push_back(const T&);
		void pop_front();
		void pop_back();
		void clone(const mylist<T>&);
		bool operator<(const mylist<T>&) const;
		bool operator==(const mylist<T>&) const;
};

/*************************************************************************
function: mylist()

use: The class should have a default constructor that sets both pointer data members of the list to nullptr and the list size to 0.

return: n/a
*************************************************************************/
template <class T>
mylist<T>::mylist()
{
	//setting pointers to nothing
	top = nullptr;
	bottom = nullptr;

	//sets list to zero prior to input
	list_length=0;
}

/**************************************************************************
function: ~mylist()

use:The class should have a destructor. The destructor can simply call
the clear() method.

return: n/a
**************************************************************************/
template <class T>
mylist<T>::~mylist()
{
	//empties the list
	clear();
}

/************************************************************************
function: mylist(const mylist<T>&)

use: The class should have a proper copy constructor.

returns: n/a
************************************************************************/
template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
	//sets everything to noting again
	top = nullptr;
	bottom = nullptr;
	list_length = 0;

	//using the clone function discussed in prior
	//assignments. this clones the function into a new list
	//keeping the old one to sort
	clone(x);
}

/***********************************************************************
function: clear()

use: This member function should properly set the list back to the empty
     state, deleting all of the nodes in the linked list and setting
     the size back to 0.

return: none
***********************************************************************/
template <class T>
void mylist<T>::clear()
{
	//while list is not empty remove the top value
	while(empty() == false)
	{
		pop_front();
	}
}

/**********************************************************************
function: size() const

use: Returns the list size.

return: list_length
**********************************************************************/
template <class T>
size_t mylist<T>::size() const
{
	return list_length;
}

/**********************************************************************
function: mylist<T>& operator=(const mylist<T>&)

use: The assignment operator should be properly overloaded.

return: *this
**********************************************************************/
template <class T>
 mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{
	//oversloading x
	if(this != &x)
	{
		clear();

		//cloning it into the list
		clone(x);
	}
	return *this;
}

/**********************************************************************
function: empty() const

use: Returns true if the list size is 0; otherwise, returns false.

return: true if the size == 0, false if it doesnt
**********************************************************************/
template <class T>
bool mylist<T>::empty() const
{
	if(list_length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/********************************************************************
function: const t& front() const

use: This member function should return the value of the front node
     in the list. If the list is empty, throw an underflow_error
     instead.

return: value of the front node
********************************************************************/
template <class T>
const T& mylist<T>::front() const
{
	if (empty())
	{
		throw underflow_error("***ERROR: underflow on call to front()***");
	}
	else
	{
		return top->value;
	}
}

/******************************************************************
function: T& front()

use: This member function should return the value of the front node
     in the list. If the list is empty, throw an underflow_error
     instead.

return: return the top value from the node
******************************************************************/
template <class T>
T& mylist<T>::front()
{
	if(empty())
	{
		throw underflow_error("***ERROR: underflow on call to front()***");
	}
	else
	{
		return top->value;
	}
}

/****************************************************************
function: const T& back() const

use: This member function should return the value of the back
     node in the list. If the list is empty, throw an
     underflow_error instead.

return: the value of the last node
****************************************************************/
template <class T>
const T& mylist<T>::back() const
{
	if(empty())
	{
		throw underflow_error("***ERROR: underflow on call to back()***");
	}
	else
	{
		return bottom->value;
	}
}

/****************************************************************
function: T& back()

use: This member function should return the value of the back
     node in the list. If the list is empty, throw an
     underflow_error instead.

return: the value of the last node in list_length
****************************************************************/
template <class T>
T& mylist<T>::back()
{
	if(empty())
	{
		throw underflow_error("***ERROR: underflow on call to back()***");
	}
	else
	{
		return bottom->value;
	}
}

/***********************************************************************
function: push_front(const T&)

use: This member function should insert an item at the front of the list.

return: n/a
***********************************************************************/
template <class T>
void mylist<T>::push_front(const T& value)
{
	//creates new node to hold the list
	node<T> *new_node = nullptr;

	new_node =  new node<T>(value, new_node, new_node);

	//puts the next item at the top of the other list
	new_node->next = top;

	//if not empty
	if(!empty())
	{
		top->prior = new_node;
		top = new_node;
	}
	else
	{
		bottom = new_node;
		top = new_node;
	}
	list_length++;
}

/************************************************************************
function: push_back(consr T)

use: This member function should insert an item at the back of the list.

return: n/a
************************************************************************/
template <class T>
void mylist<T>::push_back(const T& value)
{
	//creates new node to hold the list
	node<T> *new_node  = nullptr;
	new_node = new node<T>(value, new_node, new_node);

	//takes last number and puts it to back
	new_node->prior = bottom;

	//if not empty
	if(!empty())
	{
		//take next num from bottom into new node, and copies
		bottom->next = new_node;
		bottom = new_node;
	}
	else
	{
		//make things same
		top = new_node;
		bottom = new_node;
	}

	list_length++;
}

/**************************************************************************
function: pop_front()

use: This member function should remove the item at the front of the list.
     If the list is empty, throw an underflow_error instead

return: n/a
**************************************************************************/
template <class T>
void mylist<T>::pop_front()
{
	if(list_length == 0)
	{
		throw underflow_error("***ERROR: underflow on call to pop_front()***");
	}

	//pointer to delete numbers
	node<T> *deletion = top;

	//make top equal next num in series
	top = deletion->next;

	//no num
	if(top == nullptr)
	{
		bottom = nullptr;
	}
	//deletes that num
	else
	{
		top->prior = nullptr;
		delete deletion;
	}

	list_length--;
}

/****************************************************************************
function: pop_back()

use: This member function should remove the item at the back of the list.
     If the list is empty, throw an underflow_error instead

return: n/a
****************************************************************************/
template <class T>
void mylist<T>::pop_back()
{
	if(empty())
	{
		throw underflow_error("***ERROR: underflow at pop_back()***");
	}

	//make pointer to delete num off bottom
	node<T> *deletion = bottom;

	//same thing as top but with bottom
	bottom = deletion->prior;

	if(bottom == nullptr)
	{
		top = nullptr;
	}
	else
	{
		bottom->next = nullptr;
		delete deletion;
	}

	list_length--;
}

/**********************************************************************
function: operator==(const mylist<T>&) const

use: The equality operator should be overloaded to allow the comparison
     of two mylist objects. This member function returns true if 1)
     the two lists contain the same number of nodes, and 2) if each
     element stored in the left-hand-side list is equal to the
     corresponding element of the right-hand-side list. Otherwise, the
     method returns false.

return: true or false
**********************************************************************/
template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
	node<T> *point = rhs.top;
	node<T> *point1 = this->top;

	bool equality = false; //seeing if equal
	size_t l = rhs.list_length; //list length
	size_t l1 = this->list_length; //list length 1

	//if the two lists done match
	if(l != l1)
	{
		return false;
	}
	//while there is num being pointed to
	while(point != nullptr)
	{
		if(point->value == point1->value)
		{
			equality = true;
		}
		else
		{
			equality = false;
			break;
		}

		point = point->next;
		point1 = point1->next;
	}
	if(l == l1 && equality)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/***********************************************************************
function: operator<(const mylist<T>&) const

use: The less than operator should be overloaded to allow the comparison
     of two mylist objects. This member function will perform a
     "lexicographical" comparison of the two lists.

     Lexicographical comparison means "dictionary" (element-by-element)
     ordering. That is, list1 is less than list2 if the first value of
     list1 is less than the first value of list2, and greater if the
     first value of list1 is greater than the first value of list2. If
     the two first value elements are equivalent then the member function
     compares the two second value elements, and so on.

     The first list is also considered to be less than the second if
     every value in the first list is equal to the corresponding value
     in the second but the second list contains more elements.

return: true or false
***********************************************************************/
template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{
	//nodes pointing to top and the new top
	node<T> *point = rhs.top;
	node<T> *point1 = top;

	//while both have variables check to see which
	//value is bigger and return true or false
	while (point1 != nullptr && point != nullptr)
	{
        	if (point1->value < point->value)
        	{
            		return true;
        	}
        	else if (point1->value > point->value)
        	{
            		return false;
        	}
        	// move on to the next element (front to back)
        	point = point->next;
        	point1 = point1->next;
    	}

    	return (list_length < rhs.list_length) ? true : false;
}

/***************************************************************************
function: operator<<(ostream&, const mylist<T>&)

use: The stream insertion operator should be overloaded so that an entire
     mylist object can be sent to standard output. This function will need
     to be a friend rather than a member function. Start at the front of
     the list and traverse the list, printing the value in each node
     followed by a single space until you reach the end of the list.

return: os
***************************************************************************/
template <class T>
ostream& operator<<(ostream& os, const mylist<T>& obj)
{
	node<T> *point = obj.top;

	//loop to print every value with space in between
	while(point != nullptr)
	{
		os << point->value;
		os << " ";
		point = point->next;
	}

	//printing everything
	return os;
}

/*************************************************************************
function: clone(const mylist<T>&)

use: clones the front and back pointers to push it to the next value in the
     array.

return: n/a
*************************************************************************/
template <class T>
void mylist<T>::clone(const mylist<T>& x)
{
	node<T> *point = x.top;

	//while it has numbers clone the variable
	while(point != nullptr)
	{
		push_back(point->value);
		point = point->next;
	}
}

#endif
