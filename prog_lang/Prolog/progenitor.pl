progenitor(sara, isaque).
progenitor(abraao, isaque).
progenitor(abraao, ismael).
progenitor(abraao, manuela).
progenitor(isaque, esau).
progenitor(isaque, jaco).
progenitor(jaco, jose).
mulher(sara).
mulher(manuela).
homem(isaque).
homem(abraao).
homem(ismael).
homem(esau).
homem(jaco).
homem(jose).

filho_geral(Y, X) :- progenitor(X, Y).
mae(X, Y) :- progenitor(X, Y), mulher(X).
avo_geral(X, Z) :- progenitor(X, Y), progenitor(Y, Z).

/* Para saber se um valor que satisfaz a uma condicao e so fazer homem(X). assim serao retornados */
/* odos os valores que atendem a condicao */
