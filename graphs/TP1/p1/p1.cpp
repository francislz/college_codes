#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "grafo.hpp"
using namespace std;

int main(int argc, char const *argv[]){
	if(argv[1] == NULL){
		cout << "Entrada do arquivo nula, favor forneca a entrada!" << endl;
	}
	else{
		ifstream arquivo(argv[1]);

		int numV, numA;
		arquivo >> numV >> numA;
		int caso = 1;
		ofstream tempo("Tempo_Execucao.txt");
		do{
			clock_t inicio, fim;
			Grafo grafo(numV, numA, -1, -1, -1);

			for (int i = 0; i < numA; ++i){
				int u, v, peso;
				arquivo	>> u >> v >> peso;
				grafo.insereAresta(u, v, peso);
			}
			int partida, destino, numPass;
			arquivo >> partida >> destino >> numPass;
			grafo.setPartida(partida);
			grafo.setDestino(destino);
			grafo.setNumPass(numPass);
			cout << "Caso #" << caso << endl;
			tempo << "Caso #" << caso << endl;
			inicio = clock();
			grafo.melhorCaminho();
			fim = clock();
			tempo << "O tempo gasto foi: " << (1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC)) << " ms" << endl;

			arquivo >> numV >> numA;
			caso++;
		}while((numV != 0) and (numA != 0));
	}
	return 0;
}