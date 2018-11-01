progenitor(franciscone, junior).
progenitor(debora, junior).
progenitor(franciscone, humberto).
progenitor(debora, humberto).
progenitor(maria, debora).
progenitor(sadi, debora).
progenitor(sadi, bruna).
progenitor(maria, bruna).
progenitor(aparecida, franciscone).
progenitor(sebastiao, franciscone).
progenitor(bruna, eduarda).
progenitor(caio, eduarda).

homem(franciscone).
homem(junior).
homem(humberto).
homem(sadi).
homem(sebastiao).
homem(caio).

mulher(eduarda).
mulher(debora).
mulher(maria).
mulher(aparecida).
mulher(bruna).

descendente(X, Y) :- progenitor(Y, X).

mae(X, Y) :- descendente(Y, X), mulher(X).
pai(X, Y) :- descendente(Y, X), homem(X).

irmao(X, Y) :- progenitor(Z, X), progenitor(Z, Y), homem(X).
irma(X, Y) :- progenitor(Z, X), progenitor(Z, Y), mulher(X).

tia(X, Y) :- mae(Z, Y), irma(Z, X).

primo(X, Y) :- tia(Z, X), progenitor(Z, Y).