#ifndef _LINKED_LIST_QUEUE_HPP_
#define _LINKED_LIST_QUEUE_HPP_

#include "Queue.hpp"
#include "LinkedListLab3.hpp"

template <class Data>
class LinkedListQueue: public Queue<Data>
{
private:
    LinkedList<Data>* linkedlist;
    bool fixedSize;
    int size;

public:
    LinkedListQueue(bool fixedSize = false, int size = 10);
    virtual ~LinkedListQueue();
    void enqueue(Data data);
    Data dequeue();
    bool isEmpty();
    bool isFull();
    Data front();
    Data back();
    int getNumberOfElements();
};

#endif