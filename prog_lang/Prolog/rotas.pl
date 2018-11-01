/* achando rotas */
ligado(a, b, 5).
ligado(a, c, 10).
ligado(a, g, 75).
ligado(c, d, 10).
ligado(d, g, 15).
ligado(d, e, 5).
ligado(g, f, 20).
ligado(e, f, 5).
ligado(b,f, 25).
ligado(b, e, 5).

rota(X, Y, C) :- ligado(X, Y, C).
rota(X, Y, C) :- ligado(X, Z, C1), rota(Z, Y, C2), C is (C1 + C2).