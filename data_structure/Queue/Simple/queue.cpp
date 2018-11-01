#include <iostream>
using namespace std;

typedef int Data;

class Node{
    friend class Queue;
    private:
        Data data;
        Node* next;
    public:
        Node(Data d);
        ~Node();
};

class Queue{
    private:
        Node* first;
        Node* last;
        int queueSize;
    public:
        Queue();
        ~Queue();
        void push(Data data);
        Data pop();
        void debug();
        void stack(Queue& queue);
};

Node::Node(Data d = 0){
    data = d;
    next = NULL;
}

Node::~Node(){}

Queue::Queue(){
    first = NULL;
    last = NULL;
    queueSize = 0;
}

Queue::~Queue(){}

void Queue::push(Data data){
    Node* temp = new Node(data);
    if(queueSize == 0){
        first = temp;
        last = temp;
    }
    else{
        last->next = temp;
        last = temp;
    }
    ++queueSize;
}

void Queue::debug(){
    Node* temp = first;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Data Queue::pop(){
    if(queueSize != 0){
        Node* temp = first;
        Data data = temp->data;
        first = temp->next;
        delete temp;
        --queueSize;
        return data;
    }
    else{
        cout << "Dude WTF?!" << endl;
    }
    return -1;
}

void Queue::stack(Queue& queue){
    Data data = queue.pop();
    if(queue.queueSize == 0){
        push(data);
    }
    else{
        stack(queue);
        push(data);
    }
}

int main(){
    Queue queue;
    queue.push(4);
    queue.push(2);
    queue.push(5);
    queue.push(7);
    queue.debug();
    queue.pop();
    queue.debug();
    
    Queue stackQ;
    stackQ.stack(queue);
    stackQ.debug();
    return 0;
}



