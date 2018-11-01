#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
// #include "memoria.hpp"
using namespace std;

int pow(int base, int expoente){
    int pot = 1;
    for (int i = 0; i < expoente; ++i){
        pot *= base;
    }
    return pot;
}

int log2(int numero){
    int exp = 0;
    while(numero != 1){
        numero /= 2;
        ++exp;
    }
    return exp;
}
/* ====================================================
   ========================CLASSES=====================
   ====================================================
*/
class MainMemory{
    public:
        int ramsize;
        int vmsize;
        int totalSize;
        int* mainMemory;
        MainMemory(int ramsize, int vmsize);
        ~MainMemory();
};

class TACache{
public:
    int capacidade;
    int tamLinha;
    int numLinhas;
    int numBitsOffset;
    int linhaEscrita=0;
    int* diretorio;
    int** tabela;
    TACache(int c, int l);
    ~TACache();
    int getCapacity(){return this->capacidade;}
    int getLineSize(){return this->tamLinha;}
};

class SACache{
public:
    int capacidade;
    int tamLinha;
    int assoc;
    int numConjuntos;
    int numBitsOffset;
    TACache** conjuntos;
    SACache(int c, int a, int l);
    ~SACache();
    int getCapacity(){return this->capacidade;}
    int getLineSize(){return this->tamLinha;}
};

class Cache{
public:
    SACache *l1d;
    SACache *l1i;
    SACache *l2;
    SACache *l3;
    Cache(SACache *l1d, SACache *l1i, SACache *l2, SACache *l3);
    ~Cache();
};

class Memory{
    public:
        Cache *c;
        MainMemory *mainM;
        Memory(Cache *c, MainMemory *mem);
};

class Processor{
public:
    int ncores;
    Memory** memoria;
    Processor(int ncores, Memory* memoria);
};

/* ====================================================
   ==================FUNCOES MAINMEM===================
   ====================================================
*/
MainMemory::MainMemory(int ramsize, int vmsize){
    this->ramsize = ramsize;
    this->vmsize = vmsize;
    this->totalSize = ramsize + vmsize;

    this->mainMemory = new int[totalSize/4];
}

MainMemory::~MainMemory(){delete[] mainMemory;}

static MainMemory* createMainMemory(int ramsize, int vmsize){return new MainMemory(ramsize, vmsize);}

int getMainMemoryData(MainMemory *mem, int address, int *value){
    if((address/4) >= mem->totalSize){
        return -1;
    }
    else{
        *value = mem->mainMemory[address/4];
        return 4;
    }
}

void setMainMemoryData(MainMemory *mem, int address, int *value){
    if((address/4) < mem->totalSize){
        mem->mainMemory[address/4] = *value;
    }
}

/* ====================================================
   ==================FUNCOES TACACHE===================
   ====================================================
*/
TACache::TACache(int c = 0, int l = 0){
    //atribuicao da capacidade total do cache
    this->capacidade = c;
    //quantidades de bytes por linha do cache
    this->tamLinha = l;
    //A capacidade total dividida pela quantidade de bytes por linha resulta no numero de linhas
    this->numLinhas = this->capacidade/this->tamLinha;
    this->numBitsOffset = log2(this->tamLinha);
    //O numero de bits de offset e dado pelo logaritmo do tamanho do bloco

    diretorio = new int [numLinhas];
    for (int i = 0; i < numLinhas; ++i){
        diretorio[i] = -1;
    }
    tabela = new int*[numLinhas];
    for (int i = 0; i < numLinhas; i++){
        this->tabela[i] = new int[l];
    }
}

TACache::~TACache(){
    delete[] diretorio;
    for (int i = 0; i < numLinhas; i++){
        delete[] tabela [i];
    }
    delete[] tabela;
}

//Funcoes de acesso ao TACache fora da classe principal
//Cria um TACache
static TACache* createTACache(int c, int l){return new TACache(c, l);}
//Retorna a capacidade do TACache
int getTACacheCapacity(TACache* tac){return tac->getCapacity();}

//Retorna o tamanho da linha do TACache
int getTACacheLineSize(TACache* tac){return tac->getLineSize();}

