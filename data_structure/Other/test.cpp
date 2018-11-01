#include <iostream>
using namespace std;

void imprimeReverso(int n){
    int i;
    cin >> i;
    if(n == 1)
        cout << n << " ";
    else{
        cout << n << " ";
        imprimeReverso(n - 1);
    }
}

int main(){
    imprimeReverso(10);
}
