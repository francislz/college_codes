#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <list>
//#include <stack>
#include <cstring>
#include "grafo.hpp"

using namespace std;


/*======================================================================
...................FUNCOES DA CLASSE VERTICE............................
======================================================================*/

Vertice& Vertice::operator =(Vertice& vertice){
    coordX = vertice.coordX;
    coordY = vertice.coordY;
    posAdjacente = vertice.posAdjacente;
    return *this;
}

/*======================================================================
...................FUNCOES DA CLASSE TRABALHO...........................
======================================================================*/

Trabalho::Trabalho(char nomeArq[]){
    ifstream arquivo(nomeArq);
    arquivo >> numCasos;

    casos = new Grafo(numCasos);

    char teste = 'x';
    arquivo >> teste;

    if((teste == 'b') or (arquivo.eof())){
        //agora percorre o arquivo numCasos vezes criando seus vertices
        for (int i = 0; i < numCasos; ++i){
            
            int x0, y0, x1, y1;
            arquivo >> x0 >> y0;
            
            //lê o vertice de partida
            Vertice* novaPartida = new Vertice(x0, y0, casos[i].tamLA);
            casos[i].partida = novaPartida;
            
            //adiciona o vertice de partida na lista de adjacencia
            casos[i].listaAdj[0] = novaPartida;
            ++casos[i].tamLA;
            
            //enquanto nao se lê um '\n'(linha em branco) ou final do arquivo adiciona os vertices
            while((teste == 'b') or (!arquivo.eof())){
                //reinicializa a varivel de teste
                teste = 'x';
                
                arquivo >> x0 >> y0 >> x1 >> y1; //Le os pontos no arquivo
                //cout << "(" << x0 << "." << y0 << ")->" << "(" << x1 << "." << y1 << ")"<< endl;
                
                //se os pontos lidos nao tem os valores padrao, inicia a insercao deles na lista de adjacencia
                if((x0 != -99) and (y0 != -99) and (x1 != -99) and (y1 != -99)){
                    
                    //verifica se primeiro vertice lido (x0, y0) esta na lista, se sim é retornado sua 
                    //posicao na lista, se nao retorna -1
                    int pos = BuscarPosVertice(x0, y0, &casos[i]);
                    if(pos != -1){
                        //verifica se o vertice adjacente tem um vertice original
                        int posAdj = BuscarPosVertice(x1, y1, &casos[i]);
                        if(posAdj != -1){
                            //Vertice* pontoDestino = new Vertice(x1, y1, posAdj);
                            casos[i].listaAdj[pos]->posAdjacente.push_back(posAdj);
                        }else{
                            Vertice* pontoDestino = new Vertice(x1, y1, casos[i].tamLA);
                            casos[i].listaAdj[casos[i].tamLA] = pontoDestino;
                            casos[i].listaAdj[pos]->posAdjacente.push_back(casos[i].tamLA);
                            ++casos[i].tamLA;
                        }
                    }else{
                        //cria-se vertice de inicio
                        Vertice* pontoInicio = new Vertice(x0, y0, casos[i].tamLA);
                        casos[i].listaAdj[casos[i].tamLA] = pontoInicio;
                        ++casos[i].tamLA;
                        //verifica se o vertice adjacente tem um vertice original
                        int posAdj = BuscarPosVertice(x1, y1, &casos[i]);
                        if(posAdj != -1){
                            pontoInicio->posAdjacente.push_back(posAdj);
                        }else{
                            Vertice* pontoDestino = new Vertice(x1, y1, casos[i].tamLA);
                            casos[i].listaAdj[casos[i].tamLA] = pontoDestino;
                            pontoInicio->posAdjacente.push_back(casos[i].tamLA);
                            ++casos[i].tamLA;
                        }
                    }
                }
                //reinicializa os valores dos pontos;
                x0 = y0 = x1 = y1 = -99;
            }
        }
    }
}

int Trabalho::BuscarPosVertice(int x, int y, Grafo* caso){
    for (int i = 0; i < caso->tamLA; ++i){
        if((caso->listaAdj[i]->coordX == x) and (caso->listaAdj[i]->coordY == y)){
            return i;
        }
    }
    return -1;
}

void Trabalho::Imprimir(){
    for (int i = 0; i < numCasos; ++i){
        cout << "casos: " << i << endl;
        ImprimirGrafo(&casos[i]);
    }
}

