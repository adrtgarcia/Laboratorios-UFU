% livro(nome('Nome'), autor('Autor'), pal_chave([palavraschave])).
livro(nome('C completo e total'), autor('Schildt'), pal_chave([linguagemc, programacao, computacao])).
livro(nome('Introdução à Linguagem C'), autor('Kernighan'), pal_chave([linguagemc, programacao, linguagem])).
livro(nome('Algoritmos e Estruturas de Dados em C'), autor('Drozdek'), pal_chave([linguagemc, programacao, estruturasdedados])).
livro(nome('A Arte de Programar'), autor('Knuth'), pal_chave([algoritmos, programacao, computacao])).
livro(nome('Aprenda Computação com Python'), autor('Shaw'), pal_chave([python, programacao, computacao])).
livro(nome('Estrutura de Dados e Algoritmos em Python'), autor('Goodrich'), pal_chave([python, estruturasdedados, algoritmos])).
livro(nome('Programação em Java'), autor('Deitel'), pal_chave([java, programacao, linguagem])).
livro(nome('Banco de Dados: Projeto e Implementação'), autor('Elmasri'), pal_chave([bancodedados, database, modelagem])).
livro(nome('Inteligência Artificial: Uma Abordagem Moderna'), autor('Russell'), pal_chave([inteligenciaartificial, machinelearning, algoritmos])).
livro(nome('Redes de Computadores'), autor('Tanenbaum'), pal_chave([redes, computacao, protocolos])).

% encontre o nome do autor, dado o nome do livro
% ?- livro(nome('C completo e total'), autor(X), _).

% encontre o nome do livro, dado o nome do autor
% ?- livro(nome(X), autor('Schildt'), _).

% encontre as palavras-chave, dado o nome do livro
% ?- livro(nome('C completo e total'), _, pal_chave(X)).

% encontre o nome do autor e o nome do livro, dada uma palavra-chave

verifica(PalavraChave, [PalavraChave|_]).

verifica(PalavraChave, [_|Tail]) :-
    verifica(PalavraChave, Tail).

busca_palavrachave(PalavraChave, Autor, Nome) :-
    livro(nome(Nome), autor(Autor), pal_chave(ListaPC)),
    verifica(PalavraChave, ListaPC).

% encontre livros que têm pelo menos uma das palavras-chave fornecidas

busca_palavrachave(ListaPC, Nome, Autor) :-
    livro(nome(Nome), autor(Autor), pal_chave(PCs),
    comum(ListaPC, PCs).

comum([Palavra|_], PCs) :-
    member(Palavra, PCs).

comum([_|Tail], PCs) :-
    comum(Tail, PCs).
