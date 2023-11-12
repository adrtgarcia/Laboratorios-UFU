% soma(Lista, Soma).
soma([X], X).
soma([A|B], S) :-
    soma(B, S1),
    S is S1 + A.
