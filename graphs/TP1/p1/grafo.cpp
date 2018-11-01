#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "grafo.hpp"
using namespace std;



Aresta& Aresta::operator =(Aresta& aresta){
	tempo = aresta.tempo;
	cor = aresta.cor;
	peso = aresta.peso;
    return *this;
}

void Grafo::relaxaVertice(Vertice* u, Vertice* v, Vertice *ancU, Aresta* w){
	if(u->rotulo == partida){
        if(u->custo < w->peso)
            u->custo = w->peso;
		v->custo = w->peso;
		v->anc = u->rotulo;
	}
	else if(u->rotulo != destino){
		if(w->peso < u->custo){
			u->custo = w->peso;
			v->custo = w->peso;
			v->anc = u->rotulo;
		}
		else if((w->peso > u->custo) and (w->peso < ancU->custo)){
			u->custo = w->peso;
            v->custo = w->peso;
			v->anc = u->rotulo;
		}
        else{
            v->custo = u->custo;
            v->anc = u->rotulo;
        }
	}
	

}

void Fila::imprimeCaminho(Vertice *u, int partida, int destino){
	if(u->rotulo != partida){
		imprimeCaminho(retorna(u->anc), partida, destino);
	}
	if(u->rotulo == destino){
		cout << u->rotulo << endl;
	}
	else{
        if(u->rotulo == partida)
            cout << "Rota: " << u->rotulo << " - ";
        else
		    cout << u->rotulo << " - ";
	}
}

void Grafo::melhorCaminho(){
	Fila Q;
	Fila S;
	for (int i = 0; i < numV; ++i){
		Vertice *v = new Vertice;
		v->custo = -1;
		v->rotulo = i + 1;
		Q.insere(v);
	}
	Q.mudarCusto(partida, 0);
	while(Q.tam != 0){
		Vertice *u = Q.extrairMax();
		for (int i = 0; i < numV; ++i){
			if((matrizAdja[u->rotulo - 1][i].peso != 0) and (u->rotulo != (i + 1))){
				Vertice* v = Q.retorna(i + 1);	
				if(v != NULL){
					int uCusto = u->custo;
                    Vertice *ancU = S.retorna(u->anc);
					relaxaVertice(u, v, ancU, &matrizAdja[u->rotulo - 1][i]);
					if(u->custo != uCusto){
						Q.remove(u->rotulo);
						Q.insere(u);
					}
					Q.remove(v->rotulo);
					Q.insere(v);

				}
			}
		}
		Vertice* temp = Q.remove(u->rotulo);
		S.insere(temp);
	}
    //O codigo abaixo e destinado para impressao do caminho encontrado
	Vertice *u = S.retorna(destino); //Vertice de destino usando para imprimir o caminho
	int capacidade = u->custo; //Custo do caminho (Quantidade de passageiros)
	S.imprimeCaminho(u, partida, destino);
	int viagens = (numPass/ (capacidade - 1));
	if((numPass % (capacidade - 1)) == 0)
		cout << "Minimo de viagens = " << viagens << endl;
	else{
		cout << "Minimo de viagens = " << (viagens + 1) << endl;
	}

}

Grafo::Grafo(int numV = -1, int numA = -1, int partida = -1, int destino = -1, int numPass = -1){
    this->numV = numV;
    this->numA = numA;
    this->partida = partida;
    this->destino = destino;
    this->numPass = numPass;
    matrizAdja = new Aresta*[numV];
    for (int i = 0; i < numV; ++i){
        matrizAdja[i] = new Aresta[numV]();
    }
}

void Grafo::insereAresta(int u, int v, int peso){
    Aresta* nova = new Aresta();
    nova->peso = peso;
    matrizAdja[u - 1][v - 1] = *nova;
    matrizAdja[v - 1][u - 1] = *nova;
}

