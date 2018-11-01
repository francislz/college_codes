#include <iostream>
#include <cstdlib> 
using namespace std;

typedef int Data;

class Heap{
    private:
        Data* heap;
        int capacity;
        int size;
        inline int parent(int i);
        inline int left(int i); // where i is the parent position
        inline int right(int i);
        void fix();
        void heapifyUp(int i);
        void heapifyDown(int i);
    public:
        Heap(int cap);
        Heap(Data array[], int s, int cap = 0);
        ~Heap();
        void insert(Data d);
        Data removeRoot();
        void printHeap();
};

Heap::Heap(int cap){
    capacity = cap;
    heap = new Data[capacity];
    size = 0;
}

Heap::~Heap(){
    delete[] heap;
}

void Heap::fix(){
    for(int i = (size/2 - 1); i >= 0; --i){
        heapifyDown(i);
    }
}

Heap::Heap(Data array[], int s, int cap){
    size = s;
    if(cap == 0)
        capacity = s;
    else
        capacity = cap;
    heap = new Data[capacity];
    for(int i = 0; i < size; ++i){
        heap[i] = array[i];
    }
    fix();
}

int Heap::left(int i){return 2 * i + 1;}
int Heap::right(int i){return 2 * i + 2;}
int Heap::parent(int i){return (i - 1)/2;}

void Heap::heapifyDown(int i){
    int l = left(i);
    int r = right(i);
    int major = i;
    
    if((l < size) and (heap[l] > heap[major])){
        major = l;
    }
    if((r < size) and (heap[r] > heap[major])){
        major = r;
    }
    
    if(major != i){
        Data temp = heap[major];
        heap[major] = heap[i];
        heap[i] = temp;
        heapifyDown(major);
    }
}

void Heap::heapifyUp(int i){
    int p = parent(i);
    if(heap[i] > heap[p]){
        Data temp = heap[i];
        heap[i] = heap[p];
        heap[p] = temp;
        heapifyUp(p);
    }
}

void Heap::insert(Data d){
    if(size == capacity){
        cerr << "Error inserting value" << endl;
        exit(EXIT_FAILURE);
    }
    heap[size] = d;
    heapifyUp(size);
    ++size;
}

Data Heap::removeRoot(){
    if(size == 0){
        cerr << "Dude WTF?!" << endl;
        exit(EXIT_FAILURE);
    }
    Data temp = heap[0];
    heap[0] = heap[size - 1];
    --size;
    heapifyDown(0);
    return temp;
}

void Heap::printHeap(){
    for(int i = 0; i < size; ++i){
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main(){
    int vet[] = {7, 2, 4, 6, 50, 1, 10};
    Heap* heap = new Heap(vet, 7, 100);
    heap->printHeap();
    
    delete heap;    
    Heap* heap2 = new Heap(100);
    for(int i = 0; i < 7; ++i){
        heap2->insert(vet[i]);
    }
    
    heap2->printHeap();
    heap2->removeRoot();
    heap2->printHeap();
    return 0;
}




