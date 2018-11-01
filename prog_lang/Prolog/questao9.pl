contiguo([]) :- false.
contiguo([X,Y|_]) :- X = Y, !.
contiguo([_,B|L]) :- contiguo([B|L]).