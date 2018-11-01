#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <time.h>
#include "grafo.hpp"
using namespace std;


int main(int argc, char const *argv[]){
    //Entrada de 1 ou mais arquivos
    for (int i = 1; i < argc; ++i){
        if(argv[i] != NULL){
            Grafo grafo(argv[i]);
            cout << grafo.resolveInstancia() << " ";
            cout << grafo.getViagens() << " ";
            cout << grafo.getTempo() << endl;
        }
        //Sinaliza se a entrada for nula
        else{
            cerr << "Entrada do arquivo vazia!!" << endl; 
        }
    }

}