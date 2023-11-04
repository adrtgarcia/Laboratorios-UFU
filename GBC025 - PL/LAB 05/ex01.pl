% estrada(número, origem, destino).
estrada(1, a, b).
estrada(2, a, d).
estrada(3, b, c).
estrada(4, c, d).
estrada(5, b, e).
estrada(6, c, f).
estrada(7, d, f).
estrada(8, e, f).

% rota(A, B, R).
rota(A, B, estrada(R, A, B)) :-
  estrada(R, A, B).

% rotac(R, A).
rotac(estrada(R, X, A), A) :-
  estrada(R, X, A).

% rotas(R, A).
rotas(estrada(R, A, X), A) :-
  estrada(R, A, X).
