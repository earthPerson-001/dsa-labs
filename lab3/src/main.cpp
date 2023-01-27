#include "LinkedListQueue.hpp"
#include "ArrayQueue.hpp"

// For solving linking errors caused due to templates
#include "LinkedList.cpp"
#include "LinkedListQueue.cpp"
#include "ArrayQueue.cpp"

#include <iostream>
#include <strings.h>

enum QueueTypes
{
    LINKED_LIST_QUEUE = 0,
    ARRAY_QUEUE,
};

// some values dependent upon the command line input
QueueTypes QUEUE_TYPE = ARRAY_QUEUE;
int MAX_QUEUE_SIZE = 10;
bool FIXED_MAX_QUEUE_SIZE = false;

// wrapping the function calls to catch exceptions

template <class Data>
void _enqueue(std::shared_ptr<Queue<Data>> queue, Data data)
{
    try
    {
        queue->enqueue(data);
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << oor.what() << '\n';
    }
}

template <class Data>
bool _dequeue(std::shared_ptr<Queue<Data>> queue, Data &outData)
{
    try
    {
        outData = queue->dequeue();
        return true;
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << oor.what() << '\n';
    }
    return false;
}

template <class Data>
bool _front(std::shared_ptr<Queue<Data>> queue, Data &outData)
{
    try
    {
        outData = queue->front();
        return 1;
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << oor.what() << '\n';
    }
    return 0;
}

template <class Data>
bool _back(std::shared_ptr<Queue<Data>> queue, Data &outData)
{
    try
    {
        outData = queue->back();
        return 1;
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << oor.what() << '\n';
    }
    return 0;
}

template <class T>
void testQueueFunctions(std::shared_ptr<Queue<T>> queue, T *enqueueArray, size_t enqueueArraySize)
{

    // determining the type name of the datatype
    std::string typeName = typeid(T).name();
    std::cout << "\n**************************************************************\n";
    std::cout << "\nTesting for i(int), f(float), c(char): \033[0;32m" << typeName << " \033[0;m datatype. \n";

    // testing if the queue is empty initially
    std::cout << "\nIs the queue empty? : " << queue->isEmpty() << std::endl;

    // adding all the elements if possible
    for (int count = 0; count < enqueueArraySize; count++)
    {
        T element = enqueueArray[count];
        std::cout << "\n \033[0;32m + \033[0m Adding " << element << " to the back.";
        _enqueue(queue, element);
    }

    // testing if the queue is empty now
    std::cout << "\nIs the queue empty? : " << queue->isEmpty() << std::endl;

    // testing if the queue is full now
    std::cout << "\nIs the queue full? : " << queue->isFull() << std::endl;

    // removing all the elements
    T outData;
    while (!queue->isEmpty())
    {
        if (_dequeue(queue, outData))
            std::cout << "\n \033[0;31m - \033[0m Dequeued data " << outData;
    }

    // adding element until the queue is full ( if the queue has a max size)
    if (FIXED_MAX_QUEUE_SIZE)
    {
        int index = 0;
        while (!queue->isFull())
        {
            if (index > enqueueArraySize - 1)
                index = 0;

            T element = enqueueArray[index];
            std::cout << "\n \033[0;32m + \033[0m Adding " << element << " to the back.";
            _enqueue(queue, element);

            index++;
        }
    }

    // testing if the queue is full now
    std::cout << "\nIs the queue full? : " << queue->isFull() << std::endl;

    // testing front() and back()
    T outDataFront, outDataBack;
    if (_front(queue, outData) && _back(queue, outDataBack))
    {
        std::cout << "\nFront: " << outData << "\t Back: " << queue->back();
    }

    std::cout << "\n**************************************************************\n";
}

// main method
int main(int argc, char *argv[])
{

    // Parsing valid command line argument
    for (int i = 1; i < argc; i++)
    {
        if (strcasecmp("--type", argv[i]) == 0 || strcasecmp("-t", argv[i]) == 0)
        {
            if (strcasecmp("linkedlist", argv[i + 1]) == 0)
            {
                QUEUE_TYPE = LINKED_LIST_QUEUE;
            }
        }

        if (strcasecmp("--size", argv[i]) == 0 || strcasecmp("-s", argv[i]) == 0)
        {
            int size = MAX_QUEUE_SIZE;
            try
            {
                size = std::stoi(argv[i + 1]);
            }
            catch (const std::invalid_argument &inv_arg)
            {
                std::cout << "\nThe given size is invalid, please enter a valid stack size.";
            }

            if (size < 0)
            {
                std::cout << "\n The entered size isn't a valid size, so using default size of " << MAX_QUEUE_SIZE << " .\n";
            }
            else
            {
                MAX_QUEUE_SIZE = size;
            }
            FIXED_MAX_QUEUE_SIZE = true;
        }
    }

    std::shared_ptr<Queue<int>> integerQueue;
    std::shared_ptr<Queue<float>> floatQueue;
    std::shared_ptr<Queue<char>> charQueue;

    if (QUEUE_TYPE == LINKED_LIST_QUEUE)
    {
        integerQueue = std::make_shared<LinkedListQueue<int>>(FIXED_MAX_QUEUE_SIZE, MAX_QUEUE_SIZE);
        floatQueue = std::make_shared<LinkedListQueue<float>>(FIXED_MAX_QUEUE_SIZE, MAX_QUEUE_SIZE);
        charQueue = std::make_shared<LinkedListQueue<char>>(FIXED_MAX_QUEUE_SIZE, MAX_QUEUE_SIZE);
    }
    else
    {
        integerQueue = std::make_shared<ArrayQueue<int>>(MAX_QUEUE_SIZE);
        floatQueue = std::make_shared<ArrayQueue<float>>(MAX_QUEUE_SIZE);
        charQueue = std::make_shared<ArrayQueue<char>>(MAX_QUEUE_SIZE);
    }

    int integerArray[] = {1, 2, 3, 4, 5, 6, 7};
    float floatArray[] = {1.2345, 42.424132, 52423.2342, 4123.123};
    char charArray[] = {'a', '1', '3', '5', '7', '9', 'z'};

    testQueueFunctions(integerQueue, integerArray, sizeof(integerArray) / sizeof(integerArray[0]));
    testQueueFunctions(floatQueue, floatArray, sizeof(floatArray) / sizeof(floatArray[0]));
    testQueueFunctions(charQueue, charArray, sizeof(charArray) / sizeof(charArray[0]));

    return 0;
}
