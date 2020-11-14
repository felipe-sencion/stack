#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stdexcept>
#include "ldl.h"

using namespace std;

template<typename T>
class Stack
{
private:
    LDL<T> list;

public:
    Stack()
    {

    }
    ~Stack()
    {
        list.clear();
    }
    bool empty() const;
    size_t size() const;
    const T& top() const;
    void push(const T& element);
    void pop();
};

template<typename T>
bool Stack<T>::empty() const
{
    return list.empty();
}

template<typename T>
size_t Stack<T>::size() const
{
    return list.size();
}

template<typename T>
const T& Stack<T>::top() const
{
    if (empty())
    {
        throw runtime_error("Trying top() from empty stack.");
    }
    return list.back();
}

template<typename T>
void Stack<T>::push(const T& element)
{
    list.push_back(element);
}

template<typename T>
void Stack<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from empty stack.");
    }
    list.pop_back();
}
#endif // STACK_H
