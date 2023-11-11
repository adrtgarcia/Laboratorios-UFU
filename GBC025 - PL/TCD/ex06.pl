achaTermo(Termo) :- 
    open('C:/Users/Home/Documents/arq.txt',read,X),
    see(X),
    repeat,
    read(Termo1),
     (Termo1 == end_of_file ->
        write('Termo não encontrado no arquivo.'), nl ;
        (Termo == Termo1 ->
            write(Termo), nl ;
            fail
        )
    ),
    close(X).