bool getTACacheData(TACache *tac, int address, int* value){

    int offset = address & (tac->tamLinha - 1);
    int tag = address >> tac->numBitsOffset;
    tag = tag & (pow(2, (32 - tac->numBitsOffset)) - 1);

    bool hit = false;
    for (int i = 0; i < tac->numLinhas and (not hit); ++i){
        if(tac->diretorio[i] == tag){
            *value = tac->tabela[i][offset/4];
            hit = true;
        } 
    }
    return hit;
}

bool setTACacheData(TACache* tac, int address, int value){
    //Pegando os bits de offset
    int offset = address & (tac->tamLinha - 1);
    //Pegando os bits de tag
    int tag = address >> tac->numBitsOffset;
    tag = tag & (pow(2, (32 - tac->numBitsOffset)) - 1);

    bool hit = false;
    for (int i = 0; i < tac->numLinhas and (not hit); ++i){
        if(tac->diretorio[i] == tag){
            tac->tabela[i][offset/4] = value;
            hit = true;
        } 
    }
    return hit;
}

void setTACacheLine(TACache* tac, int address, int* line){

    int tag = address >> tac->numBitsOffset;

    int linha = -1;
    for (int i = 0; i < tac->numLinhas; ++i){
        if(tac->diretorio[i] == tag){
            linha = i;
            break;
        } 
    }

    if(linha <  0) {
        linha = tac->linhaEscrita;
        tac->linhaEscrita = (tac->linhaEscrita + 1) % tac->numLinhas;
    }

    memcpy(tac->tabela[linha],line,tac->tamLinha);
}

/* ====================================================
   ==================FUNCOES SACACHE===================
   ====================================================
*/
SACache::SACache(int c, int a, int l){
    //atribuicao da capacidade total do cache
    this->capacidade = c;
    this->assoc = a;
    //Atribuicao da qunatidade de conjuntos.
    this->numConjuntos = c / (l * a);
    this->numBitsOffset = log2(this->capacidade/(this->numConjuntos * this->assoc));
    //quantidades de bytes por linha do cache
    this->tamLinha = l;
    //this->numBitsOffset = log2(this->numLinhas);
    //O numero de bits de offset e dado pelo logaritmo do tamanho do bloco

    conjuntos = new TACache*[numConjuntos]();
    for (int i = 0; i < numConjuntos; i++){
        this->conjuntos[i] = createTACache(c, l);
    }
}

SACache::~SACache(){delete[] conjuntos;}

//Funcoes SACache
static SACache* createSACache(int c, int a, int l){return new SACache(c, a, l);}

int getSACacheCapacity(SACache* sac){return sac->getCapacity();}

int getSACacheLineSize(SACache* sac){return sac->getLineSize();}

bool getSACacheData(SACache* sac, int address, int* value){
    //Operacoes bit a bit para o calculo do valor do lookup
    int lookup = address >> sac->numBitsOffset;
    lookup = lookup & (sac->numConjuntos - 1);

    return getTACacheData(sac->conjuntos[lookup], address, value);
}

bool setSACacheData(SACache* sac, int address, int value){
    //Operacoes bit a bit para o calculo do valor do lookup
    int lookup = address >> sac->numBitsOffset;
    lookup = lookup & (sac->numConjuntos - 1);

    return setTACacheData(sac->conjuntos[lookup], address, value);
}

void setSACacheLine(SACache* sac, int address, int* line){

    int lookup = address >> sac->numBitsOffset;
    lookup = lookup & (sac->numConjuntos - 1);
    setTACacheLine(sac->conjuntos[lookup], address, line); 
}

static SACache* duplicateSACache(SACache* sac){
    SACache *duplicado = new SACache(sac->capacidade, sac->assoc, sac->tamLinha);
    for (int i = 0; i < sac->numConjuntos; i++){
        duplicado->conjuntos[i] = createTACache(sac->assoc*sac->tamLinha, sac->tamLinha);
    }
    return duplicado;
}

/* 
   ====================================================
   =======================CACHE========================
   ====================================================
*/
Cache::Cache(SACache *l1d, SACache *l1i, SACache *l2, SACache *l3){
    this->l1d = l1d;
    this->l1i = l1i;
    this->l2 = l2;
    this->l3 = l3;
}

Cache::~Cache(){}

static Cache* createCache(SACache *l1d, SACache *l1i, SACache *l2, SACache *l3){
    return new Cache(l1d, l1i, l2, l3);
}

