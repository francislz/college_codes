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

//Retorna o ID da saga
int Geek::retornarId(){
    return id;
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
    {//Verifica se o arquivo existe, senao cria o mesmo.
        fstream arq(nomeArq);
        if(!arq){
            cabecalho = 0;
            ofstream arquivo(nomeArq);
            arquivo.seekp(0);
            arquivo.write(reinterpret_cast<char*>(&cabecalho), sizeof(Cabecalho));
        }
    }
    arquivo.open(nomeArq);//Abre o arquivo
    cabecalho = LerCabecalho();
}

//Destrutor arquivo
Arquivo::~Arquivo(){
    arquivo.close();//Fecha o arquivo
}

//Imprimir o cabecalho do arquivo (Funcao para debug)
void Arquivo::Imprimir(){
    cout << "Cabecalho: " << cabecalho << endl;
}

//Le o cabecalho do arquivo
Cabecalho Arquivo::LerCabecalho(){
    Cabecalho cab;
    arquivo.seekg(0);
    arquivo.read(reinterpret_cast<char*>(&cab), sizeof(Cabecalho));
    return cab;
}

//Escreve o cabecalho no arquivo
void Arquivo::EscreverCabecalho(){
    arquivo.seekp(0);
    arquivo.write(reinterpret_cast<char*>(&cabecalho), sizeof(Cabecalho));
}

//Calcula a posicao para o Geek no arquivo com base no indice do Objeto
streampos Arquivo::CalcularPos(int indice){
    streampos pos = (sizeof(Geek) * indice) + sizeof(Cabecalho);
    return pos;
}

//Le e retorna o Geek em uma determinada posicao do arquivo
Geek Arquivo::LerGeek(int pos){
    Geek geek;
    arquivo.seekg(CalcularPos(pos));
    arquivo.read(reinterpret_cast<char*>(&geek), sizeof(Geek));
    return geek;
}

//Inserir Geek no arquivo
void Arquivo::Inserir(Geek& geek){
    if(cabecalho != 0){ // Verifica se ja tem algum Obj cadastrado
        Geek listaGeek[cabecalho + 1];//Vetor de Geeks, le-se todos os dados
        for (unsigned int i = 0; i < cabecalho; ++i){
            Geek aux = LerGeek(i);
            listaGeek[i] = aux;
        }
        listaGeek[cabecalho] = geek;//Novo dados ocupa a ultima posicao do vetor

        //Bubble Sort que ordena o vetor pelo ID
        for (unsigned int i = cabecalho; i > 0; --i){
           for (unsigned int j = 0; j < i; ++j){
                if(listaGeek[j].id > listaGeek[j + 1].id){
                    Geek aux = listaGeek[j];
                    listaGeek[j] = listaGeek[j + 1];
                    listaGeek[j + 1] = aux;
                }
            } 
        }

        //Escreve os dados no arquivo
        ++cabecalho;
        EscreverCabecalho();
        for (unsigned int i = 0; i < cabecalho; ++i){
            arquivo.seekp(CalcularPos(i));
            arquivo.write(reinterpret_cast<char*>(&listaGeek[i]), sizeof(Geek));
        }
    }
    else{//Se nao houver dados apenas se insere
        arquivo.seekp(CalcularPos(cabecalho));
        arquivo.write(reinterpret_cast<char*>(&geek), sizeof(Geek));
        ++cabecalho;
        EscreverCabecalho();
    }
}

//Busca Binaria retorna a posicao encontrada, ou -1 se nao encontrou
int Arquivo::Buscar(int id){
    if(cabecalho > 0){
        bool naoAchou = true;
        int ini, fim;
        ini = 0;
        fim = cabecalho;
        int meio;
        while(ini <= fim and naoAchou){
            meio = (fim + ini) / 2;
            Geek aux = LerGeek(meio);
            if(aux.id == id){
                naoAchou = false;
                return meio;
            }
            else{
                if(aux.id > id) fim = meio - 1;
                else ini = meio + 1;
            }
        }
        if(!naoAchou){
            return -1;
        }
    }
    return -1;
}

//Remove Baseado no ID
void Arquivo::Remover(int pos){
    Geek listaGeek[cabecalho - 1];//Vetor com o tamanho atual - 1, pois 1 dado sera removido
    int j = 0;
    for (unsigned int i = 0; i < cabecalho; ++i){
        if(i != pos){ //Verifica se a posica é igual ao do que vai ser removido, se for nao é copiado
            Geek aux = LerGeek(i);
            listaGeek[j] = aux;
            ++j;
        }
    }
    --cabecalho;//Decrementa o cabecalho
    EscreverCabecalho();
    //Escreve no arquivo
    for (unsigned int i = 0; i < cabecalho; ++i){
        arquivo.seekp(CalcularPos(i));
        arquivo.write(reinterpret_cast<char*>(&listaGeek[i]), sizeof(Geek));
    }
}