filme('Amnésia', 'Suspense', 'Nolan', 2000, 113).
filme('Babel', 'Drama', 'Innaritu', 2006, 142).
filme('Capote', 'Drama', 'Miller', 2005, 98).
filme('Casablanca', 'Romance', 'Curtiz', 1942, 102).
filme('Matrix', 'Ficção', 'Washowsk', 1999, 136).
filme('Robocco', 'Suspense', 'Hitchcock', 1940, 130).
filme('Shrek', 'Aventura', 'Adamson', 2001, 90).
filme('Superman', 'Aventura', 'Donner', 1997, 143).
filme('Titanic', 'Romance', 'Cameron', 1997, 194).
filme('Tubarão', 'Suspense', 'Spielberg', 1975, 124).
filme('Volver', 'Drama', 'Almodóvar', 2006, 121).
filme('Sinais', 'Ficção', 'Shymalan', 2002, 106).
filme('Spartacus', 'Ação', 'Kubrik', 1960, 184).

diretor(X, Z) :- 
    filme(X, _, Z, _, _).

genero(Y, X) :- 
    filme(X, Y, _, _, _).

dirigiu(Z, X) :- 
    filme(X, _, Z, _, _).

ano(X, W) :- 
    filme(X, _, _, W, _).

duracao(M, X) :- 
    filme(X, _, _, _, V), V < M.

lancamento(A1, A2, X) :- 
    filme(X, _, _, W, _), W >= A1, W <= A2.

classico(X) :- 
    filme(X, _, _, W, _), W < 1980.

classico_genero(Y, X) :- 
    classico(X), genero(Y, X).