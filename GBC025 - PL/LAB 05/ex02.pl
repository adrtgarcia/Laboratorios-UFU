% tam(Lista, Tamanho).
tam([_], 1).
tam([_|X], N) :-
    tam(X, N1),
    N is N1 + 1.
