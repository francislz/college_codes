/* 
    Trabalho de Estrutura de Dados
    Método usando TAD, para manipular um geek object
    Copyright 2016 by Victor Hugo, Franciscone Luiz, Igor Carvalho 
    geek.hpp
        Header com o escopo das Classes
    geek.cpp
        Arquivo que contém os metodos da classe Geek
    main.cpp
        Arquivo com a funcao main e o menu principal
    Makefile
        Arquivo Makefile que gera as classes e compila o codigo
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "geek.hpp"
using namespace std;

/*
------------------------------------
------------------------------------
-------Funcoes da classe geek-------
------------------------------------
------------------------------------
*/

//Construtor Geek com parametros
Geek::Geek(int Id, char Ti[50], char Per[4][20], int Ano, int To, char Sin[200]){
    id = Id;
    strcpy(titulo,Ti);
    for (int i = 0; i < 4; ++i){
        strcpy(personagens[i], Per[i]);
    }
    anoLancamento = Ano;
    totalEp = To;
    strcpy(sinopse, Sin);
}

//Destrutor Geek
Geek::~Geek(){}
//Construtor Geek vazio
Geek::Geek(){}

//Sobrecarga operador de igual, que faz o papel de copia do Objeto
Geek& Geek::operator =(Geek& geek){
    id = geek.id;
    strcpy(titulo,geek.titulo);
    for (int i = 0; i < 4; ++i){
        strcpy(personagens[i], geek.personagens[i]);
    }
    anoLancamento = geek.anoLancamento;
    totalEp = geek.totalEp;
    strcpy(sinopse, geek.sinopse);
    return *this;
}

//Imprimir a saga
void Geek::Imprimir(){
    cout << endl;
    cout << "ID: " << id << endl
        << "TITULO: " << titulo << endl;
    for (int i = 0; i < 4 and (personagens[i][0] != ' '); ++i){
        cout << "PERSONAGEM " << (i + 1) << ": " << personagens[i] << endl;
    }
    cout << "ANO LANCAMENTO: " << anoLancamento << endl
        << "TOTAL DE EPISODIOS: " << totalEp << endl
        << "SINOPSE: " << sinopse << endl;
}

/*
------------------------------------
------------------------------------
----Funcoes da class SequenceSet----
------------------------------------
------------------------------------
*/
SequenceSet Arquivo::LerSequenceSet(int indice){
    SequenceSet set;
    arquivo.seekg(CalcularPos(indice));
    arquivo.read(reinterpret_cast<char*>(&set), sizeof(SequenceSet));
    return set;
}

void Arquivo::EscreveSequenceSet(SequenceSet& set, int pos, bool novoSeq){
    arquivo.seekp(CalcularPos(pos));
    arquivo.write(reinterpret_cast<char*>(&set), sizeof(SequenceSet));
    if(novoSeq) cabecalho.tamanho++;
    EscreverCabecalhoArq();
}

/*
------------------------------------
------------------------------------
------Funcoes da classe arquivo-----
------------------------------------
------------------------------------
*/
//Construtor arquivo
Arquivo::Arquivo(char nomeArq[]){
    {//Busca se o arquivo existe, senao cria o mesmo.
        fstream arq(nomeArq);
        if(!arq){
            cabecalho.tamanho = 0;
            ofstream arquivo(nomeArq);
            arquivo.seekp(0);
            arquivo.write(reinterpret_cast<char*>(&cabecalho), sizeof(CabecalhoArq));
        }
    }
    arquivo.open(nomeArq);//Abre o arquivo
    cabecalho = LerCabecalhoArq();
}

//Destrutor arquivo
Arquivo::~Arquivo(){
    arquivo.close();//Fecha o arquivo
}

//Imprimir o cabecalho do arquivo (Funcao para debug)
void Arquivo::Imprimir(){
    cout << "CabecalhoArq: " << cabecalho.tamanho << endl;
    cout << "PrimeiraSeq: " << cabecalho.primeiraSeq << endl;
    cout << "ProximaVazia: " << cabecalho.proximaVazia << endl;
}

//Imprimir o cabecalho do arquivo (Funcao para debug)
void Arquivo::ImprimirTodos(){
    int k = cabecalho.primeiraSeq;
    for(int i = 0; i < cabecalho.tamanho; ++i){
        SequenceSet set = LerSequenceSet(k);
        for(int j = 0; j < set.cabecalho.tamanhoSeq; ++j){
            set.geek[j].Imprimir();
        }
        k = set.cabecalho.proximaSeq;
        //cout << endl;
        cout << "ProximaSeq: " << k << endl;
    }
}

//Le o cabecalho do arquivo
CabecalhoArq Arquivo::LerCabecalhoArq(){
    CabecalhoArq cab;
    arquivo.seekg(0);
    arquivo.read(reinterpret_cast<char*>(&cab), sizeof(CabecalhoArq));
    return cab;
}

//Escreve o cabecalho no arquivo
void Arquivo::EscreverCabecalhoArq(){
    arquivo.seekp(0);
    arquivo.write(reinterpret_cast<char*>(&cabecalho), sizeof(CabecalhoArq));
}

//Calcula a posicao para o Geek no arquivo com base no indice do Objeto
streampos Arquivo::CalcularPos(int indice){
    streampos pos = (sizeof(SequenceSet) * indice) + sizeof(CabecalhoArq);
    return pos;
}

//Busca a proxima sequencia vazia e atualiza o cabecalho
void Arquivo::BuscaVazia(){
    int k = cabecalho.primeiraSeq;
    bool notFound = true;
    //Percorre os "ponteiros" ate encontrar o correpondente
    for(int i = 0; i < cabecalho.tamanho and notFound; ++i){
        SequenceSet set = LerSequenceSet(k);
        if(set.cabecalho.tamanhoSeq != 5){
            notFound = false;
            cabecalho.proximaVazia = k;
        }
        k = set.cabecalho.proximaSeq;
    }
}

