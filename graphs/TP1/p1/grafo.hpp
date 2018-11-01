#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <iostream>
#include <fstream>
using namespace std;

typedef struct{
	int rotulo;
	int custo;
	int anc = -1;	
} Vertice;

class Aresta {
	friend class Grafo;
	friend class No;
	private:
		int peso = 0;
		char cor;
		int tempo;
	public:
		Aresta(int peso = 0, char cor = 'B', int tempo = -1){
			this->peso = peso;
			this->cor = cor;
			this->tempo = tempo;
		}
		~Aresta(){}
		Aresta& operator=(Aresta& aresta);
		int getPeso(){
			return peso;
		}
};

class Grafo{
	friend class Fila;
	private:
		int numV;
		int numA;
		int partida;
		int destino;
		int numPass;
		Aresta** matrizAdja;
	public:
		Grafo(int numV, int numA, int partida, int destino, int numPass);
		~Grafo();
		void melhorCaminho();
		void relaxaVertice(Vertice* u, Vertice* v, Vertice* ancU, Aresta* w);
		void insereAresta(int u, int v, int peso);
		void imprimir(){
			for (int i = 0; i < numV; ++i){
		        for (int j = 0; j < numV; ++j){
		            cout << matrizAdja[i][j].peso << " ";
		        }
		        cout << endl;
		    }
		}
		int getNumV(){return numV;}
		int getNumA(){return numA;}
		int getPartida(){return partida;}
		int getDestino(){return destino;}
		int getNumPass(){return numPass;}
		void setNumV(int numV){this->numV = numV;}
		void setNumA(int numA){this->numA = numA;}
		void setPartida(int partida){this->partida = partida;}
		void setDestino(int destino){this->destino = destino;}
		void setNumPass(int numPass){this->numPass = numPass;}
};

class No{
    friend class Fila;
    private:
        Vertice* vertice;
        No* prox;
    public:
        No(Vertice* vertice);
};

class Fila{
	friend class Grafo;
    private:
        No* prim;
        No* ulti;
        int tam;
    public:
        Fila();
        ~Fila();
        void insere(Vertice* dado);
        Vertice* remove(int rotulo);
        Vertice* retorna(int rotulo);
        void debug(bool imprimeAncestral = false);
        void mudarCusto(int rotulo, int custo);
        Vertice* extrairMax();
        void imprimeCaminho(Vertice *u, int partida, int destino);
};
#endif