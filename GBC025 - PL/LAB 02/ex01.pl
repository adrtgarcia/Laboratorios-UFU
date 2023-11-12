% pai(X, Y) : X é pai de Y
pai(jose, lucio).
pai(joao, luciano).
pai(mario, fabricio).
pai(mario, lucas).

% mae(X, Y) : X é mãe de Y
mae(maria, luciano).
mae(ana, lucia).
mae(joana, murilo).

% feliz(X) : X é feliz
feliz(X) :-
    mae(X, _) ; pai(X, _).

% casal(X, Y) : X e Y são um casal
casal(X, Y) :-
    mae(X, Z), pai(Y, Z).
