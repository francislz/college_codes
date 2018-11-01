#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int left = 20, right = 101;
    int cont = 3;

    string result = to_string(left) + ".";
    for (int i = 0; i < cont; ++i){
        result += '0';
    }

    result += to_string(right);
    cout << result << endl;
    return 0;
}
