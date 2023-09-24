estuda(fabricio, programação).
estuda(joana, lógica).
estuda(ana, tcc).
estuda(josé, banco).
estuda(lucas, estrutura).
estuda(nicolas, lógica).
estuda(fernanda, tcc).
estuda(maria, tcc).

aluno(fabricio, ufmg).
aluno(joana, ufu).
aluno(ana, ufu).
aluno(josé, ufu).
aluno(lucas, ufmg).
aluno(nicolas, ufu).
aluno(fernanda, ufu).
aluno(maria, ufu).

professor(joão, programação).
professor(clara, lógica).
professor(roberta, tcc).
professor(antonio, banco).
professor(leandro, estrutura).

reitor(beatriz, ufmg).
reitor(marcos, ufu).

oferta(bcc, programação).
oferta(bcc, lógica).
oferta(si, tcc).
oferta(si, banco).
oferta(bcc, estrutura).

alunos_professor(X, Y) :-
    estuda(X, Z), professor(Y, Z).

alunos_bcc(X) :-
    estuda(X, Z), oferta(bcc, Z).

alunos_si(X) :-
    estuda(X, Z), oferta(si, Z).

alunos_universidade(X, Y) :-
    aluno(X, Y).

disciplinas_professor(X, Y) :-
    professor(Y, X).

professor_universidade(Y, X) :-
    professor(Y, Z), estuda(W, Z), aluno(W, X).

disciplinas_universidade(X, Y) :-
    estuda(Z, X), aluno(Z, Y).

reitor_professor(X, Y) :-
    reitor(X, Z), aluno(W, Z), estuda(W, U), professor(Y, U).