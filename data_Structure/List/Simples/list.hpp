#ifndef LIST_HPP
#define LIST_HPP

typedef int Data;

class Node{
    friend class List;
    private:
        Data data;
        Node* next;
    public:
        Node(Data data);
};

class List{
    private:
        Node* first;
        Node* last;
        int listSize;
    public:
        List();
        ~List();
        void insert(Data data);
        void insertEnd(Data data);
        void insertBegin(Data data);
        
};


#endif
