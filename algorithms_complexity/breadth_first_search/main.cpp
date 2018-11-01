#include "list.hpp"
#include <iostream>
using namespace std;

int main(){
    List* list = new List();
    list->insert(10);
    list->insert(2);
    list->insert(3);
    list->debug();
}