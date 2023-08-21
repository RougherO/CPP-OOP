#include <iterator>
#include <iostream>

class Stack {
    int *buffer, top, size, max_size;

public:
    Stack(int); // create a stack with specified size
    void push(int); // push the specified item
    int pop(); // return the top element
    void disp(); // displays elements in the stack in top to bottom order
    ~Stack();
};

Stack::Stack(int size)
    : buffer { new int[size]() }
    , max_size { size }
    , size {}
{
}

void Stack::push(int data)
{
    if (size == max_size) {
        // throw error
        return;
    }
    buffer[size++] = data;
}

int Stack::pop()
{
    if (size == 0) {
        // throw error;
        return 0;
    }
    return buffer[size--];
}

void Stack::disp()
{
    if (size > 0) {
        for (int i = size - 1; i >= 0; --i) {
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
    }
}

Stack::~Stack()
{
    delete[] buffer;
}

int main()
{
    Stack s(10);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.disp();
}