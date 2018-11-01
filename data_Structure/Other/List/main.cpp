#include <iostream>
#include "list.hpp"
using namespace std;

int main(){
    List list;
    list.insert(3);
    list.insert(1);
    list.insert(4);
    list.insert(7);
    list.insert(5);
    list.insert(2);
    list.print();
    list.bubbleSort();
    list.print();
    list.insert(6);
    list.insert(10);
    list.print();
    list.printReverse();
    
    /*List list2(list);
    list2.insert(10);
    list2.print();
    list.print();*/
    return 0;
}
