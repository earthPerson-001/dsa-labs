/**
 * @file ArrayQueue.hpp
 * @author Bishal Neupane
 * @brief Queue implementation using array data structure
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _ARRAY_QUEUE_HPP_
#define _ARRAY_QUEUE_HPP_

#include "Queue.hpp"
#include <memory>

/**
 * @brief Queue implementation using generic arrays
 * 
 * @tparam Data the datatype stored by queue
 */
template <class Data>
class ArrayQueue: public Queue<Data>
{
private:
    /// @brief The underlying array to store data (refrence counted shared pointer is used)
    std::shared_ptr<Data[]> dataArray;
    /// @brief The index pointing to the front of the queue
    int frontIndex;
    /// @brief The index pointing to the back of the queue
    int backIndex;
    /// @brief The maximum size of the queue
    int maxQueueSize;

public:
    /**
     * @brief constructor
     * 
     * @param size The maximum size of the queue
     */
    ArrayQueue(std::size_t size = 10);

    /**
     * @brief destructor
     * 
     */
    virtual ~ArrayQueue();

    /**
     * @brief Inserts data at the end of the queue
     * 
     * @param data 
     */
    void enqueue(Data data);

    /**
     * @brief Removes data from the beginning of the queue
     * 
     * @return Data 
     */
    Data dequeue();

    /**
     * @brief Checks if the Queue is empty
     * 
     * @return true if the Queue is empty,
     * @return false otherwise
     */
    bool isEmpty();

    /**
     * @brief Checks if the Queue is full.
     * 
     * @return true if the Queue is full,
     * @return false otherwise
     */
    bool isFull();

    /**
     * 
     * @return Data, the data at the beginning of the queue
     */
    Data front();

    /**
     * 
     * @return Data, the data at the end of the queue
     */
    Data back();

    /**
     * @brief Gets the current number of elements 
     * 
     * @return int 
     */
    int getNumberOfElements();
};

#endif