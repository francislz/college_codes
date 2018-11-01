#ifndef LIST_HPP
#define LIST_HPP

class Node{
    friend class List;
    private:
        int data;
        Node* next;
    public:
        Node(int data);
};

class List{
    private:
        int size;
        Node* first;
        Node* last;
    public:
        List();
        ~List();
        void insert(int data);
        void debug();
};

#endif