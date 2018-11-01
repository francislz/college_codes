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
typedef unsigned int Cabecalho;

class Geek{
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
        int retornarId();
        Geek& operator=(Geek& geek);
        void Imprimir();
};

class Arquivo{
    friend class fstream;
    private:
        fstream arquivo;
        Cabecalho cabecalho;
    public:
        Arquivo(char nomeAqr[]);
        ~Arquivo();
        Cabecalho LerCabecalho();
        void EscreverCabecalho();
        streampos CalcularPos(int indice);
        void Inserir(Geek& geek);
        Geek LerGeek(int pos);
        //void ListarTodos(Geek listaGeek[]);
        int Buscar(int idBusca);
        void Remover(int id);
        void Imprimir();
};

#endif
