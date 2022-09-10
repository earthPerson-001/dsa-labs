#include "ArrayStack.hpp"
#include "LinkedListStack.hpp"
#include "iostream"
#include "strings.h"
#include "assert.h"


// STACK_TYPE = 0 for arraystack and STACK_TYPE = 1 for linkedlist stack
enum stackTypes{
    ARRAY_STACK = 0,
    LINKED_LIST_STACK = 1,
};

int STACK_TYPE = ARRAY_STACK;
int STACK_SIZE = 5;
bool FIXED_STACK_SIZE = false;  // For linked list stack size

// pushing element with exception handling
bool _push(Stack* stack, int data)
{
    try
    {
        stack->push(data);
        return 1;
    }
    catch(const std::out_of_range& orr)
    {
        std::cerr << orr.what() << '\n';
        return 0;
    }
    
}

// poping element with exception handling
bool _pop(Stack* stack, int& data)
{
    try
    {
        data = stack->pop();
        return 1;
    }
    catch(const std::out_of_range& orr)
    {
        std::cerr << orr.what() << '\n';
        return 0;
    }
    
}

// get the top element with exception handling
bool _top(Stack* stack, int& data)
{
    try
    {
        data = stack->top();
        return 1;
    }
    catch(const std::out_of_range& orr)
    {
        std::cerr << orr.what() << '\n';
        return 0;
    }
    
}

// display the top element from the stack
void _displayTop(Stack* stack)
{
    int top_value;
    bool isTopValid = _top(stack, top_value);

    if(isTopValid)
    {
        std::cout << "\nTop: " << top_value << "\n";
    }
}

int main(int argc, char* argv[])
{
    // Parsing valid command line argument
    for(int i =1; i < argc; i++)
    {
        if(strcasecmp("--type", argv[i]) == 0 || strcasecmp("-t", argv[i]) == 0)
        {
            if(strcasecmp("linkedlist", argv[i+1]) == 0)
            {
                STACK_TYPE = LINKED_LIST_STACK;
            }
        }

        if(strcasecmp("--size", argv[i]) == 0 || strcasecmp("-s", argv[i]) == 0)
        {
            int size = STACK_SIZE;
            try
            {
                size = std::stoi(argv[i+1]);
            }
            catch(const std::invalid_argument& inv_arg)
            {
                std::cout << "\nThe given size is invalid, please enter a valid stack size.";
            }

            if (size < 0)
            {
                std::cout << "\n The entered size isn't a valid size, so using default size of " << STACK_SIZE << " .\n";
            }
            else
            {
                STACK_SIZE = size;
            }
            FIXED_STACK_SIZE = true;
            
        }
    }

    // Giving the information about the stack being initialized
    if(STACK_TYPE==LINKED_LIST_STACK && FIXED_STACK_SIZE)
    {
        std::cout << "\nUsing LinkedList stack of size "<< STACK_SIZE << ".\n";
    }
    else if (STACK_TYPE==LINKED_LIST_STACK) 
    {
        std::cout << "\nUsing LinkedList stack of variable size.\n";
    }
    else 
    {
        std::cout << "\nUsing Array stack of size "<< STACK_SIZE << ".\n";
    }

    Stack* stack;

    if(STACK_TYPE == LINKED_LIST_STACK)
    {
        stack = new LinkedListStack(FIXED_STACK_SIZE, 5);
    }
    else
    {
        stack = new ArrayStack(STACK_SIZE);
    }
    
    int outData;

    _displayTop(stack);

    _push(stack, 1);
    _displayTop(stack);

    std::cout << "Popped element: " << _pop(stack, outData) << " from the stack.\n";
    _displayTop(stack);

    _push(stack, 2);
    _displayTop(stack);

    std::cout << "\n isFull: " << stack->isFull() << std::endl;

    _push(stack, 3);
    _displayTop(stack);

    _push(stack, 4);
    _displayTop(stack);

    _push(stack, 5);
    _displayTop(stack);

    _push(stack, 6);
    _displayTop(stack);

    std::cout << "\n isFull: " << stack->isFull() << std::endl;

    _push(stack, 7);
    _displayTop(stack);

    delete stack;

    return 0;
}