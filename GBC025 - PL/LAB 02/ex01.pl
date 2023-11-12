pai(jose, lucio).
pai(joao, luciano).
pai(mario, fabricio).
pai(mario, lucas).

mae(maria, luciano).
mae(ana, lucia).
mae(joana, murilo).

% feliz(X) : X é feliz
feliz(X) :-
    mae(X, _) ; pai(X, _).

% casal(X, Y) : X e Y são um casal
casal(X, Y) :-
    mae(X, Z), pai(Y, Z).
