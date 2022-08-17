#include <iostream>

#include "LinkedList.h"

int main()
{
    LinkedList list;

    list.addToHead(5);
    list.addToHead(7);
    list.addToTail(8);
    list.addToTail(9);
    list.traverse();

    int output;
    std::cout << "\n After removing from head\n";
    list.removeFromHead(output);
    list.traverse();

    int dataToRemove = 8;
    std::cout << "\n After removing data: " << dataToRemove << std::endl; 
    list.remove(8);
    list.traverse();

    Node* outputPointer = nullptr;
    int dataToRetrive = 5;

    bool retrivalSuccess = list.retrieve(dataToRetrive, outputPointer);

    if(retrivalSuccess && outputPointer)
    {
        std::cout << "\n The data to retrive: "<< dataToRetrive << " was in " << outputPointer << std::endl;
        std::cout << "\n Inserting the node after " << outputPointer << std::endl;
        list.add(10, outputPointer);
    }
    else
    {
        std::cout << "\n The data to retrive: "<< dataToRetrive << " was not found. " << std::endl;
    }

    list.traverse();

    int searchValue = 10;
    std::cout << "\n Searching for " << searchValue << "\nSearch Result: ";
    if(list.search(searchValue)) std::cout << "Found\n";
    else std::cout<< "Not Found\n"; 
    

    return 0;
}