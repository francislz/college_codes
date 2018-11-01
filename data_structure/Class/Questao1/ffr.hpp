#ifndef FFR_HPP
#define FFR_HPP

enum tipo {fib, fet, ric};

class FFR {
    private:
        tipo meuTipo;
        int termo1, termo2;
        long calculaFib (int n);
        long calculaFet (int n);
        long calculaRic (int n);
        long* calculaSeqFib (int n, long* vet);
        long* calculaSeqFet (int n, long* vet);
        long* calculaSeqRic (int n, long* vet);
    public:
        FFR (tipo t); // construtor para Fibonacci
        FFR (tipo t, int t1, int t2); // construtor para Fettuccine e Ricci
        long calculaTermo (int n); //calcula o n-esimo termo
        long* calculaSequencia (int n); // retorna um vetor com os n primeiros termos
};
#endif
