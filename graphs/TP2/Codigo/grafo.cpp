#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "grafo.hpp"
using namespace std;
//Construtor da classe vertice, atribui os valores padroes do vertice
Vertice::Vertice(int indice, float x, float y, float tempo_ponto, bool visitado){
    this->indice = indice;
    this->x = x;
    this->y = y;
    this->tempo_ponto = tempo_ponto;
    this->visitado = visitado;
}

//Destrutor do vertice, nao possui implementacao pois nao desaloca memoria
Vertice::~Vertice(){}

//Construtor da classe grafo
Grafo::Grafo(const char arq[]){
    nomeArq = new char[100]; // Atribuicao do nome do arquivo
    // Atribuicao dos valores iniciais
    this->viagens = 1;
    this->nomeArq = arq;
    this->tempo_gasto = 0.0;
    ifstream arquivo(arq);

    if(arquivo){ //Verifica se o arquivo foi aberto corretamente, se for executa o escopo do if
        //Le a quantidade hostels, pontos turisticos e o tempo limite diario;
        arquivo >> numHostels >> numPtsTuristicos >> tempo;
        hostels = new Vertice[numHostels]();//Vetor dinamico de hostels
        for (int i = 0; i < numHostels; ++i){
            int indice;
            float x,y;
            arquivo >> indice >> x >> y; //Leitura dos pontos
            Vertice *v = new Vertice(indice, x, y); //instancia de um vertices
            hostels[i] = *v; //Atribuicao
        }

        ptsTuristicos = new Vertice[numPtsTuristicos]();
        for (int i = 0; i < numPtsTuristicos; ++i){
            int indice;
            float x,y,tempo;
            arquivo >> indice >> x >> y >> tempo; //Leitura dos pontos
            Vertice *u = new Vertice(indice, x, y, tempo); //instancia de um vertices
            ptsTuristicos[i] = *u;//Atribuicao
        }
    }
    else{//Escopo do else para caso o arquivo seja invalido
        numHostels = -1; //valor invalido para os hostels
        numPtsTuristicos = -1;
        cerr << "Arquivo invalido tente novamente" << endl; //Mensagem de erro
    }
    
}

Grafo::~Grafo(){
    //Desaloca memoria
    if(numHostels != -1){
        delete[] hostels;
        delete[] ptsTuristicos;
    }
}

//Funcao que calcula a distancia entre dois pontos
float Grafo::distanciaEntrePontos(float x0, float y0, float x1, float y1){
    return (float) sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
}

//Funcao que verifica se todos os pontos turisticos foram visitados
bool Grafo::pontosVisitados(){
    for (int i = 0; i < numPtsTuristicos; ++i){
        if(not ptsTuristicos[i].isVisitado()){
            return false;
        }
    }
    return true;
}

