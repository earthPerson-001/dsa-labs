/**
 * @file Stack.hpp
 * @author Bishal Neupane
 * @brief Implementation of stack data type
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _STACK_HPP_
#define _STACK_HPP_

/**
 * @brief Implementation of stack data type for integers.
 * This is an interface for stack implementation using arrays or linkedlist
 */
class Stack
{

public:
    /**
     * @brief destructor
     * 
     */
    virtual ~Stack(){};

    /**
     * @brief adds an element into the stack
     * 
     * @param data the data to push
     */
    virtual void push(int data) = 0;

    /**
     * @brief removes an element from the stack
     * 
     * @return int, the removed element
     */
    virtual int pop() = 0;

    /**
     * @brief checks if the stack is empty
     * 
     * @return true if the stack is empty, false otherwise
     */
    virtual bool isEmpty() = 0;

    /**
     * @brief checks if the stack if full
     * 
     * @return true if the stack is full, false otherwise
     */
    virtual bool isFull() =0;

    /**
     * @brief  gives the element at the top
     * 
     * @return int, the element at the top index
     */
    virtual int top() = 0;

};


#endif