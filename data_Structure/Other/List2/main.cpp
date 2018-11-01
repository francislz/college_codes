#include <iostream>
#include "list.hpp"
using namespace std;

int main(){
    List list;
    list.insert(3);
    list.insert(1);
    list.insert(4);
    list.print();
    return 0;
}
