#ifndef _LINKED_LIST_STACK_HPP_
#define _LINKED_LIST_STACK_HPP_

#include "Stack.hpp"
#include "LinkedList.hpp"

class LinkedListStack: public Stack 
{
private:
    LinkedList linkedliststack;
    bool fixedSize;
    int size;

public:

    // ctor
    LinkedListStack(bool fixedSize = false, int size = 100);

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

    // returns the number of filled positions
    int getNumberOfElements();

};



#endif