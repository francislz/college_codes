#include <iostream>
#include "list.hpp"
using namespace std;

Node::Node(Data D){
    data = D;
    next = NULL;
}

List::List(){
    first = NULL;
    last = NULL;
    listSize = 0;
}

List::~List(){
    Node* temp = first;
    Node* aux;
    while(temp != NULL){
        aux = temp;
        temp = temp->next;
        delete aux;
    }
    first = NULL;
    last = NULL;
    cout << "Destructor called" << endl;
}

List::List(List& list){
    first = list.first;
    last = list.last;
    listSize = list.listSize;
}

List& List::operator =(List& l2){
    if(listSize != 0){
        Node* temp = first;
        Node* aux;
        while(temp != NULL){
            aux = temp;
            temp = temp->next;
            delete aux;
        }
        first = NULL;
        last = NULL;
    }else{
        first = l2.first;
        last = l2.last;
        listSize = l2.listSize;
    }
    return *this;
}

void List::bubbleSort(){
    for(int i = listSize; i >= 0; --i){
        Node* temp = first;
        int j = 0;
        while(temp->next != NULL){
            Node* next = temp->next;
            if(temp->data > next->data){
                if(temp == first){
                    temp->next = next->next;
                    next->next = temp;
                    first = next;
                }
                else{
                    Node* aNode = first;
                    int cont = 0;
                    while(cont < (j - 1)){
                        aNode = aNode->next;
                        ++cont;
                    }
                    if(next->next == NULL){
                        temp->next = NULL;
                        next->next = temp;
                        aNode->next = next;
                        last = temp;
                    }else{
                        temp->next = next->next;
                        next->next = temp;
                        aNode->next = next;
                    }
                }
            }
            else{
                temp = temp->next;
            }
            ++j;
        }

    }
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
        last->next = temp;
        last = temp;
    }
    listSize++;
}

void List::insertBegin(Data data){
    Node* temp = new Node(data);
    if(listSize == 0){
        first = temp;
        last = temp;
    }else{
        temp->next = first;
        first = temp;
    }
    listSize++;
}

void List::insertPosition(int pos, Data data){
    Node* temp = new Node(data);
    if((pos <= listSize) and (pos >= 0)){
        if(listSize == 0){
            first = temp;
            last = temp;
        }else if(pos == listSize){
            last->next = temp;
            last = temp;
        }else{
            Node* aux = first;
            int posAux = 0;
            while(posAux < (pos - 1)){
                aux = aux->next;
                ++posAux;
            }
            temp->next = aux->next;
            aux->next = temp;
        }
        listSize++;
    }else{
        cerr << "Deu merda" << endl;
    }
}

void List::remove(int position){
    if((position < listSize) and (position >= 0)){
        if(position == 0){
           Node* aux = first;
           first = first->next;
           delete aux;
        }else{
            Node* aux = first->next;
            Node* prev = first;
            int countPos = 1;
            while((aux != NULL) and (countPos < position)){
                prev = aux;
                aux = aux->next;
                ++countPos;
            }
            if(aux == last){
                prev->next = NULL;
                last = prev;
                delete aux;
            }
            else{
                prev->next = aux->next;
                delete aux;
            }
        }
        --listSize;
    }else{
        cerr << "Deu merda" << endl;
    }
}

int List::search(Data data){
    Node* aux = first;
    int pos = 0;
    while((aux != NULL) and (aux->data != data)){
        aux = aux->next;
        ++pos;
    }
    if(aux == NULL)
        pos = -1;
    return pos;
}

void List::printReverse(){
    printR(listSize, first);
    cout << endl;
}

void List::printR(int n, Node* temp){
    if(n == 1)
        cout << temp->data << " ";
    else{
        printR(n - 1, temp->next);
        cout << temp->data << " ";
    }
}
void List::print(){
    Node* aux = first;
    //cout << "LAST: " << last << endl;
    while(aux != NULL){
        cout << aux->data << " "; //<< " ADDRESS: " << aux << " NEXT: " << aux->next << endl;
        aux = aux->next;
    }
    cout << endl;
}
