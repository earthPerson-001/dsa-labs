#include <iostream>

#include "DoublyLinkedList.hpp"

Data::Data() : is_valid(false), data(0)
{
}

Data::Data(int data) : is_valid(true), data(data)
{
}

/***
 * Always check if the data is valid before getting the raw data
 *
 */
int Data::get()
{
    return this->data;
}

bool Data::get_validity()
{
    return this->is_valid;
}

void Data::set(int data)
{
    this->data = data;
}

/** No point in equating if the stored data is invalid*/
bool Data::operator==(Data d)
{
    return this->is_valid && d.is_valid && this->data == d.data;
}

/** No point in equating if the stored data is invalid*/
bool Data::operator==(int d)
{
    return this->is_valid && this->data == d;
}

/**
 * @brief Default Constructor
 *
 */
Node::Node() : previous(nullptr), next(nullptr)
{
    this->data = Data();
}

/**
 * @brief Parametrized Constructor
 *
 * @param previous: Shared Node pointer pointing to the previous node, defaults to nullptr
 * @param data: The data to be stored in the node
 * @param next: Shared Node pointer pointing to next node, defaults to nullptr
 */
Node::Node(Data data, Shared_Node_Ptr previous, Shared_Node_Ptr next)
    : data(data), previous(previous), next(next)
{
}

/**
 * @brief ctor
 *
 */
DoublyLinkedList::DoublyLinkedList() : HEAD(nullptr), TAIL(nullptr)
{
}

/**
 * @brief getter for head pointer
 *
 * @return Shared_Node_Ptr
 */
Shared_Node_Ptr DoublyLinkedList::getHeadPointer()
{
    return this->HEAD;
}

/**
 * @brief getter for tail pointer
 *
 * @return pointer @param Shared_Node_Ptr
 */
Shared_Node_Ptr DoublyLinkedList::getTailPointer()
{
    return this->TAIL;
}

/**
 * @brief To find out if the list is empty or not
 *
 * @return true if the list is empty,
 * @return false otherwise
 */
bool DoublyLinkedList::isEmpty()
{
    return this->HEAD == nullptr;
}

/**
 * @brief Inserts an element to the beginning of the list
 *
 * @param data The data to be inserted
 */
void DoublyLinkedList::addToHead(Data data)
{
    Shared_Node_Ptr newNode = std::make_shared<Node>(data, nullptr, this->HEAD);
    if (this->HEAD == nullptr)
    {
        this->TAIL = newNode;
    }
    this->HEAD = newNode;
}

/**
 * @brief Inserts an element to the end of the list
 *
 * @param data The data to be inserted
 */
void DoublyLinkedList::addToTail(Data data)
{
    if (HEAD == nullptr)
    {
        this->addToHead(data);
    }
    else
    {
        Shared_Node_Ptr newNode = std::make_shared<Node>(data, this->TAIL, nullptr);
        this->TAIL->next = newNode;
        TAIL = newNode;
    }
}

/**
 * @brief Inserts an element after the given predecessor node
 * @param data  data to insert
 * @param predecessor the node after which new node is to be created
 */
void DoublyLinkedList::add_after(Data data, Shared_Node_Ptr predecessor)
{
    if (predecessor == this->TAIL)
    {
        addToTail(data);
    }
    else
    {
        Shared_Node_Ptr newNode = std::make_shared<Node>(data, predecessor, predecessor->next);
        predecessor->next->previous = newNode;
        predecessor->next = newNode;
    }
}

/**
 * @brief Inserts an element before the given successor node
 * @param data data to insert
 * @param successor the node before which new node is to be created
 */
void DoublyLinkedList::add_before(Data data, Shared_Node_Ptr successor)
{
    if (successor == this->HEAD)
    {
        addToHead(data);
    }
    else
    {
        Shared_Node_Ptr newNode = std::make_shared<Node>(data, successor->previous, successor);
        successor->previous->next = newNode;
        successor->previous = newNode;
    }
}

/**
 * @brief
 * @param data: the data present on the removed node (if it was removed successfully)
 * @returns true if removed successfully, false otherwise
 */
bool DoublyLinkedList::removeFromHead(Data &data)
{

    if (HEAD == nullptr)
        return false;

    Shared_Node_Ptr newHead = this->HEAD->next;
    newHead->previous = nullptr;
    data = HEAD->data;

    HEAD = newHead;

    return true;
}

/**
 * @brief Removes all the nodes with the given data
 *
 * @param data The data whose node is to be removed
 */
void DoublyLinkedList::remove(Data data)
{

    if (HEAD == nullptr)
        return;

    if (HEAD->data == data)
        this->removeFromHead(data);

    for (Shared_Node_Ptr start = HEAD; start->next != nullptr; start = start->next)
    {
        if (start->next->data == data)
        {
            // because of shared_ptr, there is no need to delete manually
            start->next = start->next->next;
        }
    }
}

/**
 * @brief Removes the given node
 *
 * @param data The data whose node is to be removed
 */
void DoublyLinkedList::remove(Shared_Node_Ptr node)
{
    node->previous->next = node->next;
    node->next->previous = node->previous;
}

/**
 * @brief Returns the pointer to the node with the requested data, if found returns true and outputNodePointer contains reference to that Node
 * @param outputNodePointer: the retrived shared node pointer, pass by reference is required to properly set the output pointer
 */
bool DoublyLinkedList::retrieve(Data data, Shared_Node_Ptr &outputNodePointer)
{
    if (HEAD == nullptr)
        return false;

    outputNodePointer = nullptr;
    for (Shared_Node_Ptr start = HEAD; start != nullptr; start = start->next)
    {
        if (start->data == data)
        {
            outputNodePointer = start;
            return true;
        }
    }
    return false;
}

/**
 * @brief search function
 *
 * @param data the Data to search
 * @returns true if the data exists in the list, and false otherwise
 */
bool DoublyLinkedList::search(Data data)
{
    if (HEAD == nullptr)
        return false;

    for (Shared_Node_Ptr start = HEAD; start != nullptr; start = start->next)
    {
        if (start->data == data)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Displays the contents of the list
 *
 */
void DoublyLinkedList::traverse()
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "|S.N.     |     DATA                                        \n";

    if (HEAD == nullptr)
        return;

    int sn = 1;
    for (Shared_Node_Ptr start = HEAD; start != nullptr; start = start->next)
    {
        if (start->data.get_validity()) {
            std::cout << "|" << sn << "        |     " << start->data.get() << std::endl;
        } else {
            std::cout << "|" << sn << "        |     " << " - " << std::endl;
        }

        sn++;

    }
}
