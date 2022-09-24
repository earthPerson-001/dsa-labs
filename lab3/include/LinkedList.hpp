/**
 * @brief linked list implementation using node pointer
 */

#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

template <class NodeData>
class Node
{
public:
    NodeData data;
    Node* next;

    // ctors
    Node();
    Node(NodeData data, Node* next=nullptr);
};

template <class LinkedListData>
class LinkedList
{
private:
    Node<LinkedListData>* HEAD;
    Node<LinkedListData>* TAIL;
public:
    LinkedList();

    Node<LinkedListData>* getHeadPointer();
    Node<LinkedListData>* getTailPointer();

    bool getHeadData(LinkedListData& outData);
    bool getTailData(LinkedListData& outData);

    // Returns true if the list is empty, and false otherwise
    bool isEmpty(); 

    // Inserts an element to the beginning of the list
    void addToHead(LinkedListData data);

    // Inserts an element to the end of the list
    void addToTail(LinkedListData data);  

    // Inserts an element after the given predecessor node
    void add(LinkedListData data, Node<LinkedListData>* predecessor); 

    // Removes the first node in the list
    // Returns true if removed successfully, false otherwise
    /** @param data: the data present on the removed node (if it was removed successfully) */
    bool removeFromHead(LinkedListData& data);

    // Removes the node with the given data
    void remove(LinkedListData data);

    // Returns the pointer to the node with the requested data
    /** @param outputNodePointer: the retrived node pointer, pass by reference is required to properly set the output pointer */
    bool retrieve(LinkedListData data, Node<LinkedListData>* &outputNodePointer);

    // Returns true if the data exists in the list, and false otherwise
    bool search(LinkedListData data);

    // Destructor
    ~LinkedList();


};
#endif
