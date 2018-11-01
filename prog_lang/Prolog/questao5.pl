duplica([], []).
duplica([X|Cauda], [X,X|S]) :- duplica(Cauda, S). 