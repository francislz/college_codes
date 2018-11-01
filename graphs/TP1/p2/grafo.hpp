#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

class Vertice{
	friend class Grafo;
	friend class Trabalho;
	private:
		int label;
		int coordX;
		int coordY;
		vector<int> posAdjacente;
	public:
		Vertice(){
			coordX = -99;
			coordY = -99;
			label = -1;
		}
		Vertice(int x, int y, int l){
			label = l;
			coordX = x;
			coordY = y;
		}
		Vertice(int x, int y){
			label = -1;
			coordX = x;
			coordY = y;
		}
		~Vertice(){
		}
		Vertice& operator =(Vertice& vertice);
};

class Grafo{
	friend class Vertice;
	friend class Trabalho;
	private:
		int tamLA;
		int capacidade;
        float distanciaTotal;
		Vertice** listaAdj;
		Vertice* partida;
		
		float DistEntrePontos(int vertDe, int vertAte);
        bool PartidaConexa();
		void CriarAlcancePartida();
		void CompletarAdjacencias();
        
		bool VerificaAdjacencia(int indAdj, int indice);
		//void BuscaProfundindade(int vertLabel, int descobertos[], int low[], stack<int> *antecessores, bool isAncest[]);
       	void imprimirTempo(){
			int horas = (int) distanciaTotal / 20000;
			float resto = distanciaTotal / 20000;
            resto -= (float) horas;
			float minutos = ceil(resto * 60.0);
            cout << horas << ":" << minutos << endl;   
        }
        void ImprimirCircEuleriano(int indice);
        bool PodeAtravessar(int pontoOrigem, int pontoDestino, int pos);
        int ContarAdjVertice(int indice, bool ancestral[]);
	public:
        Grafo(int cap);
		//~Grafo();
		//void ImprimirPontesGrafo();
};

class Trabalho{
	friend class Grafo;
	friend class Vertice;
	private:
		int numCasos;
		Grafo* casos;
		
		void ImprimirGrafo(Grafo* caso);
		//bool VerificaNoCaso(Grafo* caso);
		
		int BuscarPosVertice(int x, int y, Grafo* caso);
	public:
		Trabalho(char nome_ARQ[]);
		//~Trabalho();
		void Imprimir();
		void ImprimirPontes();
};

#endif
