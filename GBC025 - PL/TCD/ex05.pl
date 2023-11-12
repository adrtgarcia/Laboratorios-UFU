% LETRA A ----------------------------------------

% estrada(identificador, origem, destino, custo).
estrada(a, cidadeB, cidadeA, 150).
estrada(b, cidadeA, cidadeB, 90).
estrada(c, cidadeB, cidadeC, 211).
estrada(d, cidadeG, cidadeA, 300).
estrada(e, cidadeB, cidadeD, 50).
estrada(f, cidadeB, cidadeE, 89).
estrada(g, cidadeA, cidadeG, 187).
estrada(h, cidadeD, cidadeH, 254).
estrada(i, cidadeF, cidadeI, 621).
estrada(j, cidadeC, cidadeJ, 300).
estrada(k, cidadeI, cidadeJ, 41).
estrada(l, cidadeD, cidadeL, 99).
estrada(m, cidadeH, cidadeM, 148).
estrada(n, cidadeP1, cidadeM, 163).
estrada(o, cidadeP1, cidadeN, 69).
estrada(p, cidadeP2, cidadeL, 10).
estrada(q, cidadeJ, cidadeL, 364).
estrada(r, cidadeR, cidadeL, 79).
estrada(s, cidadeL, cidadeO, 193).
estrada(t, cidadeP2, cidadeP1, 311).
estrada(u, cidadeP2, cidadeR, 577).
estrada(v, cidadeN, cidadeP1, 150).
estrada(x, cidadeA, cidadeD, 100).
estrada(semId, cidadeL, cidadeN, 0).


% LETRA B ----------------------------------------

rota(A, B, estrada(R, A, B, C), C) :-
    estrada(R, A, B, C).

rota(A, B, [estrada(R, A, Intermediario, C1) | L], C) :-
    estrada(R, A, Intermediario, C1),
    rota(Intermediario, B, L, C2),
    C is C1 + C2.


% LETRA C ----------------------------------------

rotaC([estrada(R, _, A, C)], A, C) :-
    estrada(R, _, A, C).


% LETRA D ----------------------------------------

rotaS([estrada(R, A, _, C)], A, C) :-
    estrada(R, A, _, C).


% LETRA E ----------------------------------------

rotaM([estrada(R, _, B, M)], B, C) :-
    estrada(R, _, B, M),
    M < C.
