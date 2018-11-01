particiona([], [], []).
particiona([X], [X|L1], L2) :- particiona([], L1, L2).
particiona([X,Y|Cauda], [X|L1], [Y|L2]) :- particiona(Cauda, L1, L2).