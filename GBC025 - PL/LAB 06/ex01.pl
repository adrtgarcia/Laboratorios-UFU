% último(l)
ultimo([U]) :-
    write(U).

ultimo([_|U]) :-
    ultimo(U).
