% pot (base, expoente, potência)

pot(X, 1, X).
pot(_, 0, 1).

pot(B, E, P) :-
    E > 0,
    BB is B * B,
    E1 is E - 1,
    pot(BB, E1, P).