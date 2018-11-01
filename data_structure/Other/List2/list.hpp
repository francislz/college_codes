#ifndef LIST_HPP
#define LIST_HPP
using namespace std;
typedef int Data;

class Node{
    friend class List;
    private:
        Data data;
        Node* next;
        Node* prev;
    public:
        Node(Data data = 0);
};

class List{
    private:
        Node* first;
        Node* last;
        int listSize;
    public:
        List();
        ~List();
        void print();
        void insert(Data data);
        void insertEnd(Data data);
};
#endif
