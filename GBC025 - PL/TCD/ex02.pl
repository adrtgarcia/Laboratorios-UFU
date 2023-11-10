% LETRA A ----------------------------------------
% L2 é a lista L1 com o elemento X

adiciona(X, L1, [X|L1]).


% LETRA B ----------------------------------------
% L2 é a lista L1 sem o elemento X

apaga(X, [X|L], L).
apaga(X, [Y|L1], [Y|L2]) :-
    apaga(X, L1, L2).


% LETRA C ----------------------------------------
% TRUE se X pertencer à lista L

membro(X, [X|_]).
membro(X,[_|L]) :-
    membro(X, L).


% LETRA D ----------------------------------------
% L3 é a junção das listas L1 e L2

concatena([], L, L).
concatena([X|L1], L2, [X|L3]) :-
    concatena(L1, L2, L3).


% LETRA E ----------------------------------------
% X é o número de elementos da lista L

comprimento(0, []).
comprimento(X, [_|L]) :-
    comprimento(X1, L),
    X is X1 + 1.


% LETRA F ----------------------------------------
% X é o valor máximo da lista L

max(X,[X]).
max(X,[Y|R]) :- 
    max(X,R), 
    X > Y, !.
max(Y,[Y|_]).


% LETRA G ----------------------------------------
% X é o valor médio da lista L

somaElementos(0, []).
somaElementos(X, [Y|L]) :-
    somaElementos(S, L),
    X is S + Y.

contElementos(0, []).
contElementos(X, [_|L]) :-
    contElementos(X1, L),
    X is X1 + 1.

media(X, L) :-
    somaElementos(S, L),
    contElementos(C, L),
    X is S/C.


% LETRA H ----------------------------------------
% diz se a lista L está ordenada (ascendentemente).

ordenada([]).
ordenada([_]).
ordenada([X, Y|L]) :-
    X =< Y,
    ordenada([Y|L]).
