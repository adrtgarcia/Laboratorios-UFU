quadrado() :-
    repeat,
    write('Digite um número ("stop" encerra):'), nl,
    read(X),
    (X = 'stop' -> !;
    Y is X*X,
    write('O quadrado é:'),
    write(Y), nl, 
    fail).
