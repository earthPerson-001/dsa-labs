/**
 * @file DoublyLinkedList.hpp
 * @author Bishal Neupane
 * @brief Doubly Linked list implementation for int data type.
 * @version 0.1
 * @date 2024-04-09
 *
 * @copyright Copyright (c) 2024
 */

#ifndef _DOUBLY_LINKED_LIST_HPP_
#define _DOUBLY_LINKED_LIST_HPP_

#include <memory>

class Data
{
private:
    bool is_valid;
    int data;

public:
    Data();
    Data(int data);
    int get();
    bool get_validity();
    void set(int data);
    bool operator==(Data);
    bool operator==(int);
};

class Node;

using Shared_Node_Ptr = std::shared_ptr<Node>;

/**
 * @brief Datatype representing the node of a doubly linked list.
 * Handle nullptr properly as unfilled state defaults to nullptr.
 */
class Node
{
public:
    Data data;
    Shared_Node_Ptr previous;
    Shared_Node_Ptr next;

    /**
     * @brief Default Constructor
     *
     */
    Node();

    /**
     * @brief Parametrized Constructor
     *
     * @param data: The data to be stored in the node
     * @param previous: Shared Node pointer pointing to the previous node, defaults to nullptr
     * @param next: Shared Node pointer pointing to next node, defaults to nullptr
     */
    Node(Data data, Shared_Node_Ptr previous = nullptr, Shared_Node_Ptr next = nullptr);
};

/**
 * @brief Linked List implementation for Node datatype
 *
 */
class DoublyLinkedList
{
private:
    /// @brief Shared Pointer to the first node of the linked list
    Shared_Node_Ptr HEAD;
    /// @brief Shared Pointer to the last node of the linekd list
    Shared_Node_Ptr TAIL;

public:
    /**
     * @brief ctor
     *
     */
    DoublyLinkedList();

    /**
     * @brief getter for head pointer
     *
     * @return Shared_Node_Ptr
     */
    Shared_Node_Ptr getHeadPointer();

    /**
     * @brief getter for tail pointer
     *
     * @return pointer @param Shared_Node_Ptr
     */
    Shared_Node_Ptr getTailPointer();

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
     * @param data The data to be inserted
     */
    void addToHead(Data data);

    /**
     * @brief Inserts an element to the end of the list
     *
     * @param data The data to be inserted
     */
    void addToTail(Data data);

    /**
     * @brief Inserts an element after the given predecessor node
     * @param data  data to insert
     * @param predecessor the node after which new node is to be created
     */
    void add_after(Data data, Shared_Node_Ptr predecessor);

    /**
     * @brief Inserts an element before the given successor node
     * @param data data to insert
     * @param successor the node before which new node is to be created
     */
    void add_before(Data data, Shared_Node_Ptr successor);

    /**
     * @brief
     * @param data: the data present on the removed node (if it was removed successfully)
     * @returns true if removed successfully, false otherwise
     */
    bool removeFromHead(Data &data);

    /**
     * @brief Removes all the nodes with the given data
     *
     * @param data The data whose node is to be removed
     */
    void remove(Data data);

    /**
     * @brief Removes the given node
     *
     * @param data The data whose node is to be removed
     */
    void remove(Shared_Node_Ptr node);

    /**
     * @brief Returns the pointer to the node with the requested data
     * @param outputNodePointer: the retrived shared node pointer, pass by reference is required to properly set the output pointer
     */
    bool retrieve(Data data, Shared_Node_Ptr &outputNodePointer);

    /**
     * @brief search function
     *
     * @param data the Data to search
     * @returns true if the data exists in the list, and false otherwise
     */
    bool search(Data data);

    /**
     * @brief Displays the contents of the list
     *
     */
    void traverse();
};
#endif
