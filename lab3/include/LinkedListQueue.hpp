/**
 * @file LinkedListQueue.hpp
 * @author Bishal Neupane
 * @brief Queue implementation using linkedlist data structure
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _LINKED_LIST_QUEUE_HPP_
#define _LINKED_LIST_QUEUE_HPP_

#include "Queue.hpp"
#include "LinkedListLab3.hpp"

/**
 * @brief Queue implementation using linkedlist data structure for generic datatypes
 * 
 * @tparam Data The generic data stored inside of the Queue (linkedlist)
 */
template <class Data>
class LinkedListQueue: public Queue<Data>
{
private:
    LinkedList<Data>* linkedlist;
    bool fixedSize;
    int size;

public:
    /**
     * @brief constructor
     * 
     * @param fixedSize whether to set the queue as fixed size
     * @param size the size of the queue if it's fixed size
     */
    LinkedListQueue(bool fixedSize = false, int size = 10);

    /**
     * @brief destructor
     * 
     */
    virtual ~LinkedListQueue();

    /**
     * @brief Add data to the end of the queue
     * 
     * @param data The generic data to add
     */
    void enqueue(Data data);

    /**
     * @brief Remove data from the beginning of the queue
     * 
     * @return Data The removed data, if dequeue was successful
     */
    Data dequeue();

    /**
     * @brief check if the queue is empty
     * 
     * @return true
     * @return false 
     */
    bool isEmpty();

    /**
     * @brief check if the queue is full
     * if fixedSize if false (the queue isn't a fixed sized one), 
     * then isFull() will always be false
     * 
     * @return true 
     * @return false 
     */
    bool isFull();

    /**
     * @brief get data at the front of the queue
     * 
     * @return Data 
     */
    Data front();

    /**
     * @brief get data at the back of the queue
     * 
     * @return Data 
     */
    Data back();

    /**
     * @brief get the current number of elements
     * 
     * @return int 
     */
    int getNumberOfElements();
};

#endif