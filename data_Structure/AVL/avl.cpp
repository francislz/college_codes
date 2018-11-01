#include <iostream>
#include <cstdlib>
using namespace std;

typedef int Dado;

class No{
    friend class avl;
    friend int calcAltura(No* umNo);
    friend int calcBal(No* umNo);
    private:
        Dado dado;
        No* esq;
        No* dir;
        No* pai;
        int altura;
    public:
        int fatorBalanceamento();
        No(Dado d = 0);
        ~No();
};

No::No(Dado d){
    dado = d;
    esq = NULL;
    dir = NULL;
    pai = NULL;
    altura = 1;
}

No::~No(){
    delete esq;
    delete dir;
}

int calcAltura(No* umNo){
    if(umNo == NULL)
        return 0;
    else return umNo->altura;
}

int calcBal(No* umNo){
    if(umNo == NULL)
        return 0;
    else return umNo->fatorBalanceamento();
}

int No::fatorBalanceamento(){
    return calcAltura(esq) - calcAltura(dir);
}

class avl{
    private:
        No* raiz;
        No* insereAux(No* umNo, Dado dado);
        No* rotacaoDireita(No* umNo);
        No* rotacaoEsquerda(No* umNo);
        No* arrumaBalanceamento(No* umNo);
        void percorreAux(No* umNo);
    public:
        avl(){raiz = NULL;}
        ~avl() {delete raiz;}
        void insere(Dado d);
        void percorre();
};

void avl::insere(Dado d){
    raiz = insereAux(raiz, d);
}

No* avl::insereAux(No* umNo, Dado dado){
    if(umNo == NULL){
        No* novo = new No(dado);
        return novo;
    }
    
    if(dado < umNo->dado){
        umNo->esq = insereAux(umNo->esq, dado);
        umNo->esq->pai = umNo;
    }
    else if(dado > umNo->dado){
        umNo->dir = insereAux(umNo->dir, dado);
        umNo->dir->pai = umNo;
    }
    else{
        cerr << "Elemento repetido: " << dado << endl;
    }
    
    return arrumaBalanceamento(umNo);
}

No* avl::arrumaBalanceamento(No* umNo){
    umNo->altura = 1 + max(calcAltura(umNo->esq), calcAltura(umNo->dir));
    int bal = umNo->fatorBalanceamento();
    
    if((bal >= -1) and (bal <= 1)){
        return umNo;
    }
    if((bal > 1) and (calcBal(umNo->esq) >= 0)){
        return rotacaoDireita(umNo);
    }
    if((bal > 0) and (calcBal(umNo->esq) < 0)){
        umNo->esq = rotacaoEsquerda(umNo->esq);
        return rotacaoDireita(umNo);
    }
    if((bal < -1) and (calcBal(umNo->dir) <= 0)){
        return rotacaoEsquerda(umNo);
    }
    if((bal < -1) and (calcBal(umNo->dir) > 0)){
        umNo->dir = rotacaoDireita(umNo->dir);
        return rotacaoEsquerda(umNo);
    }
    cerr << "Não deveria chegar aqui" << endl;
    return NULL;
}

No* avl::rotacaoEsquerda(No* umNo){
    No* noAux = umNo->dir;
    umNo->dir = noAux->esq;
    
    if(noAux->esq != NULL){
        noAux->esq->pai = umNo;
    }
    
    noAux->pai = umNo->pai;
    if(umNo->pai != NULL){
        if(umNo == umNo->pai->esq){
            umNo->pai->esq = noAux;
        }
        else{
            umNo->pai->dir = noAux;
        }
    }
    noAux->esq = umNo;
    umNo->pai = noAux;
    
    umNo->altura = 1 + max(calcAltura(umNo->esq), calcAltura(umNo->dir));
    noAux->altura = 1 + max(calcAltura(noAux->esq), calcAltura(noAux->dir));
    
    return noAux;
}

No* avl::rotacaoDireita(No* umNo){
    No* noAux = umNo->esq;
    umNo->esq = noAux->dir;
    
    if(noAux->dir != NULL){
        noAux->dir->pai = umNo;
    }
    
    noAux->pai = umNo->pai;
    
    if(umNo->pai != NULL){
        if(umNo == umNo->pai->esq){
            umNo->pai->esq = noAux;
        }
        else{
            umNo->pai->dir = noAux;
        }
    }
    noAux->dir = umNo;
    umNo->pai = noAux;
    
    umNo->altura = 1 + max(calcAltura(umNo->esq), calcAltura(umNo->dir));
    noAux->altura = 1 + max(calcAltura(noAux->esq), calcAltura(noAux->dir));
    
    return noAux;
}

void avl::percorreAux(No* umNo){
    if(umNo != NULL){
        cout << umNo->dado << " ";
        percorreAux(umNo->esq);
        percorreAux(umNo->dir);
    }
}

void avl::percorre(){
    percorreAux(raiz);
    cout << endl;
}

int main(){
    avl tree;
    tree.insere(100);
    tree.percorre();
    tree.insere(50);
    tree.percorre();
    tree.insere(200);
    tree.percorre();
    tree.insere(70);
    tree.percorre();
    tree.insere(300);
    tree.percorre();
    tree.insere(400);
    tree.percorre();
    return 0;
}
