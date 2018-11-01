#include <iostream>
using namespace std;

typedef char Data;

#ifndef STACK_HPP
#define STACK_HPP

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
        void push(Data d);
        Data pop();
        void debug();
        bool xCy(Stack& x, Stack& y);
};
#endif

Node::Node(Data d = ' '){
    data = d;
    next = NULL;
}

Node::~Node(){}

Stack::Stack(){
    top = NULL;
    stackSize = 0;
}

Stack::~Stack(){}

void Stack::push(Data d){
    Node* temp = new Node(d);
    if(stackSize == 0){
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
    ++stackSize;
}

void Stack::debug(){
    Node* temp = top;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

Data Stack::pop(){
    if(stackSize > 0){
        Node* temp = top;
        Data value = temp->data;
        top = temp->next;
        --stackSize;
        delete temp;
        return value;
    }
    else{
        cout << "Dude WTF ?!" << endl;
    }
    return ' ';
}

bool Stack::xCy(Stack& x, Stack& y){
    bool form = true;
    while(top != NULL and form){
        while(form and (x.stackSize != 0)){
            if(pop() != x.pop()){
                form = false;
            }
        }
        while((stackSize <= 2) and (y.stackSize != 0) and form){
            if(pop() != y.pop()){
                form = false;
            }
        }
        if(stackSize != 0)
            pop();
    }
    return form;
}

int main(){
    Stack stack;
    stack.push('A');
    stack.push('B');
    stack.push('B');
    stack.push('A');
    
    Stack x;
    x.push('B');
    x.push('A');
    
    Stack y;
    y.push('A');
    y.push('B');
    
    bool value = stack.xCy(x, y);
    if(value) cout << "In the xCy form!" << endl;
    else cout << "Not in the xCy form!" << endl;
}

