#include "ArrayQueue.hpp"
#include <iostream>

template <class Data>
ArrayQueue<Data>::ArrayQueue(int size): maxQueueSize(size)
{
    this->dataArray = new Data[maxQueueSize];
    this->frontIndex = -1;
    this->backIndex = -1;
}

template <class Data>
ArrayQueue<Data>::~ArrayQueue()
{
    delete[] this->dataArray;
}

template <class Data>
void ArrayQueue<Data>::enqueue(Data data)
{
    if(this->isEmpty())
    {
        frontIndex = 0;
    }
    else if (this->isFull())
    {
        throw std::out_of_range("Queue Overflow");
    }
    
    backIndex = (backIndex + 1) % maxQueueSize;
    this->dataArray[backIndex] = data;

}

template <class Data>
Data ArrayQueue<Data>::dequeue()
{
    if(this->isEmpty())
    {
        throw std::out_of_range("Queue Underflow");
    }
    else if(this->frontIndex == this->backIndex)
    {
        Data outputData = this->dataArray[frontIndex];
        frontIndex = backIndex = -1;
        return outputData;
    }
    else
    {
        Data outputData = this->dataArray[frontIndex];
        frontIndex = (frontIndex + 1) % maxQueueSize;
        return outputData;
    }
}

template <class Data>
bool ArrayQueue<Data>::isEmpty()
{
    if(this->frontIndex == this->backIndex && this->frontIndex == -1)
    {
        return 1;
    }
    return 0;
}

template <class Data>
bool ArrayQueue<Data>::isFull()
{
    if((this->backIndex + 1)%maxQueueSize == frontIndex) return 1;
    return 0;
}

template <class Data>
Data ArrayQueue<Data>::front()
{
    if(!this->isEmpty())
    {
        return this->dataArray[frontIndex];
    }
    else
    {
        throw std::out_of_range("Queue Underflow");
    }
}

template <class Data>
Data ArrayQueue<Data>::back()
{
    if(!this->isEmpty())
    {
        return this->dataArray[this->backIndex];
    }
    else
    {
        throw std::out_of_range("Queue Underflow");
    }
}