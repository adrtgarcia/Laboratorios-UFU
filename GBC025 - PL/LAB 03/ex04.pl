% soma dos n primeiro números: s(num, resultado).

s(1, 1).

s(N, X) :-
    N1 is N - 1,
    s(N1, X1),
    X is X1 + N.
