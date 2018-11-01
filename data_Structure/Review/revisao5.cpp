#include<iostream>
using namespace std;

void InsertElement(int vet[], int element, int pos){
    for(int i = 8; i >= pos; --i)
        vet[i + 1] = vet[i];
    vet[pos] = element;
}

int main(){
    int vet[10], k;
    cin >> k;
    for(int i = 0; i < 10; ++i)
        vet[i] = 0;
    for(int i = 0; i < k; ++i)
        cin >> vet[i];
        
    int num, pos;
    cin >> num >> pos;
    
    InsertElement(vet, num, pos);
    
    for(int i = 0; i < 10; ++i)
        cout << vet[i] << " ";
    cout << endl;
}
