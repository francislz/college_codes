/* Defino Y = 1 para X = 0*/
fatorial(0, 1).
/* X1 = X - 1 e Y e a recursao */
fatorial(X, Y) :- X1 is X - 1, fatorial(X1, Y1), Y is X*Y1.