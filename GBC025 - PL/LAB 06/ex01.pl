% último(Lista).
ultimo([U]) :-
    write(U).

ultimo([_|U]) :-
    ultimo(U).
