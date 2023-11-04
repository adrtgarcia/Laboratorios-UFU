% retiraElemento(Elem, L1, L2)

retiraElemento(_, [], []).

retiraElemento(Elem, [Elem|B], L) :-
    retiraElemento(Elem, B, L).

retiraElemento(Elem, [A|B], [A|L]) :-
    Elem \= A,
    retiraElemento(Elem, B, L).
