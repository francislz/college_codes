soma([], 0).
soma([X|L], R) :- soma(L, A), R is (A + X).