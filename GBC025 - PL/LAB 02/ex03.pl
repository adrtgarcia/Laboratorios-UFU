% aluno(Nome, Disciplina, Nota).
aluno(ana, calculo, 10).
aluno(joao, logica, 8).
aluno(maria, programacao, 9).
aluno(pedro, programacao, 7).
aluno(carolina, calculo, 9).
aluno(rafael, calculo, 5).
aluno(juliana, logica, 6).
aluno(lucas, calculo, 8).
aluno(beatriz, programacao, 10).
aluno(thiago, calculo, 7).
aluno(isabela, logica, 6).
aluno(bruno, programacao, 5).
aluno(larissa, calculo, 5).
aluno(gabriel, logica, 6).
aluno(renata, calculo, 10).
aluno(marcelo, calculo, 10).
aluno(camila, logica, 9).
aluno(gustavo, programacao, 8).
aluno(vanessa, programacao, 9).
aluno(daniel,  logica, 10).

% professor(Nome, Disciplina, Peso).
professor(fernanda, logica, 2).
professor(marcos, programacao, 3).
professor(aline, calculo, 1).

% nota(NomeAluno, Disciplina, Valor).
nota(Nome, Disciplina, Valor) :-
    aluno(Nome, Disciplina, Nota),
    professor(_, Disciplina, Peso),
    Valor is Nota * Peso / 5.

% maiorNota(Disciplina, NomeAluno).
maiorNota(Disciplina, NomeAluno) :-
    aluno(NomeAluno, Disciplina, N1),
    \+ (aluno(_, Disciplina, N2), N2 > N1).

% menorNota(Disciplina, NomeAluno).
menorNota(Disciplina, NomeAluno) :-
    aluno(NomeAluno, Disciplina, N1),
    \+ (aluno(_, Disciplina, N2), N2 < N1).

% mairNotaGeral(NomeAluno).
maiorNotaGeral(NomeAluno) :-
    aluno(NomeAluno, _, N1),
    \+ (aluno(_, _, N2), N2 > N1).
