% fato: caminho(cidade1, cidade2, valor).

caminho(a, b, 5).
caminho(a, c, 10).
caminho(a, f, 5).
caminho(a, g, 75).
caminho(b, e, 25).
caminho(b, f, 25).
caminho(c, d, 10).
caminho(d, e, 5).
caminho(e, f, 5).
caminho(g, f, 20).

% regra: custo(cidade1, cidade2, valor).

custo(C1, C2, V) :-
    caminho(C1, C2, V).

custo(C1, C2, V) :-
    caminho(C1, C3, V1),
    custo(C3, C2, V2),
    V is V1 + V2.