#include <iostream>
#include "stack.hpp"
using namespace std;

Node::Node(Data d = 0){
    data = d;
    next = NULL;
}

Node::~Node(){
    //cout << "Node destructor!!" << endl;
}

Stack::Stack(){
    stackSize = 0;
    top = NULL;
}

Stack::~Stack(){
    while(top != NULL){
        pop();
    }
}

void Stack::push(Data data){
    Node* temp = new Node(data);
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
    for(int i = 0; i < stackSize; ++i){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Data Stack::pop(){
    if(stackSize != 0){
        Node* temp = top;
        Data value = top->data;
        top = top->next;
        --stackSize;
        delete temp;
        return value;
    }
    else{
        cout << "WTF ?!" << endl;
    }
    return -1;
}

void Stack::orderStack(){
    Data values[stackSize];
    int tam = stackSize;
    for(int i = 0; top != NULL; ++i){
        values[i] = pop();
    }
    for(int i = tam; i >= 0; --i){
        for(int j = 0; j < i; ++j){
            if(values[j] > values[j + 1]){
                Data aux = values[j];
                values[j] = values[j + 1];
                values[j + 1] = aux;
            }
        }
    }
    for(int i = 0; i < tam; ++i){
        push(values[i]);
    }
}














