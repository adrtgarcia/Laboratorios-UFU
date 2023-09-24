homem(ivo).
homem(gil).
homem(noé).
homem(ari).
homem(raí).

mulher(ana).
mulher(bia).
mulher(eva).
mulher(clô).
mulher(lia).
mulher(gal).

gerou(ana, eva).
gerou(ivo, eva).
gerou(eva, noé).
gerou(raí, noé).
gerou(bia, raí).
gerou(bia, clô).
gerou(bia, ari).
gerou(gil, raí).
gerou(gil, clô).
gerou(gil, ari).
gerou(ari, gal).
gerou(lia, gal).

pai(X, Y) :- 
    homem(X), gerou(X, Y).

mãe(X, Y) :- 
    mulher(X), gerou(X, Y).

irmãos(X, Y) :-
    gerou(Z, X), gerou(Z, Y), X \= Y.

irmã(X, Y) :- 
    irmãos(X, Y), mulher(X);
    irmãos(Y, X), mulher(X).

irmão(X, Y) :- 
    irmãos(X, Y), homem(X);
    irmãos(Y, X), homem(X).

tio(X, Y) :- 
    irmão(X, Z), gerou(Z, Y).

tia(X, Y) :- 
    irmã(X, Z), gerou(Z, Y).

avô(X, Y) :- 
    pai(X, Z), gerou(Z, Y).

avó(X, Y) :- 
    mãe(X, Z), gerou(Z, Y).