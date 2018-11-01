#include <iostream>
#include "list.hpp"

using namespace std;

Node::Node(int data = 0){
    this->data = data;
    this->next = NULL;
}

List::List(){
    this->size = 0;
    this->first = NULL;
    this->last = NULL;
}

List::~List(){
    if(this->size != 0){
        Node* temp = this->first;
        while(temp != NULL){
            Node* aux = temp;
            temp = temp->next;
            delete aux;
        }
    }
}

void List::insert(int data){
    Node* node = new Node(data);
    if(this->size == 0){
        this->first = node;
        this->last = node;
    }
    else{
        this->last->next = node;
        this->last = node;
    }
    this->size++;
}

void List::debug(){
    Node* temp = this->first;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}