Grafo::~Grafo(){
    for (int i = 0; i < numV; ++i){
        delete[] matrizAdja[i];
    }
    delete[] matrizAdja;
}

No::No(Vertice* v){
    vertice = v;
    prox = NULL;
}

Fila::Fila(){
    prim = NULL;
    ulti = NULL;
    tam = 0;
}

Fila::~Fila(){
    No* temp = prim;
    No* aux;
    while(temp != NULL){
        aux = temp;
        temp = temp->prox;
        delete aux;
    }
    prim = NULL;
    ulti = NULL;
}

void Fila::insere(Vertice* v){
    No* novo = new No(v);
    if(tam == 0){
        prim = novo;
        ulti = novo;
    }
    else{
    	No* temp = prim;
    	No* ant;
    	while((temp->vertice->custo < novo->vertice->custo) and (temp != ulti)){
			ant = temp;
			temp = temp->prox;
    	}
    	if((temp == prim) and (temp == ulti)){
    		if(temp->vertice->custo > novo->vertice->custo){
    			novo->prox = temp;
    			prim = novo;
    			ulti = temp;
    		}
    		else{
    			temp->prox = novo;
    			ulti = novo;
    		}
    	}
    	else if(temp == prim){
    		if(temp->vertice->custo > novo->vertice->custo){
    			novo->prox = temp;
    			prim = novo;
    		}
    		else{
    			novo->prox = temp->prox;
    			temp->prox = novo;
    		}
    	}
    	else if(temp == ulti){
    		if(temp->vertice->custo > novo->vertice->custo){
    			ant->prox = novo;
    			novo->prox = temp;
    		}
    		else{
    			temp->prox = novo;
    			ulti = novo;
    		}
    	}
    	else{
    		if(temp->vertice->custo > novo->vertice->custo){
	    		ant->prox = novo;
	    		novo->prox = temp;
    		}
    		else{
    			novo->prox = temp->prox;
    			temp->prox = novo;
    		}
    	}
    }
    ++tam;
}

void Fila::debug(bool imprimeAncestral){
    No* temp = prim;
    int i = 0;
    while(i < tam){
        cout << "[" << temp->vertice->rotulo << " : " << temp->vertice->custo;
        if(imprimeAncestral)
        	cout << " : " << temp->vertice->anc;
        cout << "] -> ";
        temp = temp->prox;
        ++i;
    }
    cout << "NULL" << endl;
}

Vertice* Fila::retorna(int rotulo){
    if(tam != 0){
        No* temp = prim;
        while((temp->vertice->rotulo != rotulo) and (temp != ulti)){
        	temp = temp->prox;
        }
        if(temp->vertice->rotulo == rotulo){
        	return temp->vertice;
        }       
    }
    return NULL;
}

Vertice* Fila::remove(int rotulo){
    if(tam != 0){
        No* temp = prim;
        No* ant;
        int i = 0;
        while((temp->vertice->rotulo != rotulo) and (i < tam)){
        	ant = temp;
        	temp = temp->prox;
        	++i;
        }

        if(temp->vertice->rotulo == rotulo){
        	if(temp == prim){
    			prim = temp->prox;
    		}
    		else if(temp == ulti){
                ant->prox = NULL;
    			ulti = ant;
    		}
    		else{
    			ant->prox = temp->prox;
    		}
        	Vertice* vertice = temp->vertice;
        	temp->vertice = NULL;
        	delete temp;
        	--tam;
        	return vertice;
        }       
    }
    return NULL;
}

void Fila::mudarCusto(int rotulo, int custo){
	Vertice *v = remove(rotulo);
	if(v != NULL){
		v->custo = custo;
		insere(v);
	}
}

Vertice* Fila::extrairMax(){
	No* temp = prim;
	Vertice* min = prim->vertice;
	while(temp != NULL){
		if(temp->vertice->custo > min->custo){
			min = temp->vertice;
		}
		temp = temp->prox;
	}
	return min;
}