homem(ivo).
homem(gil).
homem(noe).
homem(ari).
homem(rai).

mulher(ana).
mulher(bia).
mulher(eva).
mulher(clo).
mulher(lia).
mulher(gal).

gerou(ana, eva).
gerou(ivo, eva).
gerou(eva, noe).
gerou(rai, noe).
gerou(bia, rai).
gerou(bia, clo).
gerou(bia, ari).
gerou(gil, rai).
gerou(gil, clo).
gerou(gil, ari).
gerou(ari, gal).
gerou(lia, gal).

pai(X, Y) :- 
    homem(X), gerou(X, Y).

mae(X, Y) :- 
    mulher(X), gerou(X, Y).

irmaos(X, Y) :-
    gerou(Z, X), gerou(Z, Y), X \= Y.

irma(X, Y) :- 
    irmaos(X, Y), mulher(X);
    irmaos(Y, X), mulher(X).

irmao(X, Y) :- 
    irmaos(X, Y), homem(X);
    irmaos(Y, X), homem(X).

tio(X, Y) :- 
    irmao(X, Z), gerou(Z, Y).

tia(X, Y) :- 
    irma(X, Z), gerou(Z, Y).

avô(X, Y) :- 
    pai(X, Z), gerou(Z, Y).

avó(X, Y) :- 
    mae(X, Z), gerou(Z, Y).
