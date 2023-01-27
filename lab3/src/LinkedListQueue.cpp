#include "LinkedListQueue.hpp"
#include <iostream>
#include <assert.h>

template <class Data>
LinkedListQueue<Data>::LinkedListQueue(bool fixedSize, int size): fixedSize(fixedSize), size(size)
{
    this->linkedlist = new LinkedList<Data>();
}

template <class Data>
LinkedListQueue<Data>::~LinkedListQueue()
{
    delete this->linkedlist;
}

template <class Data>
void LinkedListQueue<Data>::enqueue(Data data)
{
    if(!this->isFull())
    {
        this->linkedlist->addToTail(data);
    }
    else
    {
        throw std::out_of_range("Queue Overflow");
    }
    
}

template <class Data>
Data LinkedListQueue<Data>::dequeue()
{
    Data outputData;
    bool returnValue = this->linkedlist->removeFromHead(outputData);
    if(returnValue)
    {
        return outputData;
    }
    else
    {
        throw std::out_of_range("Queue Underflow");
    }

}

template <class Data>
bool LinkedListQueue<Data>::isEmpty()
{
    return this->linkedlist->isEmpty();
}

template <class Data>
bool LinkedListQueue<Data>::isFull()
{
    if (!fixedSize) return false;

    if(this->getNumberOfElements() > this->size -1)
    {
        return true;
    }

    return false;
}

template <class Data>
Data LinkedListQueue<Data>::front()
{
    Data outputData;
    bool returnValue = this->linkedlist->getHeadData(outputData);
    if(returnValue)
    {
        return outputData;
    }
    else
    {
        throw std::out_of_range("Queue Underflow");
    }
}

template <class Data>
Data LinkedListQueue<Data>::back()
{
    Data outputData;
    bool returnValue = this->linkedlist->getTailData(outputData);
    if(returnValue)
    {
        return outputData;
    }
    else
    {
        throw std::out_of_range("Queue Underflow");
    }
}

template <class Data>
int LinkedListQueue<Data>::getNumberOfElements()
{
    int count = 0;
    for(Shared_Node_Ptr<Data> start = this->linkedlist->getHeadPointer(); start != nullptr; start = start->next)
    {
        assert(start!=nullptr);
        count++;
    }
    return count;
}

