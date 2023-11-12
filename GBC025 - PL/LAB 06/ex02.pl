% imprimir os valores de 0 até X

imprime(X) :- 
  imprime(X, 0).

imprime(X, X) :- 
  write(X), !.

imprime(X, Y) :- 
  Y < X,
  write(Y),
  Y1 is Y + 1,
  imprime(X, Y1), !.
