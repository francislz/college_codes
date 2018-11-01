separa([], [], []).
separa([X|Cauda], P, [X|N]) :- separa(Cauda, P, N), X < 0.
separa([X|Cauda], [X|P], N) :- separa(Cauda, P, N), X >= 0.