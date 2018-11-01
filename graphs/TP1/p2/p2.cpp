#include <iostream>
#include <fstream>
#include "grafo.hpp"

using namespace std;

int main(int argc, char *argv[]){
    if(argv[1] == NULL){
        cout << "Voce esqueceu de digitar o nome do arquivo" << endl;
    }
    else{
	    Trabalho grafos(argv[1]);
	    //grafos.Imprimir();
        grafos.ImprimirPontes();
        //grafos.Imprimir()
    }
	return 0;
}
