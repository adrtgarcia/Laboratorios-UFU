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
	progenitor(X, Z), progenitor(Z, Y).


% mae(X, Y) : X é mãe de Y

mae(X, Y) :-
	feminino(X), progenitor(X, Y).


% pai(X, Y) : X é pai de Y

pai(X, Y) :-
	masculino(X), progenitor(X, Y).


% avo(X, Y) : X é avô de Y

avo(X, Y) :-
	pai(X, Z), pai(Z, Y).


% tio(X, Y) : X é tio de Y

tio(X, Y) :-
	irmao(X, Z), progenitor(Z, Y).


% primo(X, Y) : X é primo de Y

primo(X, Y) :-
	masculino(X), progenitor(Z, X), (irmao(Z, W) ; irma(Z, W)), progenitor(W, Y).


% LETRA C ----------------------------------------

% joão é filho de josé? 
% sim.
filho(X, Y) :-
	progenitor(Y, X).

% quem são os filhos de maria? 
% joão, ana, jéssica, lucas.
filho(X, Y) :-
	progenitor(Y, X).

% quem são os primos do mário?
% helena, joana, heloísa, fagundes, márcia, júlio.
primo(X, Y) :-
	progenitor(Z, X), (irmao(Z, W) ; irma(Z, W)), progenitor(W, Y).

% quantos são os sobrinhos/sobrinhas com um tio da família pinheiro?
% 
---

% quem são os ascendentes do carlos?
% 
---

% helena tem irmãos?
% não.
irmao(X, Y) :-
	masculino(X), progenitor(Z, X), progenitor(Z, Y), X \= Y.

% helena tem irmãs?
% sim.
irma(X, Y) :-
	feminino(X), progenitor(Z, X), progenitor(Z, Y), X \= Y.

% quem é avô/avó de luciano?
% 
---

% quem tem netos na família pinheiro?
% 
---
