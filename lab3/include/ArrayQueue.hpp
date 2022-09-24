#ifndef _ARRAY_QUEUE_HPP_
#define _ARRAY_QUEUE_HPP_

#include "Queue.hpp"

template <class Data>
class ArrayQueue: public Queue<Data>
{
private:
    Data* dataArray;
    int frontIndex;
    int backIndex;
    int maxQueueSize;

public:
    ArrayQueue(int size = 10);
    virtual ~ArrayQueue();
    void enqueue(Data data);
    Data dequeue();
    bool isEmpty();
    bool isFull();
    Data front();
    Data back();
    int getNumberOfElements();
};

#endif