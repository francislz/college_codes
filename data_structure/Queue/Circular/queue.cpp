#include <iostream>
using namespace std;

typedef int Data;

class Queue{
    private:
        int capacity;
        Data* data;
        int size;
        int begin;
        int end;
    public:
        Queue(int cap = 100);
        ~Queue();
        void enqueue(Data d);
        Data dequeue();
        void debug();
};

Queue::Queue(int cap){
    capacity = cap;
    data = new Data[capacity];
    begin = -1;
    end = -1;
    size = 0;
}

Queue::~Queue(){
    delete[] data;
}

void Queue::enqueue(Data d){
    if((end + capacity - begin) % capacity == (capacity - 1)){
        cout << "Err you dumb asshole!" << endl;
    }
    else{
        if(begin == -1){
            ++begin;
        }
        end = (end + 1) % capacity;
        data[end] = d;
        ++size;
    }
}

Data Queue::dequeue(){
    if(size != 0){
        Data value = data[begin];
        if(begin == end){
            begin = -1;
            end = -1;
        }
        else{
            begin = (begin + 1) % capacity;
        }
        --size;
        return value;
    }
    else{
        cout << "Dude, WTF?!" << endl;
    }
    return -1;
}

void Queue::debug(){
    int i = begin;
    while(i <= end){
        cout << data[i] << " ";
        ++i;
    }
    cout << endl;
}

int main(){
    Queue queue;
    queue.enqueue(2);
    queue.enqueue(1);
    queue.enqueue(4);
    queue.enqueue(3);
    queue.debug();
    return 0;
}





