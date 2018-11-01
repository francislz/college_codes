/* Exemplo Basico. Regras e fatos terminam com .*/
humano(socrates).
humano(aristoteles).
humano(platao).
deus(apolo).
deus(zeus).
mortal(X) :- humano(X).