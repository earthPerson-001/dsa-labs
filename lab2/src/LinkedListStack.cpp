#include "LinkedListStack.hpp"
#include "iostream"
#include "assert.h"

// ctor
LinkedListStack::LinkedListStack(bool fixedSize, int size): fixedSize(fixedSize), size(size)
{

}

// adds an element to the top of the stack
void LinkedListStack::push(int data)
{
    if(this->isFull()) throw std::out_of_range("Stack Overflow");

    this->linkedliststack.addToHead(data);
}

// removes an element from the stack
// also returns the removed element
int LinkedListStack::pop()
{
    int removedData;
    bool removedSuccessfully = this->linkedliststack.removeFromHead(removedData);

    if(!removedSuccessfully) throw std::out_of_range("Stack Underflow");

    else return removedData;
}

// checks if the stack is empty
bool LinkedListStack::isEmpty()
{
    return this->linkedliststack.isEmpty();
}

// checks if the stack if full
bool LinkedListStack::isFull()
{
    if (!fixedSize) return false;

    if(this->getNumberOfElements() > this->size -1)
    {
        return true;
    }

    return false;
}

// gives the element at the top
int LinkedListStack::top()
{
    if(this->isEmpty()) throw std::out_of_range("Stack Underflow");
    int outputData;
    bool returnValue = this->linkedliststack.getHeadData(outputData);
    if(returnValue)
    {
        return outputData;
    }
    else
    {
        throw std::out_of_range("Stack Underflow");
    }
}

int LinkedListStack::getNumberOfElements()
{
    int count = 0;
    for(Shared_Node_Ptr start = this->linkedliststack.getHeadPointer(); start != nullptr; start = start->next)
    {
        assert(start!=nullptr);
        count++;
    }
    return count;
}