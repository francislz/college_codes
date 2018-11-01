insereOrdenado([], A, [A]).
insereOrdenado([X|L], A, [N, X|L]) :- X > A, N is A, !.
insereOrdenado([X|L], A, [N|LO]) :- insereOrdenado(L, A, LO), X < A, N is X. 