void Trabalho::ImprimirGrafo(Grafo* caso){
    for (int i = 0; i < caso->tamLA; ++i){
        cout << i << ": ";
        int numAdj = caso->listaAdj[i]->posAdjacente.size();
        cout << "(" << caso->listaAdj[i]->coordX << "." << caso->listaAdj[i]->coordY << ")-->";
        for (int j = 0; j < numAdj; ++j){
            cout << "|" << caso->listaAdj[i]->posAdjacente.at(j) << "|->";
        }
        cout << "NULL" << endl;
    }
}

void Trabalho::ImprimirPontes(){
    //verificar se o ponto de partida faz parte do grafo, verificando se algum outro vertice é adja a ele
    for (int i = 0; i < numCasos; ++i){
        casos[i].CompletarAdjacencias();
        if ((casos[i].PartidaConexa()) == false){
            casos[i].CriarAlcancePartida();
        }
        casos[i].ImprimirCircEuleriano(0);
        casos[i].imprimirTempo();
    }
    
}

/*======================================================================
...................FUNCOES DA CLASSE GRAFOS.............................
======================================================================*/

Grafo::Grafo(int cap = 0){
    tamLA = 0;
    listaAdj = new Vertice*[cap];
    for (int i = 0; i < cap; ++i){
        listaAdj[i] = NULL;
    }
    capacidade = cap;
    partida = NULL;
    distanciaTotal = 0.0;
}

float Grafo::DistEntrePontos(int vertDe, int vertAte){
    Vertice* ponto1 = listaAdj[vertDe];
    Vertice* ponto2 = listaAdj[vertAte];
    float distancia = sqrt(pow((ponto2->coordX - ponto1->coordX),2) + pow((ponto2->coordY - ponto1->coordY),2));
    return distancia;
}

bool Grafo::PartidaConexa(){
    //cout << "PartidaConexa" << endl;
    int tam = listaAdj[0]->posAdjacente.size();
    if (tam == 0){
        return false;
    }
    return true;
}

void Grafo::CriarAlcancePartida(){
    //cout << "CriarAlcancePartida" << endl;
    Vertice* vertMenorDist = listaAdj[1];
    Vertice* segMenor = listaAdj[1];
    float menorDist = DistEntrePontos(0, 1);
    for (int i = 2; i < tamLA; ++i){
        int aux = DistEntrePontos(0, listaAdj[i]->label);
        if(aux < menorDist){
            aux = menorDist;
            segMenor = vertMenorDist;
            vertMenorDist = listaAdj[i];
        }
    }
    listaAdj[0]->posAdjacente.push_back(vertMenorDist->label);
    listaAdj[0]->posAdjacente.push_back(segMenor->label);
}

bool Grafo::VerificaAdjacencia(int indAdj, int indice){
   // cout << "VerificaAdjacencia" << endl;
    int tam = listaAdj[indAdj]->posAdjacente.size();
    for (int i = 0; i < tam; ++i){
        if(listaAdj[indAdj]->posAdjacente.at(i) == indice){
            return true;
        }
    }
    return false;
}

void Grafo::CompletarAdjacencias(){
    //cout << "CompletarAdjacencias" << endl;
    for (int i = 0; i < tamLA; ++i){
        int tam = listaAdj[i]->posAdjacente.size();
        for (int j = 0; j < tam; ++j){
            int aux = listaAdj[i]->posAdjacente.at(j);
            if (VerificaAdjacencia(aux, i) == false){
                listaAdj[aux]->posAdjacente.push_back(i);
            }
        }
    }
}

void Grafo::ImprimirCircEuleriano(int indice){
    //cout << "ImprimirCircEuleriano" << endl;
    int tamanho = listaAdj[indice]->posAdjacente.size();
    for (int i = 0; i < tamanho; ++i){
        int aux = listaAdj[indice]->posAdjacente.at(i);
        //cout << "aux: " << aux << endl;
        if ((aux != -1) and (PodeAtravessar(indice, aux, i) == true)){
            //cout << indice << "-" << aux << " ";
            distanciaTotal += DistEntrePontos(indice, aux);
            //cout << "distanciaTotal: " << distanciaTotal << endl;
            listaAdj[indice]->posAdjacente[i] = -1;
            ImprimirCircEuleriano(aux);
        }
    }
    //cout << endl;
}

