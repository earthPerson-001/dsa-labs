#include <iostream>

#include "LinkedListLab3.hpp"

template <class NodeData>
Node<NodeData>::Node(): next(nullptr)
{}

template <class NodeData>
Node<NodeData>::Node(NodeData data, Node<NodeData> *next): data(data), next(next)
{}

template <class LinkedListData>
LinkedList<LinkedListData>::LinkedList(): HEAD(nullptr), TAIL(nullptr)
{}


// Returns true if the list is empty, and false otherwise
template <class LinkedListData>
bool LinkedList<LinkedListData>::isEmpty()
{
    if(this->HEAD==nullptr) return true;
    return false;
}

// Inserts an element to the beginning of the list
template <class LinkedListData>
void LinkedList<LinkedListData>::addToHead(LinkedListData data)
{
    Node<LinkedListData>* newNode = new Node(data, this->HEAD);
    if(this->HEAD==nullptr)
    {
        this->TAIL=newNode;
    }
    this->HEAD=newNode;

}

// Inserts an element to the end of the list
template <class LinkedListData>
void LinkedList<LinkedListData>::addToTail(LinkedListData data)
{
    if(HEAD==nullptr)
    {
        this->addToHead(data);
    }
    else
    {
        Node<LinkedListData>* newNode = new Node<LinkedListData>(data, nullptr);
        this->TAIL->next = newNode;
        TAIL=newNode;
    }
}

// Inserts an element after the given predecessor node
template <class LinkedListData>
void LinkedList<LinkedListData>::add(LinkedListData data, Node<LinkedListData> *predecessor)
{
    if(predecessor==this->TAIL)
    {
        addToTail(data);
    }
    else
    {
        Node<LinkedListData>* newNode = new Node<LinkedListData>(data, predecessor->next);
        predecessor->next = newNode;
    }
}

// Removes the first node in the list
// Returns true if removed successfully, false otherwise
/** @param data: the data present on the removed node (if it was removed successfully) */
template <class LinkedListData>
bool LinkedList<LinkedListData>::removeFromHead(LinkedListData &data)
{
   if(HEAD==nullptr) return false;

   Node<LinkedListData>* newHead = this->HEAD->next;
   data = HEAD->data;

   delete HEAD;

   HEAD = newHead;

   return true;
}

// Removes the node with the given data
template <class LinkedListData>
void LinkedList<LinkedListData>::remove(LinkedListData data)
{
    if(HEAD==nullptr) return;

    if(HEAD->data==data) this->removeFromHead(data);

    for(Node<LinkedListData>* start = HEAD; start->next != nullptr; start=start->next)
    {
        if(start->next->data == data)
        {
            Node<LinkedListData>* nodeToRemove = start->next;
            start->next = start->next->next;
            delete nodeToRemove;
        }
    }
}

// Returns the pointer to the node with the requested data
/** @param outputNodePointer: the retrived node pointer */
template <class LinkedListData>
bool LinkedList<LinkedListData>::retrieve(LinkedListData data, Node<LinkedListData>* &outputNodePointer)
{
    if(HEAD==nullptr) return false;

    for(Node<LinkedListData>* start = HEAD; start != nullptr; start=start->next)
    {
        if(start->data == data)
        {
            outputNodePointer = start;
            return true;
        }
        else
        {
            outputNodePointer=nullptr;
            return false;
        }
    }
    return false;
}

// Returns true if the data exists in the list, and false otherwise
template <class LinkedListData>
bool LinkedList<LinkedListData>::search(LinkedListData data)
{
    if(HEAD==nullptr) return false;

    for(Node<LinkedListData>* start = HEAD; start != nullptr; start=start->next)
    {
        if(start->data == data)
        {
            return true;
        }
    }
    return false;

}

template <class LinkedListData>
LinkedList<LinkedListData>::~LinkedList()
{

    while(HEAD!=NULL)
    {
        Node<LinkedListData>* nodeToDelete = HEAD;
        HEAD=HEAD->next;

        delete nodeToDelete;
    }
}

template <class LinkedListData>
Node<LinkedListData>* LinkedList<LinkedListData>::getHeadPointer()
{
    return this->HEAD;
}

template <class LinkedListData>
Node<LinkedListData>* LinkedList<LinkedListData>::getTailPointer()
{
    return this->TAIL;
}

template <class LinkedListData>
bool LinkedList<LinkedListData>::getHeadData(LinkedListData& outData)
{
    if(!this->isEmpty())
    {
        outData = this->getHeadPointer()->data;
        return 1;
    }
    return 0;
}

template <class LinkedListData>
bool LinkedList<LinkedListData>::getTailData(LinkedListData& outData)
{
    if(!this->isEmpty())
    {
        outData = this->getTailPointer()->data;
        return 1;
    }
    return 0;
}