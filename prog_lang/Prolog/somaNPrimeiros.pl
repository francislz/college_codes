s(1,1).
s(N, S) :- N > 1, Aux is (N - 1), write('*'), s(Aux, Parcial), S is (N + Parcial).