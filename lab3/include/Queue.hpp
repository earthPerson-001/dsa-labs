/**
 * @file Queue.hpp
 * @author Bishal Neupane
 * @brief Implementation of queue data structure
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

/**
 * @brief Queue implementation for generic data types.
 * An Interface class for queue 
 * 
 * @tparam Data 
 */
template <class Data>
class Queue
{
private:


public:

    /* we don't need to do anything in this destructor, but for runtime polymorphism
     child's destruction will call parent's destructor 
     it is defined as not to add a separate file
     */ 
    /**
     * @brief destructor
     * 
     */
    virtual ~Queue() {}
    
    /**
     * @brief Add data to the back of the queue
     * 
     * @param data 
     */
    virtual void enqueue(Data data) = 0;

    /**
     * @brief Remove data from the front of the queue
     * 
     * @return Data 
     */
    virtual Data dequeue() = 0;

    /**
     * @brief Check if the queue is empty
     * 
     * @return true 
     * @return false 
     */
    virtual bool isEmpty() = 0;

    /**
     * @brief Check if the queue if full
     * 
     * @return true 
     * @return false 
     */
    virtual bool isFull() = 0;

    /**
     * @brief Get data at the front of the queue
     * 
     * @return Data 
     */
    virtual Data front() = 0;

    /**
     * @brief Get data at the back of the queue
     * 
     * @return Data 
     */
    virtual Data back() = 0;
};


#endif