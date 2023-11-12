notas(A, B, C, D, E) :-
    (A > 60 ->  write('aprovado na matéria A'), nl ; true),
    (B > 60 ->  write('aprovado na matéria B'), nl ; true),
    (C > 60 ->  write('aprovado na matéria C'), nl ; true),
    (D > 60 ->  write('aprovado na matéria D'), nl ; true),
    (E > 60 ->  write('aprovado na matéria E'), nl ; true).

media(A, B, C, D, E) :-
    S is A + B + C + D + E,
    M is S/5,
    write('sua média foi: '),
    write(M).

confereAprovacao() :-
    write('digite seu nome:'),
    read(_),
    write('digite sua nota na matéria A:'),
    read(A),
    write('digite sua nota na matéria B:'),
    read(B),
    write('digite sua nota na matéria C:'),
    read(C),
    write('digite sua nota na matéria D:'),
    read(D),
    write('digite sua nota na matéria E:'),
    read(E), nl,
    notas(A, B, C, D, E), nl,
    media(A, B, C, D, E).
