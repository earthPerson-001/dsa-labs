#include "ArrayStack.hpp"
#include "iostream"
#include "assert.h"

// ctor
ArrayStack::ArrayStack(int size): size(size)
{
    this->dataArray = new int[size];
    this->topIndex = -1;
}

// adds an element to the top of the stack
void ArrayStack::push(int data)
{
    if(this->isFull()) throw std::out_of_range("Stack Overflow");

    assert(this->topIndex < this->size - 1);

    this->topIndex++;
    dataArray[this->topIndex] = data;
    
}

// removes an element from the stack
// also returns the removed element
int ArrayStack::pop()
{
    if(this->isEmpty()) throw std::out_of_range("Stack Underflow");

    assert(this->topIndex > -1);

    this->topIndex--;
    return dataArray[topIndex + 1];
}

// checks if the stack is empty
bool ArrayStack::isEmpty()
{

    if (this->topIndex < 0) return true;
    return false;
 
}

// checks if the stack if full
bool ArrayStack::isFull()
{

    if( this->topIndex > this->size - 2) return true;
    return false;

}

// gives the element at the top
int ArrayStack::top()
{
    if(this->topIndex < 0) throw std::out_of_range("Stack Underflow");

    assert(this->topIndex > -1);

    return dataArray[topIndex];

}

ArrayStack::~ArrayStack()
{
    delete this->dataArray;
}