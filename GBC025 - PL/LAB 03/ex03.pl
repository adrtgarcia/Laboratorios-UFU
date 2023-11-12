% mdc (num1, num2, resultado)

mdc(X, X, X).

mdc(X, Y, Z) :-
    X > Y,
    X1 is X - 1,
    mdc(X1, Y, Z).

mdc(X, Y, Z) :-
    X < Y,
    mdc(Y, X, Z).
