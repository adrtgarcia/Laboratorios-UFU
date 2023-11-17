% LETRA A ----------------------------------------

% progenitor(X, Y) : X é progenitor de Y
progenitor(jose, joao).
progenitor(jose, ana).
progenitor(jose, jessica).
progenitor(jose, lucas).
progenitor(maria, joao).
progenitor(maria, ana).
progenitor(maria, jessica).
progenitor(maria, lucas).
progenitor(joao, mario).
progenitor(ana, helena).
progenitor(ana, joana).
progenitor(jessica, heloisa).
progenitor(lucas, fagundes).
progenitor(lucas, marcia).
progenitor(lucas, julio).
progenitor(mario, carlos).
progenitor(helena, carlos).
progenitor(joana, antonio).
progenitor(joana, juares).
progenitor(marcia, luciano).
progenitor(rodrigo, luciano).


% LETRA B ----------------------------------------

% feminino(X) : X é do sexo feminino
feminino(maria).
feminino(ana).
feminino(jessica).
feminino(helena).
feminino(joana).
feminino(heloisa).
feminino(marcia).

% masculino(X) : X é do sexo masculino
masculino(jose).
masculino(joao).
masculino(lucas).
masculino(mario).
masculino(fagundes).
masculino(julio).
masculino(rodrigo).
masculino(carlos).
masculino(antonio).
masculino(juares).
masculino(luciano).

% irma(X, Y) : X é irmã de Y
irma(X, Y) :-
	feminino(X), progenitor(Z, X), progenitor(Z, Y), X \= Y.

% irmao(X, Y) : X é irmão de Y
irmao(X, Y) :-
	masculino(X), progenitor(Z, X), progenitor(Z, Y), X \= Y.

% descendente(X, Y) : X é descendente de Y
descendente(X, Y) :-
	progenitor(Y, X).
descendente(X, Y) :-
	progenitor(Y, Z), descendente(X, Z).

% mae(X, Y) : X é mãe de Y
mae(X, Y) :-
	feminino(X), progenitor(X, Y).

% pai(X, Y) : X é pai de Y
pai(X, Y) :-
	masculino(X), progenitor(X, Y).

% avô(X, Y) : X é avô de Y
avô(X, Y) :-
	pai(X, Z), (pai(Z, Y) ; mae(Z, Y)).

% tio(X, Y) : X é tio de Y
tio(X, Y) :-
	irmao(X, Z), progenitor(Z, Y).

% primo(X, Y) : X é primo de Y
primo(X, Y) :-
	masculino(X), progenitor(Z, X), (irmao(Z, W) ; irma(Z, W)), progenitor(W, Y).


% LETRA C ----------------------------------------

% (1) joão é filho de josé? 
filho(X, Y) :-
	progenitor(Y, X).
% ?- filho(joao, jose).
% sim.

% (2) quem são os filhos de maria?
% ?- filho(X, maria).
% joão, ana, jéssica, lucas.

% (3) quem são os primos do mário?
primos(X, Y) :-
    progenitor(Z, X), (irmao(Z, W) ; irma(Z, W)), progenitor(W, Y).
% ?- primos(X, mario).
% helena, joana, heloísa, fagundes, márcia, júlio.

% (4) quantos são os sobrinhos/sobrinhas com um tio da família pinheiro?
sobrinhos(T, N) :-
    setof(Sobrinhos, tio(T, Sobrinhos), L),
    length(L, N).
% ?- sobrinhos(joao, N1); sobrinhos(lucas, N2); sobrinhos(mario, N3); sobrinhos(fagundes, N4); sobrinhos(julio, N5).
% joão tem 6, lucas tem 4, mário tem 0, fagundes tem 1 e júlio tem 1.

% (5) quem são os ascendentes do carlos?
ascendente(X, Y) :- 
    progenitor(X, Y).
ascendente(X, Y) :- 
    progenitor(X, Z), ascendente(Z, Y).
% ?- ascendente(X, carlos).
% mario, helena, joão, ana, josé, maria.

% (6) helena tem irmãos?
% ?- irmao(X, helena).
% não.

% (6) helena tem irmãs?
% ?- irma(X, helena).
% sim, joana.

% (7) quem é avô/avó de luciano?
avó(X, Y) :-
    mae(X, Z), (pai(Z, Y) ; mae(Z, Y)).
% ?- avô(X, luciano) ; avó(Y, luciano).
% lucas.

% (8) quem tem netos na família pinheiro?
netos(X, Y) :-
    avô(Y, X) ; avó(Y, X).
% ?- netos(_, Y).
% josé, joão, lucas, maria, ana.
