#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <iostream>

template<typename T>
struct Node {
    Node<T>* previous;
    T val;
};

template<typename T>
class Stack {
    Node<T>* current;
    int size;
public:
    Stack()
        :size(0), current(nullptr)
    {}
    virtual ~Stack() {
        while (current)
        {
            Node<T>* tmp = current;
            current = current->previous;
            delete tmp;
        }
    }
    bool push(T value)
    {
        Node<T>* tmp = new Node<T>;
        tmp->val = value;
        tmp->previous = current;
        current = tmp;
        ++size;
        return true;
    }
    T pop()
    {
        if (size == 0)
        {
            std::cerr << "Can't use pop() method on empty Stack!" << std::endl;
            assert(false);
        }

        Node<T>* tmp = current;
        T tmpVal = tmp->val;
        if (size == 1)
            current = nullptr;
        else if (size > 1) 
        {
            current = current->previous;
        }

        --size;
        delete tmp;
        return tmpVal;
    }
    int getSize() const
    {
        return size;
    }
    const T& top() const
    {
        if (size == 0)
        {
            std::cerr << "Stack is empty!" << std::endl;
            assert(false);
        }
        return current->val;
    }
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
};

#endif
