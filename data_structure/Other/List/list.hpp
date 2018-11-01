#ifndef LIST_HPP
#define LIST_HPP
using namespace std;
typedef int Data;

class Node{
    friend class List;
    private:
        Data data;
        Node* next;
    public:
        Node(Data data = 0);
};


class List{
    private:
        Node* first;
        Node* last;
        int listSize;
        void printR(int n, Node* temp);
    public:
        List();
        ~List();
        List(List& list);
        void insert(Data data);
        void insertEnd(Data data);
        void insertBegin(Data data);
        void insertPosition(int pos, Data data);
        void print();
        void printReverse();
        void remove(int position);
        Node* accessPosition(int pos);
        int search(Data data);
        void bubbleSort();
        List& operator=(List& l2);
};

#endif
