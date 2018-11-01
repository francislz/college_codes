/* 
    Trabalho de Estrutura de Dados
    Método usando TAD, para manipular um geek object
    Copyright 2017 by Victor Hugo, Franciscone Luiz, Igor Carvalho 
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
#include <cstdlib>
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
    //Verifica se ja existe dado no arquivo, se nao cria um novo sequence
    if(cabecalho.tamanho == 0){
        SequenceSet novo;
        novo.geek[novo.cabecalho.tamanhoSeq] = geek;
        novo.cabecalho.tamanhoSeq++;
        cabecalho.primeiraSeq = 0;
        EscreveSequenceSet(novo, cabecalho.tamanho, true);
    }
    //Analogo ao primeiro caso, se ja existe dado procura onde vai ser inserido
    else{
        //Equanto nao achar o lugar de insercao ele procura
        while(naoAchou){
            SequenceSet set = LerSequenceSet(pos);
            //Verifica se o sequence esta cheio
            if(set.cabecalho.tamanhoSeq == 5){
                //Se estiver cheio e ele pertence ao intervalo cheio, faz o Split
                if(geek.id < set.geek[set.cabecalho.tamanhoSeq - 1].id){
                    FazSplit(pos, geek);
                    naoAchou = false;
                }
                else{
                    //Senao, se tiver um proximo sequence ele pula para o proximo
                    if(set.cabecalho.proximaSeq != -1) pos = set.cabecalho.proximaSeq;
                    //Caso contrario um novo sequence é criado
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
            //Se a incersão for em um sequence nao cheio
            else{
                //Verifica se o ID pertence ao intervalo, se pertencer insere
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
                    //Senao, se existe uma proxima sequencia e o elemento dela é maior do que o que sera inserido
                    //O valor é inserido na ultima posicao
                    if(set.cabecalho.proximaSeq != -1){
                        SequenceSet prox = LerSequenceSet(set.cabecalho.proximaSeq);
                        if(geek.id < prox.geek[0].id){
                            set.geek[set.cabecalho.tamanhoSeq] = geek;
                            ++set.cabecalho.tamanhoSeq;
                            naoAchou = false;
                        }
                        //Senao, apenas pula para a proxima sequencia
                        else{
                            pos = set.cabecalho.proximaSeq;
                        }
                    }
                    //Caso nao tenha uma proxima sequencia o valor é apenas inserido
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

int Arquivo::SeqBuscaGeek(int idBusca){
    bool achou = false;
    int posAtual = cabecalho.primeiraSeq;
    //Percorre ate achar ou ate ler todo o arquivo binario
    while((posAtual != -1) and (!achou)){
        SequenceSet seq = LerSequenceSet(posAtual);
        if((seq.geek[0].id <= idBusca) and (seq.geek[seq.cabecalho.tamanhoSeq - 1].id >= idBusca)){
            achou = true;
        }
        else{
            posAtual = seq.cabecalho.proximaSeq;
        }
    }
    if(achou)//Se achou retorna a posica, senão retorna -1
        return posAtual;
    return -1;
}

//Busca Binaria retorna se foi encontrado o geek no sequence, se foi retorna o Geek na referencia
bool Arquivo::BuscarGeek(int idBusca, Geek& geekBuscado){
    int posSeq = SeqBuscaGeek(idBusca);
    if (posSeq != -1){
        SequenceSet seq = LerSequenceSet(posSeq);
        int inicio = 0;
        int fim = seq.cabecalho.tamanhoSeq;
        int meio;
        while (inicio <= fim){
            meio = (inicio + fim) / 2;
            if(seq.geek[meio].id == idBusca){
                geekBuscado = seq.geek[meio];
                return true;
            }
            else if ( seq.geek[meio].id > idBusca ){
                fim = meio;
            }
            else{
                inicio = meio;
            }
        }
    }
    return false;
}

//Busca a sequencia do intervalo do ID
int Arquivo::SeqBuscaGeek(int idBusca, int& posAnt){
    bool achou = false;
    int posAtual = cabecalho.primeiraSeq;
    posAnt = -1;
    //Percorre ate achar ou ate ler todo o arquivo binario
    while((posAtual != -1) and (!achou)){
        SequenceSet seq = LerSequenceSet(posAtual);
        if((seq.geek[0].id <= idBusca) and (seq.geek[seq.cabecalho.tamanhoSeq - 1].id >= idBusca)){
            achou = true;
        }
        else{
            posAnt = posAtual;
            posAtual = seq.cabecalho.proximaSeq;
        }
    }
    if(achou)//Se achou retorna a posicao
        return posAtual;
    //caso nao ache 
    return -1;
}

//Remove Baseado no ID
void Arquivo::Remover(int id){
    int posAnt;
    int posSeq = SeqBuscaGeek(id, posAnt);
    int cont = 0;
    //Se existe uma sequencia com o ID no intervalo ele busca para a remoção
    if(posSeq != -1){
        SequenceSet seq = LerSequenceSet(posSeq);
        bool naoAchou = true;
        int inicio = 0;
        int fim = seq.cabecalho.tamanhoSeq;
        int meio;
        //Busca o ID no vetor de GEEK da sequencia
        while((inicio <= fim) and (naoAchou)){
            meio = (inicio + fim) / 2;
            if(seq.geek[meio].id == id){
                naoAchou = false;
            }
            else if ( seq.geek[meio].id > id ){
                fim = meio - 1;
            }
            else{
                inicio = meio + 1;
            }
            cont++;
        }
        //Se achar remove
        if(!naoAchou){
            //Se so tiver um valor remove e muda o ponteiro das sequencias
            if(seq.cabecalho.tamanhoSeq == 1){
                if(posAnt != -1){
                    SequenceSet ant = LerSequenceSet(posAnt);
                    ant.cabecalho.proximaSeq = seq.cabecalho.proximaSeq;
                    EscreveSequenceSet(ant, posAnt, false);
                }
                //Senao muda o ponteiro da primeira sequencia do arquivo
                else{
                    cabecalho.primeiraSeq = seq.cabecalho.proximaSeq;
                }
            }
            else{
                //Se nao tiver so um elemento, sobrescreve o elemento
                fim = seq.cabecalho.tamanhoSeq;
                ++meio;
                while(meio < fim){
                    seq.geek[meio-1] = seq.geek[meio];
                    ++meio;
                }
            }
            seq.cabecalho.tamanhoSeq--;
            EscreveSequenceSet(seq, posSeq, false);
        }
        //Se nao achou o ID no Vetor retorna a mensagem
        else{
            cerr << "ID não encontrado" << endl;
        }
    }
    //Se a sequencia do ID nao existe a mensagem é retornado
    else{
        cerr << "ID não encontrado!!" << endl;
    }
}
bool Arquivo::IntercalaBloco(ifstream auxE[2], ofstream auxS[2], int passo, int saida){
    cout << "intercala" << endl;
    bool intercalou = false;
    //auxiliar de leitura
    Geek geeks[2];
    //guarda as posicoes dos dados no arquivo
    int pos[2] = {0,0};
    bool valido[2] = {false, false};
    //intercalar os dados dos dois arquivos de entrada no arquivo de saida 
    while((pos[0]+pos[1]) < (2 * passo)){
        //verifica se deve ler o dado do arquivo
        if((pos[0] < passo) and (!valido[0])){
            //verifica se há dado para ler no primeiro arquivo
            if(auxE[0].read((char*) &geeks[0], sizeof(Geek))){
                valido[0] = true;
            }
            //se nao houver a posicao recebe o passo, para sair do while apos esse ciclo
            else{
                pos[0] = passo;
            }
        }
        if((pos[1] < passo) and (!valido[1])){
            //verifica se ha dado para ler no segundo arquivo
            if(auxE[1].read((char*) &geeks[1], sizeof(Geek))){
                valido[1] = true;
            }
            //se nao houver a posicao recebe o passo, para sair do while apos esse ciclo
            else{
                pos[1] = passo;
            }
        }
        //verifica se os dois dados sao validos
        if(valido[0] and valido[1]){
            intercalou = true;
            //acha o menor e o escreve no arquivo de saida
            //incrementa a posicao e invalida para que seja lido outro dado
            if(Comparar(geeks[0].titulo, geeks[1].titulo)){
                auxS[saida].write((const char*)(&geeks[0]), sizeof(Geek));
                valido[0] = false;
                ++pos[0]; 
            }
            else{
                auxS[saida].write((const char*)(&geeks[1]), sizeof(Geek));
                valido[1] = false;
                ++pos[1];
            }
        }
        // somente o registro do arquivo 1 é valido
        else if(valido[0]){
            intercalou = true;
            auxS[saida].write((const char*)(&geeks[0]), sizeof(Geek));
            valido[0] = false;
            ++pos[0];
        }
        //somente o registro do arquivo 2 é valido
        else if(valido[1]){
            intercalou = true;
            auxS[saida].write((const char*)(&geeks[1]), sizeof(Geek));
            valido[1] = false;
            ++pos[1];
        }   
    }
    //returna confirmando que houve intercalacao
    return intercalou;
}

void Arquivo::MergeSort(ofstream& arqS){
    // copiar todos os registros para o novo arquivo
    {
        ofstream arqE("arqEntrada.dat", ios::binary);
        arqE.close();
    }
    fstream arqE("arqEntrada.dat", ios::binary);
    int numRegistros = CopiaArquivo(arqE);
     //obter metade do numero de Registros
    int metade = numRegistros / 2;
    // depois cria 2 arquivos auxiliares
    ofstream arqB1("arqB1.dat", ios::binary);
    ofstream arqB2("arqB2.dat", ios::binary);
   
    //posiciona o ponteiro de leitura para o comeco do arquivo
    arqE.seekg(0, ios::end);
    Geek umGeek;
    //copiar os dados para os dois arquivos auxiliares
    for(int i = 0; i < metade; ++i){
        arqE.read((char*) &umGeek, sizeof(Geek));
        arqB1.write((char*) &umGeek, sizeof(Geek));
    }
    for(int i = metade+1; i <= numRegistros; ++i){
        arqE.read((char*) &umGeek, sizeof(Geek));
        arqB2.write((char*) &umGeek, sizeof(Geek));
    }
    cout << "mergesort ";
    //fechar os arquivos
    arqB1.close();
    arqB2.close();
    arqE.close();
    //arquivos auxiliares
    ifstream auxEntrada[2];
    ofstream auxSaida[2];
    //variaveis de controle
    int passo = 1;
    bool ida = true;
    bool ultimo[2];
    //laço principal
    while(passo <= numRegistros){
        if(ida){
            //arquivos de entrada
            auxEntrada[0].open("arqB1.dat", ios::binary);
            auxEntrada[1].open("arqB2.dat",ios::binary);
            //arquivos de saida
            auxSaida[0].open("arqC1.dat", ios::binary);
            auxSaida[1].open("arqC2.dat", ios::binary);
        }
        else{
            //arquivos de entrada
            auxEntrada[0].open("arqC1.dat", ios::binary);
            auxEntrada[1].open("arqC2.dat", ios::binary);
            //arquivos de saida
            auxSaida[0].open("arqB1.dat", ios::binary);
            auxSaida[1].open("arqB2.dat", ios::binary);
        }
        //testa se houve algo de errado com os arquivos
        if((!auxEntrada[0]) or (!auxEntrada[1]) or (!auxSaida[0]) or (!auxSaida[1])){
            cerr << "Arquivos auxiliares não puderam ser abertos" << endl;
            exit(EXIT_FAILURE);
        }
        //repeticao para intercalar os dados dos arquivos de leitura nos de escrita
        while((!auxEntrada[0].eof()) and(!auxEntrada[1].eof())){
            ultimo[0] = IntercalaBloco(auxEntrada, auxSaida, passo, 0);
            ultimo[1] = IntercalaBloco(auxEntrada, auxSaida, passo, 1);
        }

        auxEntrada[0].close();
        auxEntrada[1].close();
        auxSaida[0].close();
        auxSaida[1].close();
        //muda o ida para que saber quais arquivos serao os de leitura e quais serao de entrada
        ida = !ida;
        //multiplica o passo por dois
        passo *= 2;

    }
    ifstream auxEnt;
    //encontra qual arquivo esta com os dados ordenados
    if(ida){
        if(ultimo[0]){
            auxEnt.open("arqB1.dat", ios::binary);
        }
        else{
            auxEnt.open("arqB2.dat", ios::binary);
        }
    }
    else{
        if(ultimo[0]){
            auxEnt.open("arqC1.dat", ios::binary);
        }
        else{
            auxEnt.open("arqC2.dat", ios::binary);  
        }
    
    }
    //escreve o cabecalho com a quantidade de registros no arquivo
    int cabecalhoArquivo = numRegistros;
    arqS.seekp(0,ios::beg);
    arqS.write(reinterpret_cast<char*>(&cabecalhoArquivo), sizeof(int));
    // copia os registros em ordem crescente no arquivo de saida
    while(auxEnt.read((char*)(&umGeek), sizeof(Geek))){
        umGeek.Imprimir();
        arqS.write((const char*)(&umGeek), sizeof(Geek));
    }
    //fechar e remove os arquivos auxiliares utilizados
    auxEnt.close();
    remove("arqB1.dat");
    remove("arqB2.dat");    
    remove("arqC1.dat");
    remove("arqC2.dat");
    remove("arqEntrada.dat");
}
//copia de um arquivo em forma de Sequence
int Arquivo::CopiaArquivo(fstream& arqE){
    int k = cabecalho.primeiraSeq;
    int numRegistros = 0;
    for(int i = 0; i < cabecalho.tamanho; ++i){
        SequenceSet set = LerSequenceSet(k);
        for(int j = 0; j < set.cabecalho.tamanhoSeq; ++j){
            Geek umGeek = set.geek[j];
            arqE.write((char*)(&umGeek), sizeof(Geek));
            ++numRegistros;
        }
        k = set.cabecalho.proximaSeq;
    }
    return numRegistros;
}
//Imprime um arquivo em ordem de leitura
void Arquivo::ImprimirArquivo(fstream& arqS){
    arqS.seekg(0, ios::end);
    int numRegistros;
    arquivo.read(reinterpret_cast<char*>(&numRegistros), sizeof(int));
    Geek umGeek;
    int i = 0;
    while(i < numRegistros){
        arqS.read((char*) (&umGeek), sizeof(Geek));
        umGeek.Imprimir(); 
        ++i;
    }
    
}
// retorna verdadeiro se nome1 for menor que nome2
//retorna falso se nome1 for maior que nome2
bool Arquivo::Comparar(char nome1[], char nome2[], int i){
    if(i == 50) return false;
    if(nome1[i] == '\0') return true;
    if(nome2[i] == '\0') return false;
    if(nome1[i] < nome2[i]) return true;
    if(nome1[i] < nome2[i]) return false;
    return Comparar(nome1,nome2, i+1); 
}
bool Arquivo::Comparar(char nome1[], char nome2[]){
    return Comparar(nome1, nome2, 0);
}

