/**
 * @brief linked list implementation using node pointer
 */

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

class Node
{
public:
    int data;
    Node* next;

    // ctors
    Node();
    Node(int data, Node* next=nullptr);
};

class LinkedList
{
public:
    Node* HEAD;
    Node* TAIL;

    LinkedList();

    // Returns true if the list is empty, and false otherwise
    bool isEmpty(); 

    // Inserts an element to the beginning of the list
    void addToHead(int data);

    // Inserts an element to the end of the list
    void addToTail(int data);  

    // Inserts an element after the given predecessor node
    void add(int data, Node* predecessor); 

    // Removes the first node in the list
    // Returns true if removed successfully, false otherwise
    /** @param data: the data present on the removed node (if it was removed successfully) */
    bool removeFromHead(int& data);

    // Removes the node with the given data
    void remove(int data);

    // Returns the pointer to the node with the requested data
    /** @param outputNodePointer: the retrived node pointer, pass by reference is required to properly set the output pointer */
    bool retrieve(int data, Node* &outputNodePointer);

    // Returns true if the data exists in the list, and false otherwise
    bool search(int data);

    // Displays the contents of the list
    void traverse();

    // Destructor
    ~LinkedList();


};
#endif