bool Grafo::PodeAtravessar(int pontoOrigem, int pontoDestino, int pos){
    //cout << "PodeAtravessar" << endl;
    int tamanho = listaAdj[pontoOrigem]->posAdjacente.size();
    int cont = 0;
    for (int i = 0; i < tamanho; ++i){
        int aux = listaAdj[pontoOrigem]->posAdjacente.at(i);
        if (aux != -1){
            ++cont;
            //cout << "cont: " << cont << endl;
        }
    }
    //se o cont for 1, entao é o unico caminho
    if (cont == 1){
        //cout << "cont == 1" << endl;
        return true;
    }
    //cout << "\ncont > 1: " << cont << endl;
    bool ancestral[tamLA];
    //inicializa todos vertices como se nao fossem ancestrais e verifica os adjacentes ao destino
    memset(ancestral, false, tamLA);
    int nAdj = ContarAdjVertice(pontoOrigem, ancestral);
   // cout << "nAdjDestino: " << nAdjDestino << endl;
    
    //remove o vertice de destino das adjcencias do de origem e faz a contagem
    int aux = listaAdj[pontoOrigem]->posAdjacente[pos];
    //cout << "listaAdj[pontoOrigem]->posAdjacente[pos]: " << listaAdj[pontoOrigem]->posAdjacente[pos] << endl;
    listaAdj[pontoOrigem]->posAdjacente[pos] = -1;
   // cout << "listaAdj[pontoOrigem]->posAdjacente[pos]: " << listaAdj[pontoOrigem]->posAdjacente[pos] << endl;
    memset(ancestral, false, tamLA);
    int nAdjTest = ContarAdjVertice(pontoOrigem, ancestral);
    //cout << "nAdjDestinoTest: " << nAdjDestinoTest << endl;
    
    //reatribui ao vertice de origem o vertice de destino como seu adjacente
    listaAdj[pontoOrigem]->posAdjacente[pos] = aux;
    //cout << "listaAdj[pontoOrigem]->posAdjacente[pos]: " << listaAdj[pontoOrigem]->posAdjacente[pos] << endl;
    
    return (nAdj > nAdjTest)? false: true;
    /*{
        //cout << "nAdjDestino > nAdjDestinoTest" << endl;
        //entao é ponte
        return false;
    }
    return true;*/
}

int Grafo::ContarAdjVertice(int indice, bool ancestral[]){
    //cout << "ContarAdjVertice" << endl;
    int tamanho = listaAdj[indice]->posAdjacente.size();
    ancestral[indice] = true;
    int cont = 0;
    for (int i = 0; i < tamanho; ++i){
        int aux = listaAdj[indice]->posAdjacente.at(i);
        if (aux != -1 and (ancestral[aux] ==  false)){
            //cout << "entrou" << endl;
            cont += ContarAdjVertice(aux, ancestral);
        }
    }
    //cout << "cont: " << cont << endl;
    return cont;
}
//Abaixo estao funcoes de teste que tentamos implementar para resolver 
//o problema mas que nao funcionaram muito bem
/*void Grafo::ImprimirPontesGrafo(){
    int* descobertos = new int[tamLA];
    int* low = new int[tamLA];
    bool *isAncest = new bool[tamLA];
    stack<int> antecessores = new stack<int>();

    //inicializacao dos descobertos, low e isAncest
    for (int i = 0; i < tamLA; ++i){
        descobertos[i] = -1;
        low[i] = -1;
        isAncest[i] = false;
    }

    //chama vertice por vertice para verificar conectividade
    for (int i = 0; i < tamLA; ++i){
        if (descobertos[i] == -1){
            BuscaProfundindade(i, descobertos, low, antecessores, isAncest);
        }
    }
}

void Grafo::BuscaProfundindade(int vertLabel, int descobertos[], int low[], stack<int> *antecessores, bool isAncest[]){
	static int time = 0;
    
    //atualiza os valores de desc e do low no tempo de deescoberta
    descobertos[vertLabel] = low[vertLabel] = ++time;
    antecessores->push(vertLabel);
    isAncestral[vertLabel] = true;
    
    //verifica a lista de vertices adjacentes ao vertice atual
    int tamanho = listaAdj[vertLabel]->posAdjacente.size();
    for (int i = 0; i < tamanho; ++i){
        Vertice* vertAdj = listaAdj[i];
        //se o vertAdj nao foi descoberto, entao sera adicionado na lista de desc
        //e chamado recursivamente e preenche o low com o vertice q tem o menor tempo de descoberta
        if (descobertos[vertAdj->label] == -1){
            BuscaProfundindade(vertAdj->label, descobertos, low, antecessores, isAncest);
            low[vertLabel] = min(low[vertLabel], low[vertAdj->label]);
        }else if(isAncest[vertAdj->label] == true){
            low[vertLabel] = min(low[vertLabel], low[vertAdj->label]);
        }
    }
    for (int i = 0; i < tamanho; ++i){
        if ((low[i] == descobertos[vertLabel]) and (isAncest[vertLabel] != false)){
            cout << "é ponte: " << vertLavel << enld;
        }
    }
}*/