void fetchCacheData(Cache *c, MainMemory *mmem, int address){
    //Encontra o complemento de dois do tamanho da linha de cada cache
    //Faz um and bit a bit com o address para encontrar o endereço em cada cache.
    int addressIl1 = address & (-getSACacheLineSize(c->l1d));
    int addressIl2 = address & (-getSACacheLineSize(c->l2));
    int addressIl3 = address & (-getSACacheLineSize(c->l3));
    int* linel1 = &mmem->mainMemory[addressIl1/4];
    int* linel2 = &mmem->mainMemory[addressIl2/4];
    int* linel3 = &mmem->mainMemory[addressIl3/4];
    setSACacheLine(c->l1d, address, linel1);
    setSACacheLine(c->l2, address, linel2);
    setSACacheLine(c->l3, address, linel3);
}

void fetchCacheInstruction(Cache *c, MainMemory *mmem, int address){
    //Encontra o complemento de dois do tamanho da linha de cada cache
    //Faz um and bit a bit com o address para encontrar o endereço em cada cache.
    int addressIl1 = address & (-getSACacheLineSize(c->l1d));
    int addressIl2 = address & (-getSACacheLineSize(c->l2));
    int addressIl3 = address & (-getSACacheLineSize(c->l3));
    int* linel1 = &mmem->mainMemory[addressIl1];
    int* linel2 = &mmem->mainMemory[addressIl2];
    int* linel3 = &mmem->mainMemory[addressIl3];
    setSACacheLine(c->l1d, address, linel1);
    setSACacheLine(c->l2, address, linel2);
    setSACacheLine(c->l3, address, linel3);    
}

int getCacheData(Cache *c, MainMemory *mmem, int address, int *value){
    int ret = 1;
    if(getSACacheData(c->l1d, address, value)){
        return 1;
    }
    else if((getSACacheData(c->l2, address, value))){
        ret = 2;
    }
    else if(getSACacheData(c->l3, address, value)){
        ret = 3;
    }
    else{
        ret = getMainMemoryData(mmem, address, value);
    }

    if(ret > 0){ //Se o address for valido
        fetchCacheData(c, mmem, address);
    }
    return ret;
}

int getCacheIntruction(Cache *c, MainMemory *mmem, int address, int *value){
    int ret = 1;
    if(getSACacheData(c->l1i, address, value)){
        return 1;
    }
    else if(getSACacheData(c->l2, address, value)) {
        ret = 2;
    }
    else if(getSACacheData(c->l3, address, value)) {
        ret = 3;
    }
    else{
        ret = getMainMemoryData(mmem, address, value);
    }
    
    if (ret > 0) { // Se o address for valido
        fetchCacheInstruction(c, mmem, address);
    }
    return ret;
}

void setCacheData(Cache *c, MainMemory *mmem, int address, int value){
    int ret = 0;
    if(getSACacheData(c->l1d, address, &value)){
        ret = 1;
    }
    else if(getSACacheData(c->l2, address, &value)){
        ret = 2;
    }
    else if(getSACacheData(c->l3, address, &value)){
        ret = 3;
    }
    else{
        ret = getMainMemoryData(mmem, address, &value);
    }
    if(ret > 0){
        fetchCacheData(c, mmem, address);
    }
    setSACacheData(c->l1d, address, value);
    setSACacheData(c->l2, address, value);
    setSACacheData(c->l3, address, value);
    setMainMemoryData(mmem, address, &value);
}

void setCacheInstruction(Cache *c, MainMemory *mmem, int address, int value){
    int ret = 1;
    if (getSACacheData(c->l1i, address, &value)){
        ret = 1;
    }
    else if(getSACacheData(c->l2, address, &value)){
        ret = 2;
    }
    else if(getSACacheData(c->l3, address, &value)) {
        ret = 3;
    }
    else{
        ret = getMainMemoryData(mmem, address, &value);
    }
    
    if(ret > 0) { // for valid adress
        fetchCacheData(c, mmem, address);
    }
    setSACacheData(c->l1i, address, value);
    setSACacheData(c->l2, address, value);  
    setSACacheData(c->l3, address, value);
    setMainMemoryData(mmem, address, &value);
}

Cache* duplicateCache(Cache *c) {
    SACache* l1d = duplicateSACache(c->l1d);
    SACache* l1i = duplicateSACache(c->l1i);
    SACache* l2 = duplicateSACache(c->l2);
    SACache* l3 = c->l3;
    return createCache(l1d, l1i, l2, l3);
}

