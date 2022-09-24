/**
 * @file LinkedListStack.hpp
 * @author Bishal Neupane
 * @brief Stack implementation using linked list data type
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _LINKED_LIST_STACK_HPP_
#define _LINKED_LIST_STACK_HPP_

#include "Stack.hpp"
#include "LinkedListLab2.hpp"

/**
 * @brief Stack implementation using linked list data type.
 * Insertion and removal is done from the head of the linked list
 */
class LinkedListStack: public Stack 
{
private:
    /// @brief The underlying linkedlist of the stack
    LinkedList linkedliststack;
    /// @brief The fixed size nature of the stack
    bool fixedSize;
    /// @brief The size of the stack if the stack is fixed size
    int size;

public:

    /**
     * @brief constructor
     * 
     * @param fixedSize either the stack needs to be fixed size
     * @param size the maximum size of the stack if the stack is fixed size
     */
    LinkedListStack(bool fixedSize = false, int size = 100);

    /**
     * @brief adds an element to the top of the stack
     * 
     * @param data the integer to be added
     */
    void push(int data);

    /**
     * @brief removes an element from the stack
     * 
     * @return int, the removed element 
     */ 
    int pop();

    /**
     * @brief checks if the stack is empty.
     
     * 
     * @return true if the stack is empty false otherwise
     */
    bool isEmpty();

    /**
     * @brief checks if the stack if full
     * if the stack type of set to variable size (!fixedSize==true) then 
     * the stack is never full
     * 
     * @return true if the stack is true, false otherwise
     */
    bool isFull();

    /**
     * @brief peek the stack
     * 
     * @return int, the element at the top of the stack 
     */
    int top();

    /**
     * @brief getter
     * 
     * @return int, the number of filled positions
     */
    int getNumberOfElements();

};



#endif