% retiraElemento(Elemento, Lista1, Lista2).

retiraElemento(_, [], []).

retiraElemento(Elem, [Elem|B], L) :-
    retiraElemento(Elem, B, L).

retiraElemento(Elem, [A|B], [A|L]) :-
    Elem \= A,
    retiraElemento(Elem, B, L).
