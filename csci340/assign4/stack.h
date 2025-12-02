#ifndef STACK_H
#define STACK_H
#include <queue>

template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements
    std::queue<T> q2;	// are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();
};


// Note that the members of a template go into a .h file since
// they are not compiled directly into a .o file like the members
// of regular/non-template classes.
// Place your Stack class member implementations here.


/*
Func: bool empty() const

Arg: finds if stack has elements

Ret: t/f
*/
template<typename T>
bool Stack<T>::empty() const
{
    return q1.empty();
}


/*
Func: int size() const

Arg: finds number of elements in stack

Ret: elements in stack
*/
template <typename T>
int Stack<T>::size() const
{
    return q1.size();
}


/*
Func: const T& top

Arg: finds reference of newest element

Ret: ref to newest element
*/
template <typename T>
const T& Stack<T>::top()
{
    return q1.front();
}


/*
Func: void push(const T& val)

Arg: add element to stack

Ret: none
*/
template<typename T>
void Stack<T>::push(const T& val)
{
    q2.push(val);

    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q2, q1);
}


/*
Func: void pop()

Arg: removes the top element of the stack

Ret: nonen
*/
template <typename T>
void Stack<T>::pop()
{
    if(!q1.empty())
    {
        q1.pop();
    }
}

#endif // STACK_H
