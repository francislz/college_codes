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
#include <cstdlib>
#include "geek.hpp"
using namespace std;

//Verifica se a entrada é um numero, se nao for exibe a msg de erro
int recebeNumero(){
    int num;
    while (!(cin >> num)){
        cin.clear();
        cin.ignore(2, '\n');
        cout << "Desculpe, voce nao digitou um numero. Tente novamente: ";
    }
    //cin.ignore(2, '\n');
    return num;
}

Geek Cadastrar(){
    cout << "Digite o ID:" << endl;
    int id = recebeNumero();
    
    cout << "Digite o Titulo:" << endl;
    char titulo[50];
    cin.ignore(2,'\n');
    cin.getline(titulo, 50);
    
    char personagem[4][20];
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 20; ++j){
            personagem[i][j] = ' ';
        }
    }

    int i = 0;
    for(; i < 2; ++i){
        cout << "Digite o " << (i + 1) << " personagem:" << endl;
        //cin.ignore(2,'\n');
        cin.getline(personagem[i], 20);
    }
    char opc;
    do{
        cout << "Deseja digitar o nome de outro personagem ? (s/n)" << endl;
        cin >> opc;
        if(opc == 's'){
            cout << "Digite o " << (i + 1) << " personagem:" << endl;
            cin.ignore(2,'\n');
            cin.getline(personagem[i], 20);
            ++i;
        }
    }while(opc == 's' and i < 4);

    cout << "Digite o ano:" << endl;
    int ano = recebeNumero();
    
    cout << "Digite o total de episodios:" << endl;
    int totalEp = recebeNumero();
    
    char sinopse[200];
    cout << "Digite a sinopse:" << endl;
    cin.ignore(2,'\n');
    cin.getline(sinopse, 200);

    Geek geek(id, titulo, personagem, ano, totalEp, sinopse);
    return geek;
}

int main(){
    char ARQ[] = "geek";
    Arquivo arquivo(ARQ);
    arquivo.Imprimir();
    //Menu(&arquivo);

    int opc;
    do{
        //Menu principal
        opc = 0;
        cout << endl;
        cout << "Operacao desejada:" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Buscar" << endl;
        cout << "4 - Listar Todos" << endl;
        cout << "0 - Sair" << endl;
        cin >> opc;

        switch(opc){
            case 1:{ //Opcao de inserir
                system("clear");//Limpa o terminal
                Geek geek = Cadastrar();//Chamada da funcao de cadastro que recebe os dados da entrada padrao
                arquivo.Inserir(geek);//Inserção ordenada
                break;
            }
            case 2:{//Opcao de remover
                cout << "Digite o ID da saga a ser removido" << endl; //Remove de acordo com o ID
                int id;
                cin >> id;
                cout << "Tem certeza que deseja remover ? Essa acao nao pode ser desfeita. (s/n)" << endl;
                char aux;
                cin >> aux; 
                if(aux == 's'){
                    arquivo.Remover(id);
                }
                break;
            }
            case 3:{//Opcao de Buscar
                cout << "Digite o ID da saga a ser buscada: " << endl;//Busca binaria o ID
                int idBusca;
                cin >> idBusca;
                Geek geek;
                if(arquivo.BuscarGeek(idBusca, geek)){
                    geek.Imprimir();
                }
                else{
                    cerr << "ID nao encontrado!!!" << endl;
                }
                break;
            }
            case 4:{//Imprimir todos em ordem pelo ID
                arquivo.ImprimirTodos();
                // for (unsigned int i = 0; i < arquivo.LerCabecalho(); ++i){
                //     Geek aux = arquivo.LerGeek(i);
                //     aux.Imprimir();
                // }
                break;
            }
            case 0:
                cout << "Bye Bye!!" << endl;
                break;
            default://Caso nao seja uma das opcao a saida é invalida
                cout << "Opcao invalida, tente novamente!" << endl;
                break;
        }
    }while(opc != 0);
}