//Busca sequencia que tem o intervalo do id passado por parametro
int Arquivo::BuscaSeq(Geek& geek){
    bool achou = false;
    int posAtual = cabecalho.primeiraSeq;
    int posAnt = 0;
    //Percorre ate achar ou ate ler todo o arquivo binario
    while((posAtual != -1) and (!achou)){
        SequenceSet seq = LerSequenceSet(posAtual);
        if((seq.geek[0].id <= geek.id) and (seq.geek[seq.cabecalho.tamanhoSeq - 1].id >= geek.id)){
            achou = true;
        }
        posAnt = posAtual;
        posAtual = seq.cabecalho.proximaSeq;
    }
    if(achou)//Se achou retorna a posica, senão retorna -1
        return posAnt;
    return -1;
}

//Faz o split de uma nova insercao e muda os ponteiros dos sequences 
void Arquivo::FazSplit(int pos, Geek& geek){
    SequenceSet atual = LerSequenceSet(pos);//Sequence atual
    SequenceSet novo;
    int i = 0;
    bool mudou = false;//Controla se o novo valor fica no sequence antigo ou novo
    while(i <= 2){
        Geek aux;
        if(mudou or (geek.id < atual.geek[atual.cabecalho.tamanhoSeq - 1].id)){//Valor a ser inserido é o do atual
            aux = atual.geek[atual.cabecalho.tamanhoSeq - 1];
            --atual.cabecalho.tamanhoSeq;//Descrementa sequence atual
        }
        else{
            mudou = true;//Realiza a mudanda
            aux = geek; //Valor a ser usando é o novo
        }
        //Insere ordenado no sequence
        int j= novo.cabecalho.tamanhoSeq - 1;
        while((j>= 0) and (aux.id < novo.geek[j].id)){
            novo.geek[j+ 1] = novo.geek[j];
            --j;
        }
        novo.geek[j+ 1] = aux;
        novo.cabecalho.tamanhoSeq++;
        ++i;
    }
    //Se nao mudou insere o novo geek no sequence antigo
    if(!mudou){
        atual.geek[atual.cabecalho.tamanhoSeq] = geek;
        atual.cabecalho.tamanhoSeq++;
    }
    //Muda os ponteiros e escreve o sequence
    cabecalho.proximaVazia = pos;
    novo.cabecalho.proximaSeq = atual.cabecalho.proximaSeq;
    atual.cabecalho.proximaSeq = cabecalho.tamanho;
    EscreveSequenceSet(atual, pos, false);
    EscreveSequenceSet(novo, cabecalho.tamanho, true);
}

void Arquivo::Inserir(Geek& geek){
    bool naoAchou = true;
    int pos = cabecalho.primeiraSeq;
    if(cabecalho.tamanho == 0){
        SequenceSet novo;
        novo.geek[novo.cabecalho.tamanhoSeq] = geek;
        novo.cabecalho.tamanhoSeq++;
        cabecalho.primeiraSeq = 0;
        EscreveSequenceSet(novo, cabecalho.tamanho, true);
    }
    else{
        while(naoAchou){
                SequenceSet set = LerSequenceSet(pos);
                if(set.cabecalho.tamanhoSeq == 5){
                    if(geek.id < set.geek[set.cabecalho.tamanhoSeq - 1].id){
                        FazSplit(pos, geek);
                        naoAchou = false;
                    }
                    else{
                        if(set.cabecalho.proximaSeq != -1) pos = set.cabecalho.proximaSeq;
                        else{
                            SequenceSet novo;
                            novo.geek[novo.cabecalho.tamanhoSeq] = geek;
                            novo.cabecalho.tamanhoSeq++;
                            set.cabecalho.proximaSeq = cabecalho.tamanho;
                            EscreveSequenceSet(set, cabecalho.tamanho - 1, false);
                            EscreveSequenceSet(novo, cabecalho.tamanho, true);
                            naoAchou = false;
                        }
                    }
                }
                else{
                    if(geek.id < set.geek[set.cabecalho.tamanhoSeq - 1].id){
                        int i = set.cabecalho.tamanhoSeq - 1;
                        while((i >= 0) and (geek.id < set.geek[i].id)){
                            set.geek[i + 1] = set.geek[i];
                            --i;
                        }
                        set.geek[i + 1] = geek;
                        set.cabecalho.tamanhoSeq++;
                        EscreveSequenceSet(set, pos, false);
                        naoAchou = false;
                    }
                    else{
                        if(set.cabecalho.proximaSeq != -1){
                            SequenceSet prox = LerSequenceSet(set.cabecalho.proximaSeq);
                            if(geek.id < prox.geek[0].id){
                                set.geek[set.cabecalho.tamanhoSeq] = geek;
                                ++set.cabecalho.tamanhoSeq;
                                naoAchou = false;
                            }
                            else{
                                pos = set.cabecalho.proximaSeq;
                            }
                        }
                        else{
                            set.geek[set.cabecalho.tamanhoSeq] = geek;
                            set.cabecalho.tamanhoSeq++;
                            EscreveSequenceSet(set, cabecalho.tamanho - 1, false);
                            naoAchou = false;
                        }
                    }
                }
            }
    }
}

//Busca Binaria retorna a posicao encontrada, ou -1 se nao encontrou
int Arquivo::BuscarGeek(int id){return 0;}

//Remove Baseado no ID
void Arquivo::Remover(int pos){}