% dono(nome, carro(tipo, cor, uso)).
dono(jose, carro(onix, azul, passeio)).
dono(maria, carro(civic, prata, passeio)).
dono(carlos, carro(gol, vermelho, trabalho)).
dono(ana, carro(ecosport, preto, passeio)).
dono(pedro, carro(corolla, branco, passeio)).
dono(joao, carro(hilux, cinza, passeio)).
dono(renata, carro(fiesta, azul, trabalho)).
dono(fabiana, carro(celta, prata, trabalho)).
dono(marcos, carro(uno, vermelho, trabalho)).
dono(patricia, carro(fusion, preto, passeio)).

% maria é dona de alguma coisa?
% ?- dono(maria, X).

% joão é dono de quê?
% ?- dono(joao, X).

% quem é dono de um carro preto?
% ?- dono(X, carro(_, preto, _)).

% existe alguém que seja dono de algum carro?
% ?- dono(X, carro(_,_,_)).

% quais são as cores dos carros de trabalho?
% ?- dono(_, carro(_, X, trabalho)).
