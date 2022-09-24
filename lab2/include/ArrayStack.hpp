/**
 * @file ArrayStack.hpp
 * @author Bishal Neupane
 * @brief Fixed size stack implementation using array
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _ARRAY_STACK_HPP_
#define _ARRAY_STACK_HPP_

#include "Stack.hpp"

/**
 * @brief Stack implementation for integers
 * 
 */
class ArrayStack: public Stack
{
private:
    
    /// @brief The maximum size of array which represents the stack
    int size;
    /// @brief Index representing the top index of the stack
    int topIndex;
    /// @brief The underlying array of the stack
    int* dataArray;

public:
    /**
     * @brief constructor
     * 
     * @param size The maximum size of the stack
     */
    ArrayStack(int size = 100);

    /**
     * @brief destructor
     * 
     */
    virtual ~ArrayStack();

    /**
     * @brief adds an element to the top of the stack
     * 
     * @param data the element to add
     */
    void push(int data);

    /**
     * @brief Removes the element from the top of the stack
     * 
     * @return the removed integer
     */
    int pop();

    /**
     * @brief check if the stack is empty
     * 
     * @return true if the stack is empty,
     * @return false otherwise
     */
    bool isEmpty();

    /**
     * @brief check if the stack is full
     * 
     * @return true if the stack is full,
     * @return false otherwise
     */
    bool isFull();

    /**
     * @brief peek the stack
     * 
     * @return the integer at the top index
     */
    int top();

};


#endif