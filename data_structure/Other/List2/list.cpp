#include <iostream>
#include "list.hpp"
using namespace std;

Node::Node(Data d){
    data = d;
    next = NULL;
    prev = NULL;
}

List::List(){
    first = NULL;
    last = NULL;
    listSize = 0;
}

void List::insert(Data data){
    insertEnd(data);
}

void List::insertEnd(Data data){
    Node* temp = new Node(data);
    if(listSize == 0){
        first = temp;
        last = temp;
    }else{
        Node* aux = last;
        aux->next = temp;
        temp->prev = aux;
        last = temp;
    }
    ++listSize;
}

void List::print(){
    Node* temp = first;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

List::~List(){
    cout << "Destructor Called!" << endl;
}
