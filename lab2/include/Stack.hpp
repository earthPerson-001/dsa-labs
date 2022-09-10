#ifndef _STACK_HPP_
#define _STACK_HPP_

class Stack
{

public:
    virtual ~Stack(){};

    // adds an element into the stack
    virtual void push(int data) = 0;

    // removes an element from the stack
    // also returns the removed element
    virtual int pop() = 0;

    // checks if the stack is empty
    virtual bool isEmpty() = 0;

    // checks if the stack if full
    virtual bool isFull() =0;

    // gives the element at the top
    virtual int top() = 0;

};


#endif