/**
 * @file LinkedListLab3.hpp
 * @author Bishal Neupane
 * @brief A linked list implementation
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <memory>

// using Shared_Node_Ptr as alias to the reference counted shared pointer enclosing node pointer
template <typename NodeData>
class Node;
template <typename NodeData>
using Shared_Node_Ptr = std::shared_ptr<Node<NodeData>>;

/**
 * @brief Datatype representing the node of the linkedlist.
 * Handle nullptr properly as the uninitialized state defaults to nullptr
 * in case of pointers.
 * 
 * @tparam NodeData the generic data contained by the node
 */
template <class NodeData>
class Node
{
public:
    /// @brief The generic data stored by the node
    NodeData data;
    /// @brief Pointer pointing to the next node
    Shared_Node_Ptr<NodeData> next;

    /**
     * @brief default constructor
     * 
     */
    Node();

    /**
     * @brief parametrized constructor
     * 
     * @param data the data to be stored 
     * @param next pointer pointing to the next node
     */
    Node(NodeData data, Shared_Node_Ptr<NodeData> next=nullptr);
};

/**
 * @brief Linked list implementation for generic datatypes
 * 
 * @tparam LinkedListData 
 */
template <class LinkedListData>
class LinkedList
{
private:
    /// @brief pointer pointing to the head of the linked list
    Shared_Node_Ptr<LinkedListData> HEAD;
    /// @brief pointer pointing to the tail of the linked list
    Shared_Node_Ptr<LinkedListData> TAIL;
public:
    /**
     * @brief default constructor
     * 
     */
    LinkedList();

    /**
     * @brief getter
     * 
     * @return Node<LinkedListData>*, head of the linked list
     */
    Shared_Node_Ptr<LinkedListData> getHeadPointer();
    /**
     * @brief getter
     * 
     * @return Node<LinkedListData>* , tail of the linked list
     */
    Shared_Node_Ptr<LinkedListData> getTailPointer();

    /**
     * @brief getter
     * 
     * @param outData the data at head of the list, if there is any 
     * @return true if there is valid data,
     * @return false if the list is empty (HEAD==nullptr)
     */
    bool getHeadData(LinkedListData& outData);

    /**
     * @brief getter
     * 
     * @param outData the data at the tail of the list, if there is any
     * @return true if there is valid data,
     * @return false if the list is empty or if dereferencing tail was unsuccessful
     */
    bool getTailData(LinkedListData& outData);

    /**
     * @brief checks if the list is empty
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
    void addToHead(LinkedListData data);

    /**
     * @brief Inserts an element to the end of the list
     * 
     * @param data The data to be inserted
     */
    void addToTail(LinkedListData data);  

    /**
     * @brief Inserts an element after the given predecessor node
     * 
     * @param data The data to be inserted
     * @param predecessor Pointer pointing to node after which a new node is to be added
     */
    void add(LinkedListData data, Shared_Node_Ptr<LinkedListData> predecessor); 

    /**
     * @brief Removes the first node in the list
     * 
     * @param data: the data present on the removed node (if it was removed successfully) 
     * @returns true if removed successfully, false otherwise
    */
    bool removeFromHead(LinkedListData& data);

    /**
     * @brief Removes the node with the given data
     * 
     * @param data The data to remove
     */
    void remove(LinkedListData data);

    /**
     * @brief Retrive node pointer containing the given data
     * 
     * @param outputNodePointer: the retrived node pointer,
     *  pass by reference is required to properly set the output pointer 
     * @returns true if the data retrival was successful, false otherwise
     * The outputNodePointer is updated if the data retrival was successful
     */
    bool retrieve(LinkedListData data, Shared_Node_Ptr<LinkedListData> &outputNodePointer);

    /**
     * @brief search the give data
     * 
     * @param data the LinkedListData to search in the list
     * @return true if the data is present in the list,
     * @return false otherwise
     */
    bool search(LinkedListData data);

    /**
     * @brief destructor
     * 
     */
    ~LinkedList();


};
#endif
