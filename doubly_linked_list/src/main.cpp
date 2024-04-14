#include <iostream>

#include "DoublyLinkedList.hpp"

int main()
{
    DoublyLinkedList list;

    list.addToHead(5);
    list.addToHead(7);
    list.addToTail(8);
    list.addToTail(9);
    list.traverse();

    Data output;
    std::cout << "\n After removing from head\n";
    list.removeFromHead(output);
    list.traverse();

    int dataToRemove = 8;
    std::cout << "\n After removing data: " << dataToRemove << std::endl; 
    list.remove(8);
    list.traverse();

    Shared_Node_Ptr outputPointer = nullptr;
    
    Data dataToRetrive = Data(5);

    bool retrivalSuccess = list.retrieve(dataToRetrive, outputPointer);

    if(retrivalSuccess && outputPointer)
    {
        std::cout << "\n The data to retrive: " << dataToRetrive.get() << " was in " << outputPointer << std::endl;
        std::cout << "\n Inserting the node after " << outputPointer << std::endl;
        list.add_after(Data(10), outputPointer);

        std::cout << "\n Inserting the node before " << outputPointer << std::endl;
        list.add_before(Data(30), outputPointer);
    }
    else
    {
        std::cout << "\n The data to retrive: " << dataToRetrive.get() << " was not found. " << std::endl;
    }

    list.traverse();

    int searchValue = 10;
    std::cout << "\n Searching for " << searchValue << "\nSearch Result: ";
    if(list.search(searchValue)) std::cout << "Found\n";
    else std::cout<< "Not Found\n"; 
    

    return 0;
}