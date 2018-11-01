#include<iostream>
using namespace std;

int main(){
    int vet[5], vet1[5], resultado[10];
    for(int i = 0; i < 5; ++i)
        cin >> vet[i];
    
    for(int i = 0; i < 5; ++i)
        cin >> vet1[i];
    
    int i = 0, j = 0, k = 0;
    for(;j < 5 or k < 5;){
        if(vet[j] < vet1[k]){
            resultado[i] = vet[j];
            ++j;
            ++i;
        }
        else{
            resultado[i] = vet1[k];
            ++k;
            ++i;
        }
       // cout << i << " " << endl;
    }
    
    for(int i = 0; i < 10; ++i)
        cout << resultado[i] << " ";
    cout << endl;
}
