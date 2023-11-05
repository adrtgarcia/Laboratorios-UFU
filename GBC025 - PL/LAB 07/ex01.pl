% calcule e imprima o quadrado de x
% condição de parada: "pare"

quadrado() :-
    repeat,
    write('Digite um número ("pare" encerra):'), nl,
    read(X),
    (X = 'pare' -> !;
    Y is X*X,
    write('Seu quadrado é:'),
    write(Y), nl, 
    fail).