/* 
   ====================================================
   =============HIERARQUIA DE MEMORIA==================
   ====================================================
*/
Memory::Memory(Cache *c = NULL, MainMemory *mem = NULL){
    this->c = c;
    this->mainM = mem;
}

static Memory* createMemory(Cache *c, MainMemory *mem){return new Memory(c, mem);}

int getData(Memory *mem, int address, int *value){
    if ((address >= 0) and (address < (mem->mainM->ramsize + mem->mainM->vmsize))){
        return getCacheData(mem->c, mem->mainM, address, value);
    }
    return -1;
}

int getInstruction(Memory *mem, int address, int *value){
    if ((address >= 0) and (address < (mem->mainM->ramsize + mem->mainM->vmsize))){
        return getCacheIntruction(mem->c, mem->mainM, address, value);
    }
    return -1;
}

void setData(Memory *mem, int address, int value){
    setCacheData(mem->c, mem->mainM, address, value);
}

void setInstruction(Memory *mem, int address, int value){
    setCacheInstruction(mem->c, mem->mainM, address, value);
}

Memory* duplicateMemory(Memory *mem){
    return new Memory(duplicateCache(mem->c), mem->mainM);
}

/* 
   ====================================================
   =====================PROCESSADOR====================
   ====================================================
*/
Processor::Processor(int ncores, Memory *mem) {
    this->ncores = ncores;
    this->memoria = new Memory*[ncores]();

    for (int i = 0; i < ncores; ++i){
        this->memoria[i] = duplicateMemory(mem);
    }
}

static Processor* createProcessor(Memory *mem, int ncores){return new Processor(ncores, mem);}

/* ====================================================
   =====================PRINCIPAL======================
   ====================================================
*/

 
int main(int argv, const char* args[]){
    int NUM_HITS = 0;
    SACache *l1d, *l1i, *l2, *l3;
    MainMemory *mmem;
    Memory *mem;
    Cache *c;
    Processor *proc;

    ifstream arq(args[1]);
    string comando;

    int i = 0;
    while(i < 10){
        arq >> comando;
        cout << comando << endl;
        if(comando == "cl1d"){
            cout << "1" << endl;
            int c, a, l;
            arq >> c  >>  a >> l;
            l1d = createSACache(c,a,l);
            //tratar erro, se ocorrer
        }
        else if(comando == "cl1i"){
            cout << "2" << endl;
            int c, a, l;
            arq >> c  >>  a >> l;
            l1i = createSACache(c,a,l);
            //tratar erro, se ocorrer
        }
        else if(comando == "cl2"){
            cout << "3" << endl;
            int c, a, l;
            arq >> c  >>  a >> l;
            l2 = createSACache(c,a,l);
            //tratar erro, se ocorrer
        }
        else if(comando == "cl3"){
            cout << "4" << endl;
            int c, a, l;
            arq >> c  >>  a >> l;
            l3 = createSACache(c,a,l);
            //tratar erro, se ocorrer
        }
        else if(comando == "cmp"){
            cout << "5" << endl;
            int ramsize, vmsize;
            arq >> ramsize >> vmsize;
            mmem = createMainMemory(ramsize,vmsize);
        }
        else if(comando == "cmem"){
            cout << "6" << endl;
            c = createCache(l1d, l1i, l2, l3);
            mem = createMemory(c,mmem);
        }
        else if(comando == "cp"){
            cout << "7" << endl;
            int nnucleos;
            arq >> nnucleos;
            proc = createProcessor(mem,nnucleos);
        }
        else if(comando == "wi"){
            cout << "8" << endl;
            int n, addr, value;
            arq >> n >> addr >> value;
            setInstruction(proc->memoria[n], addr, value);
        }
        else if(comando == "ri"){
            cout << "9" << endl;
            int n, addr, *value;
            arq >> n >> addr;
            if(getInstruction(proc->memoria[n], addr, value)){
                NUM_HITS++;
            }
        }
        else if(comando == "wd"){
            cout << "10" << endl;
            int n, addr, value;
            arq >> n >> addr >> value;
            setData(proc->memoria[n], addr, value);
        }
        else if(comando == "rd"){
            cout << "11" << endl;
            int n, addr, *value;
            arq >> n >> addr;
            if(getData(proc->memoria[n], addr, value)){
                NUM_HITS++;
            }
        }
        ++i;
        cout << NUM_HITS << endl;
    }
}
