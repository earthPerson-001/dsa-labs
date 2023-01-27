#include <iostream>

#include "LinkedListLab2.hpp"


Node::Node(): next(nullptr)
{}

Node::Node(int data, Shared_Node_Ptr next): data(data), next(next)
{}

LinkedList::LinkedList(): HEAD(nullptr), TAIL(nullptr)
{}


// Returns true if the list is empty, and false otherwise
bool LinkedList::isEmpty()
{
    if(this->HEAD==nullptr) return true;
    return false;
}

// Inserts an element to the beginning of the list
void LinkedList::addToHead(int data)
{
    Shared_Node_Ptr newNode = std::make_shared<Node>(data, this->HEAD);
    if(this->HEAD==nullptr)
    {
        this->TAIL=newNode;
    }
    this->HEAD=newNode;

}

// Inserts an element to the end of the list
void LinkedList::addToTail(int data)
{
    if(HEAD==nullptr)
    {
        this->addToHead(data);
    }
    else
    {
        Shared_Node_Ptr newNode = std::make_shared<Node>(data, nullptr);
        this->TAIL->next = newNode;
        TAIL=newNode;
    }
}

// Inserts an element after the given predecessor node
void LinkedList::add(int data, Shared_Node_Ptr predecessor)
{
    if(predecessor==this->TAIL)
    {
        addToTail(data);
    }
    else
    {
        Shared_Node_Ptr newNode = std::make_shared<Node>(data, predecessor->next);
        predecessor->next = newNode;
    }
}

// Removes the first node in the list
// Returns true if removed successfully, false otherwise
/** @param data: the data present on the removed node (if it was removed successfully) */
bool LinkedList::removeFromHead(int &data)
{
   if(HEAD==nullptr) return false;

   Shared_Node_Ptr newHead = this->HEAD->next;
   data = HEAD->data;

   HEAD = newHead;

   return true;
}

// Removes the node with the given data
void LinkedList::remove(int data)
{
    if(HEAD==nullptr) return;

    if(HEAD->data==data) this->removeFromHead(data);

    for(Shared_Node_Ptr start = HEAD; start->next != nullptr; start=start->next)
    {
        if(start->next->data == data)
        {
            start->next = start->next->next;
        }
    }
}

// Returns the pointer to the node with the requested data
/** @param outputNodePointer: the retrived node pointer */
bool LinkedList::retrieve(int data, Shared_Node_Ptr &outputNodePointer)
{
    if(HEAD==nullptr) return false;

    for(Shared_Node_Ptr start = HEAD; start != nullptr; start=start->next)
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
bool LinkedList::search(int data)
{
    if(HEAD==nullptr) return false;

    for(Shared_Node_Ptr start = HEAD; start != nullptr; start=start->next)
    {
        if(start->data == data)
        {
            return true;
        }
    }
    return false;

}

LinkedList::~LinkedList()
{

    while(HEAD!=NULL)
    {
        Shared_Node_Ptr nodeToDelete = HEAD;
        HEAD=HEAD->next;
    }
}


Shared_Node_Ptr LinkedList::getHeadPointer()
{
    return this->HEAD;
}

Shared_Node_Ptr LinkedList::getTailPointer()
{
    return this->TAIL;
}

bool LinkedList::getHeadData(int& outData)
{
    if(!this->isEmpty())
    {
        outData = this->getHeadPointer()->data;
        return 1;
    }
    return 0;
}

bool LinkedList::getTailData(int& outData)
{
    if(!this->isEmpty())
    {
        outData = this->getTailPointer()->data;
        return 1;
    }
    return 0;
}