ultimo([X],X).
ultimo([_|Cauda],X) :- ultimo(Cauda, X).