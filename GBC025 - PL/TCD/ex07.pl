achaTodos(Termo) :- 
    open('C:/Users/Home/Documents/arq.txt',read,X),
    see(X),
    repeat,
    read(Termo1),
     (Termo1 == end_of_file ->
        write('Fim do arquivo.'), nl ;
        (Termo == Termo1 ->
            write(Termo1), nl,
            fail ;
            fail
        )
    ),
    close(X).
    
