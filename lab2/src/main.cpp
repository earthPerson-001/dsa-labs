#include "ArrayStack.hpp"
#include "LinkedListStack.hpp"
#include "iostream"
#include "strings.h"

const char STACK_TYPE[] = "linkedliststack";
const int STACK_SIZE = 5;

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

void _displayTop(Stack* stack)
{
    int top_value;
    bool isTopValid = _top(stack, top_value);

    if(isTopValid)
    {
        std::cout << "\nTop: " << top_value << "\n";
    }
}

int main()
{
    Stack* stack;

    if(strcasecmp(STACK_TYPE, "linkedliststack") == 0)
    {
        bool fixedSizeForStack = true;
        stack = new LinkedListStack(fixedSizeForStack, 5);
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

    return 0;
}