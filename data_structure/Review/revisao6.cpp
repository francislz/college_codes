#include<iostream>
using namespace std;

int main(){
    int vet[8], pos[8], neg[8], qtdNeg = 0, qtdPos = 0;
    for(int i = 0; i < 8; ++i){
        vet[i] = 0;
        pos[i] = 0;
        neg[i] = 0;
    }
    for(int i = 0; i < 8; ++i)
        cin >> vet[i];
    
    for(int i = 0; i < 8; ++i){
        if(vet[i] >= 0){
            pos[qtdPos] = vet[i];
            ++qtdPos;
        }
        else{
            neg[qtdNeg] = vet[i];
            ++qtdNeg;
        }
    }
    
    for(int i = 0; i < qtdPos; ++i)
        cout << pos[i] << " ";
    cout << endl;
    for(int i = 0; i < qtdNeg; ++i)
        cout << neg[i] << " ";
    cout << endl;
}
