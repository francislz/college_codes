#include <iostream>
#include "list.hpp"
using namespace std;

Node::Node(Data d = 0){
    data = d;
    next = NULL;
}

List::List(){
    first = NULL;
    last = NULL;
    listSize = 0;
}