//Resolve o problema dado
bool Grafo::resolveInstancia(){
    if(numHostels != -1){ //Se o arquivo (verificaçao feita pelo numero de hostels) for valido executa o escopo do if
        int partida = numHostels / 2; //Calcula o vertice de partida
        Vertice *atual = &hostels[partida];//Aponta o vertice atual para a partida
        //Variaveis auxiliares para calcular o tempo e distancia
        float tempo_atual = 0.0;
        float distancia = 0.0;
        while(not pontosVisitados()){ //Enquanto nao houverem vertices visitados o caminho e buscado
            atual->visitar(); //Marca o vertice atual como visitado
            tempo_atual += atual->tempo_ponto; //Soma o tempo atual com o tempo do ponto
            this->tempo_gasto += atual->tempo_ponto; //Calcula o tempo total gasto para o problema
            
            if(tempo_atual > tempo){ //Se o tempo atual for maior que o limite ele deve ir para um hostel
                int melhorH = 0; //Variavel auxiliar para o melhor hostel
                distancia = 0.0; //Reseta a variavel distancia
                for (int i = 1; i < numHostels; ++i){ //Busca o melhor hostel
                    float novaDistancia = distanciaEntrePontos(atual->x, atual->y, ptsTuristicos[i].x, ptsTuristicos[i].y);
                    float distanciaAtual = distanciaEntrePontos(atual->x, atual->y, ptsTuristicos[melhorH].x, ptsTuristicos[melhorH].y);
                    //Se a nova distancia calculada for melhor que a do ponto salvo em melhorH
                    //melhorH vai receber o indice do novo melhor hostel
                    //e a distancia e atualizada para a nova
                    if(novaDistancia < distanciaAtual){
                        melhorH = i;
                        distancia = novaDistancia;
                    }
                }
                //Faz a troca dos vertices do ponto para o novo ponto (hostel)
                int indiceAncestral = atual->indice; //Aux para salvar o indice atual
                atual = &hostels[melhorH]; //Atual recebe o novo vertice
                atual->setAncestral(indiceAncestral);//Add o ancestral no vector
                tempo_atual = 0.0; //Reseta o tempo gasto
                tempo_atual += distancia; //tempo += gasta para percorrer do ponto ate o outro
                viagens++;//Incrementa o numero de viagens
                if(viagens >= 100){ //Verifica se o programa esta em loop e tenta encontrar um solucao
                    return false;   //para uma instancia que nao tem solucao
                }
            }
            //Se o tempo nao foi estorado procura um novo ponto turistico
            else{
                int melhorP = 0; //Aux para o melhor ponto
                bool naoAchou = true; //Criterio de parada do loop
                for (int i = 0; i < numPtsTuristicos and naoAchou; ++i){ //Busca o primeiro ponto nao visitado
                    if(not ptsTuristicos[i].visitado){ //Se achar o ponto o indice e salvo e a execucao para
                        naoAchou = false;
                        melhorP = i;
                    }
                }
                //Caso melhorP nao seja atualizado no loop a seguir por padrao a distancia recebe a distancia
                //de melhorP ao ponto atual (se esse for diferente do ponto atual)
                if((atual->x != ptsTuristicos[melhorP].x) and (atual->y != ptsTuristicos[melhorP].x)){
                    distancia = distanciaEntrePontos(atual->x, atual->y, ptsTuristicos[melhorP].x, ptsTuristicos[melhorP].y);
                }
                //Loop abaixo procura pelo melhor ponto
                for (int i = 1; i < numPtsTuristicos; ++i){
                    float novaDistancia = distanciaEntrePontos(atual->x, atual->y, ptsTuristicos[i].x, ptsTuristicos[i].y);
                    float distanciaAtual = distanciaEntrePontos(atual->x, atual->y, ptsTuristicos[melhorP].x, ptsTuristicos[melhorP].y);
                    if((novaDistancia < distanciaAtual) and (not ptsTuristicos[i].visitado)){
                        melhorP = i;
                        distancia = novaDistancia;
                    }
                    //Analogo ao caso dos hostels esse loop verifica o melhor ponto
                }
                //Se o tempo desse ponto somado com o atual nao for maior que o limite
                //A atualizacao do ponto atual deve ser feita
                if((tempo_atual + atual->tempo_ponto + distancia) < tempo){
                    tempo_atual += distancia;
                    int indiceAncestral = atual->indice;
                    atual = &ptsTuristicos[melhorP];
                    atual->setAncestral(indiceAncestral);
                }
                //Caso contrario e sinalizado que a ida para o hostel deve ser realizada
                //E as mudancas nao sao realizadas
                //Por isso a variavel tempo_atual recebe a soma dos valores para que a execucao va para o
                // if dos hostel
                else{
                    tempo_atual += (atual->tempo_ponto + distancia);
                    this->tempo_gasto -= (distancia + atual->tempo_ponto);
                }
            }
            //incremento do tempo total gasto
            this->tempo_gasto += distancia;
        }
        //Se no fim da execucao o ponto atual for diferente do inicial ele e atualizado e a soma e feita
        if((atual->x != ptsTuristicos[partida].x) and (atual->y != ptsTuristicos[partida].x)){
            distancia = distanciaEntrePontos(atual->x, atual->y, ptsTuristicos[partida].x, ptsTuristicos[partida].y);
            this->tempo_gasto += distancia;
        }
        return true;
    }
    return false;
}