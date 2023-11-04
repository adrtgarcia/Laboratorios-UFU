% max(L, M)
maior([X], X).
maior([A|B], M) :-
    maior(B, MAIOR),
    M is max(A, MAIOR).
