#include <iostream>
#include "stack.hpp"

int main(){
    Stack stack;
    stack.push(1);
    stack.push(5);
    stack.push(2);
    stack.push(7);
    stack.push(4);
    stack.push(3);
    stack.push(9);
    stack.push(6);
    //stack.pop();
    stack.debug();
    stack.orderStack();
    stack.debug();
    return 0;
}
