livro('Anne de Green Gables', 1908, 'L. M. Montgomery').
livro('Um estudo em vermelho', 1887, 'A. C. Doyle').
livro('Cidades de Papel', 2008,'J. Green').
livro('Arsène Lupin, o ladrão de casaca', 1907, 'M. Leblanc').
livro('Your Name', 2016, 'M. Shinkai').
livro('A Guerra da Papoula', 2018, 'R. F. Kuang').
livro('A vida invisível de Addie LaRue', 2020, 'V. E. Schwab').
livro('Percy Jackson e o ladrão de raios', 2005, 'R. Riordan').
livro('Dom Casmurro', 1899, 'M. Assis').
livro('Memórias Póstumas de Brás Cubas', 1881, 'M. Assis').
livro('O Pequeno Príncipe', 1943, 'A. Saint-Exupéry').
livro('A Culpa é das Estrelas', 2012, 'J. Green').
livro('O Apanhador de Sonhos', 2001, 'S. King').
livro('A Sereia', 2009, 'K. Cass').
livro('Extraordinário', 2012, 'R. J. Palacio').
livro('A Cor Púrpura', 1985, 'A. Walker').
livro('Orgulho e Preconceito', 1813, 'J. Austen').
livro('A Rosa do Povo', 1945, 'C. D. Andrade').
livro('O Alquimista', 1988, 'P. Coelho').
livro('Os Miseráveis', 1862, 'V. Hugo').

% Quais os livros de um determinado autor?
% ?- livro(X, _, 'M. Assis').

% Existe um livro na base publicado em um dado ano?
% ?- livro(X, 2023, _).

% Quais os livros escritos nos anos 2015 e 2023?
% ?- livro(X, Y, _), Y >= 2015, Y < 2023.

% Quais os livros escritos antes de um dado ano?
% ?- livro(X, Y, _), Y < 2020.

% Qual ano um dado título foi publicado?
% ?- livro('Extraordinário', Y, _).
