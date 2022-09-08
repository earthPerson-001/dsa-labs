#include <iostream>

#include "LinkedList.hpp"


Node::Node(): next(nullptr)
{}

Node::Node(int data, Node *next): data(data), next(next)
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
    Node* newNode = new Node(data, this->HEAD);
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
        Node* newNode = new Node(data, nullptr);
        this->TAIL->next = newNode;
        TAIL=newNode;
    }
}

// Inserts an element after the given predecessor node
void LinkedList::add(int data, Node *predecessor)
{
    if(predecessor==this->TAIL)
    {
        addToTail(data);
    }
    else
    {
        Node* newNode = new Node(data, predecessor->next);
        predecessor->next = newNode;
    }
}

// Removes the first node in the list
// Returns true if removed successfully, false otherwise
/** @param data: the data present on the removed node (if it was removed successfully) */
bool LinkedList::removeFromHead(int &data)
{
   if(HEAD==nullptr) return false;

   Node* newHead = this->HEAD->next;
   data = HEAD->data;

   delete HEAD;

   HEAD = newHead;

   return true;
}

// Removes the node with the given data
void LinkedList::remove(int data)
{
    if(HEAD==nullptr) return;

    if(HEAD->data==data) this->removeFromHead(data);

    for(Node* start = HEAD; start->next != nullptr; start=start->next)
    {
        if(start->next->data == data)
        {
            Node* nodeToRemove = start->next;
            start->next = start->next->next;
            delete nodeToRemove;
        }
    }
}

// Returns the pointer to the node with the requested data
/** @param outputNodePointer: the retrived node pointer */
bool LinkedList::retrieve(int data, Node* &outputNodePointer)
{
    if(HEAD==nullptr) return false;

    for(Node* start = HEAD; start != nullptr; start=start->next)
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

    for(Node* start = HEAD; start != nullptr; start=start->next)
    {
        if(start->data == data)
        {
            return true;
        }
    }
    return false;

}

// Displays the contents of the list
void LinkedList::traverse()
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout <<   "|S.N.     |     DATA                                        \n";

    if(HEAD==nullptr) return;

    int sn=1;
    for(Node* start = HEAD; start != nullptr; start=start->next)
    {
        std::cout << "|" << sn << "        |     " << start->data << std::endl;
        sn++;
    }
}

LinkedList::~LinkedList()
{

    while(HEAD!=NULL)
    {
        Node* nodeToDelete = HEAD;
        HEAD=HEAD->next;

        delete nodeToDelete;
    }
}

