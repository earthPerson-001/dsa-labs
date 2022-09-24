/**
 * @file LinkedListLab2.hpp
 * @author Bishal Neupane
 * @brief Linked list implementation for integer data type.
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef _LINKED_LIST_LAB_2_HPP_
#define _LINKED_LIST_LAB_2_HPP_

/**
 * @brief Datatype representing the node of a linked list.
 * Handle nullptr properly as unfilled state defaults to nullptr.
 */
class Node
{
public:
    int data;
    Node* next;

    /**
     * @brief Default Constructor
     * 
     */
    Node();

    /**
     * @brief Parametrized Constructor
     * 
     * @param data: The integer data to be stroed in the node
     * @param next: Node pointer pointer to next node, defaults to nullptr
     */
    Node(int data, Node* next=nullptr);
};

/**
 * @brief Linked List implementation for Node datatype
 * 
 */
class LinkedList
{
private:
    /// @brief Pointer to the first node of the linked list
    Node* HEAD;
    /// @brief Pointer to the last node of the linekd list
    Node* TAIL;
public:
    /**
     * @brief ctor
     * 
     */
    LinkedList();

    /**
     * @brief getter for head pointer
     * 
     * @return Node* 
     */
    Node* getHeadPointer();

    /**
     * @brief getter for tail pointer
     * 
     * @return pointer @param Node* 
     */
    Node* getTailPointer();

    /**
     * @brief getter for data stored in head pointer
     * 
     * @param outData 
     * @return true if the list isn't empty and outData will have valid data in this case,
     * @return false otherwise
     */
    bool getHeadData(int& outData);

    /**
     * @brief getter for data stored in tail pointer
     * 
     * @param outData 
     * @return true if the list isn't empty and outData will have valid data in this case,
     * @return false otherwise
     */
    bool getTailData(int& outData);

    /**
     * @brief To find out if the list is empty or not
     * 
     * @return true if the list is empty,
     * @return false otherwise
     */ 
    bool isEmpty(); 

    /**
     * @brief Inserts an element to the beginning of the list
     * 
     * @param data The integer to be inserted
     */
    void addToHead(int data);

    /**
     * @brief Inserts an element to the end of the list
     * 
     * @param data The integer to be inserted
     */
    void addToTail(int data);  

    /**
     * @brief Inserts an element after the given predecessor node
     * @param data integer data to insert
     * @param predecessor the node after which new node is to be created
     */
    void add(int data, Node* predecessor); 

    /**
     * @brief 
     * @param data: the data present on the removed node (if it was removed successfully) 
     * @returns true if removed successfully, false otherwise
     */
    bool removeFromHead(int& data);

    /**
     * @brief Removes the node with the given data
     * 
     * @param data The data whose node is to be removed
     */
    void remove(int data);

    /**
     * @brief Returns the pointer to the node with the requested data
     * @param outputNodePointer: the retrived node pointer, pass by reference is required to properly set the output pointer
    */
    bool retrieve(int data, Node* &outputNodePointer);

    /**
     * @brief search function
     * 
     * @param data the integer to search
     * @returns true if the data exists in the list, and false otherwise 
     */
    bool search(int data);

    /**
     * @brief destructor
     * 
     */
    ~LinkedList();

};
#endif
