:- dynamic(contador_cliente/1). %Aridade 1 pra guardar o numero.

relatorio :-
    open('C:/Users/Home/Desktop/arq1.txt', read, X),
    open('C:/Users/Home/Desktop/arq2.txt', write, Y),
    retractall(contador_cliente(_)),
    assertz(contador_cliente(001)),
    repeat,
    ler_cliente(X,N,E,T),
    (N == end_of_file -> ! ;
        escrever_cliente(Y,N,E,T),
        incrementar_contador,
        fail
    ),
    close(X),
    close(Y).

%Separei por ter dado muitos erros leitura e escrita na mesma regra.
ler_cliente(Entrada,N,E,T) :-
    set_input(Entrada),
    read(N),
    read(E),
    read(T),
    set_input(user).

escrever_cliente(Saida,N,E,T) :-
    set_output(Saida),
    contador_cliente(Num),
    write(Num),
    write(' '),
    write(N),
    write(' '),
    write(E),
    write(' '),
    write(T),
    write('\r\n'),
    set_output(user).

incrementar_contador :-
    retract(contador_cliente(Num)),
    NovoNum is Num+1,
    assertz(contador_cliente(NovoNum)).
