#ifndef STACK_H
#define STACK_H

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
    Stack();
    virtual ~Stack();
    bool push(T val);
    T pop();
    int getSize() const;
    const T& top() const;
};

#endif
