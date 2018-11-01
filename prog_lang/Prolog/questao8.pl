fatorial(0, 1) :- !. 
fatorial(N, _) :- N < 0, !, false.
fatorial(N, F) :- M is N - 1, fatorial(M, F1), F is F1*N.