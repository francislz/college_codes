#include <iostream>
#include "decimal.hpp"
using namespace std;

int main(int argc, char const *argv[]){
    decimal dec1(20, 5, 1);
    decimal dec2(21, 5, 1);

    decimal result = dec1 + dec2;
    cout << result << endl;
    return 0;
}