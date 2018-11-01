#include <iostream>
#include "ffr.hpp"
using namespace std;

FFR::FFR(tipo T){
    meuTipo = T;
}

FFR::FFR(tipo T, int T1, int T2){
    meuTipo = T;
    termo1 = T1;
    termo2 = T2;
}

long* FFR::calculaSeqFib(int n, long* vet){
    for(int i = 0; i < n; ++i){
        if(i == 1){
            vet[i] = 1;
        }
        else if(i == 0){
            vet[i] = 0;
        }
        else{
            vet[i] = vet[i - 1] + vet[i - 2];
        }
    }
    return vet;
}

long* FFR::calculaSeqFet(int n, long* vet){
    for(int i = 0; i < n; ++i){
        if(i == 1)
            vet[i] = termo2;
        else if(i == 0)
            vet[i] = termo1;
        else if(i % 2 == 0)
            vet[i] = vet[i - 1] - vet[i - 2];
        else
            vet[i] = vet[i - 1] + vet[i - 2];
     }
     return vet;
}

long* FFR::calculaSeqRic(int n, long* vet){
    for(int i = 0; i < n; ++i){
        if(i == 1)
            vet[i] = termo2;
        else if(i == 0)
            vet[i] = termo1;
        else
            vet[i] = vet[i - 1] + vet[i - 2];
     }
     return vet;
}

long* FFR::calculaSequencia(int n){
    long* vet = new long[n];
    if(meuTipo == 0)
        return calculaSeqFib(n, vet);
    else if(meuTipo == 1)
        return calculaSeqFet(n, vet);
    else
        return calculaSeqRic(n, vet);
}

long FFR::calculaFib(int n){
    if(n == 1)
        return 1;
    else if(n == 0)
        return 0;
    else
        return calculaFib(n - 1) + calculaFib(n - 2);
}

long FFR::calculaFet(int n){
    if(n == 1)
        return termo2;
    else if(n == 0)
        return termo1;
    else if(n % 2 == 0)
        return calculaFet(n - 1) - calculaFet(n - 2);
    else
        return calculaFet(n - 1) + calculaFet(n - 2);
}

long FFR::calculaRic(int n){
    if(n == 1)
        return termo2;
    else if(n == 0)
        return termo1;
    else if(n % 2 == 0)
        return calculaRic(n - 1) + calculaRic(n - 2);
}

long FFR::calculaTermo(int n){
    if(meuTipo == 0)
        return calculaFib(n);
    else if(meuTipo == 1)
        return calculaFet(n);
    else
        return calculaRic(n);
}


