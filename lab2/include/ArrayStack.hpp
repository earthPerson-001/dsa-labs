#ifndef _ARRAY_STACK_HPP_
#define _ARRAY_STACK_HPP_

#include "Stack.hpp"

class ArrayStack: public Stack
{
private:
    int size, topIndex;
    int* dataArray;

public:
    // ctor
    ArrayStack(int size = 100);

    virtual ~ArrayStack();

    // adds an element to the top of the stack
    void push(int data);

    // removes an element from the stack
    // also returns the removed element
    int pop();

    // checks if the stack is empty
    bool isEmpty();

    // checks if the stack if full
    bool isFull();

    // gives the element at the top
    int top();

};


#endif