iguais([],[]).
iguais([X|C1],[X|C2]) :- iguais(C1,C2).