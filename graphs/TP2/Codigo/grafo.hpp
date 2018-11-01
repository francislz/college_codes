#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Vertice{
    friend class Grafo;
    private:
        int indice;
        float x;
        float y;
        float tempo_ponto;
        vector<int> ancestral;
        bool visitado;
    public:
        Vertice(int indice = -1, float x = 0.0, float y = 0.0, float tempo_ponto = 0.0, bool visitado = false);
        ~Vertice();
        void setAncestral(int ancestral){this->ancestral.push_back(ancestral);}
        void visitar(){this->visitado = true;} //Marca o vertice como visitado
        bool isVisitado(){return this->visitado;} //Retorna se o vertice esta ou nao visitado
};

class Grafo{
    private:
        const char* nomeArq;
        int numHostels;
        int numPtsTuristicos;
        float tempo;
        float tempo_gasto;
        int viagens;
        Vertice* hostels;
        Vertice* ptsTuristicos;
    public:
        Grafo(const char nomeArq[]);
        ~Grafo();
        float distanciaEntrePontos(float x0, float y0, float x1, float y1);
        bool resolveInstancia();
        bool pontosVisitados();
        //Retorno dos valores da saida padrao
        int getNumPtsTuristicos(){return this->numPtsTuristicos;}
        int getViagens(){return this->viagens;}
        float getTempo(){return this->tempo_gasto;}
};
#endif