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
#ifndef GEEK_HPP
#define GEEK_HPP
#include <iostream>
#include <fstream>
using namespace std;

class Geek{
    friend class SequenceSet;
    friend class Arquivo;
    private:
        int id;
        char titulo[50];
        char personagens[4][20]; //(2 a 4) personagens
        int anoLancamento;
        int totalEp;
        char sinopse[200];
    public:
        Geek();
        Geek(int Id, char Ti[50], char Per[4][20], int Ano, int To, char Sin[200]);
        ~Geek();
        int getId(){ return id; }
        Geek& operator=(Geek& geek);
        void Imprimir();
};

class CabecalhoSeq{
    friend class SequenceSet;
    friend class Arquivo;
    private:
        int proximaSeq;
        int tamanhoSeq;
    public:
        CabecalhoSeq(){
            proximaSeq = -1;
            tamanhoSeq = 0;
        }
};

class SequenceSet{
    friend class Arquivo;
    private:
        CabecalhoSeq cabecalho;
        Geek geek[5];
    public:
        SequenceSet(){}
};

class CabecalhoArq{
    friend class Arquivo;
    private:
        int tamanho;
        int primeiraSeq;
        int proximaVazia;
    public:
        CabecalhoArq(){
            tamanho = -1;
            primeiraSeq = -1;
            proximaVazia = -1;
        }
};

class Arquivo{
    friend class fstream;
    private:
        fstream arquivo;
        CabecalhoArq cabecalho;
        int BuscaSeq(Geek& geek);
        int SeqBuscaGeek(int idBusca, int& posAnt);
        int SeqBuscaGeek (int idBusca);
        void FazSplit(int pos, Geek& geek);
        void BuscaVazia();
    public:
        Arquivo(char nomeAqr[]);
        ~Arquivo();
        CabecalhoArq LerCabecalhoArq();
        void EscreverCabecalhoArq();
        streampos CalcularPos(int indice);
        //Funcoes SequenceSet
        SequenceSet LerSequenceSet(int indice);
        void EscreveSequenceSet(SequenceSet& set, int pos, bool novoSeq);
        //Funcoes do Arquivo
        void Inserir(Geek& geek);
        bool BuscarGeek(int idBusca, Geek& geekBuscado);
        //Geek LerGeek (SequenceSet seq, int pos);
        void Remover(int id);
        void Imprimir();
        void ImprimirTodos();
};

#endif
