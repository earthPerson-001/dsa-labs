#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

template <class Data>
class Queue
{
private:


public:

    // we don't need to do anything in this destructor, but for runtime polymorphism
    // child's destruction will call parent's destructor it is defined as 
    // not to add separate file
    virtual ~Queue() {}
    
    virtual void enqueue(Data data) = 0;
    virtual Data dequeue() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual Data front() = 0;
    virtual Data back() = 0;
};


#endif