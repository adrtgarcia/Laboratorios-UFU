% sucessor(X, Y) : X é sucessor de Y.
sucessor(X, Y) :-
    X is Y + 1.

% par(X) : X é par.
par(X) :-
    X > 0,
    X mod 2 =:= 0.

% triplo(X, Y) : X é o triplo de Y.
triplo(X, Y) :-
    X is Y * 3.

% entre(X, A, B) : X está entre A e B.
entre(X, A, B) :-
    X >= A,
    X =< B.
    
