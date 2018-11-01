#ifndef STACK_HPP
#define STACK_HPP

typedef int Data;

class Node{
    friend class Stack;
    private:
        Data data;
        Node* next;
    public:
        Node(Data d);
        ~Node();
        
};

class Stack{
    private:
        Node* top;
        int stackSize;
    public:
        Stack();
        ~Stack();
        void push(Data data);
        Data pop();
        void debug();
        void orderStack();
};

#endif
