#include <iostream>
#include "ffr.hpp"
using namespace std;

int main(int argc, char const *argv[]){
    FFR teste(ric, 1, 2);
    long* vet = new long[10];

    vet = teste.calculaSequencia(10);

    for(int i = 0; i < 10; ++i){
        cout << vet[i] << " ";
    }
    cout << endl;
    return 0;
}