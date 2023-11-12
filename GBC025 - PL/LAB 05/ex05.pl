% retornaElemento(Posição, Elemento, Lista).
retornaElemento(1, Elem, [Elem|_]).
retornaElemento(N, Elem, [_|B]) :-
    N1 is N - 1,
    retornaElemento(N1, Elem, B).
