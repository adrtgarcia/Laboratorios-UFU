#include <stdio.h>

int main ( )
{
   int saque, nota, tipo [] = {100, 50, 20, 10, 5, 2, 1}, cont;
   printf ("digite o valor do saque: R$ ");
   scanf ("%d", &saque);

   for (cont = 0; cont < 7; cont++)
   {
    nota = saque/tipo[cont];
    saque %= tipo[cont];
    if (nota == 0)
    {
        continue;
    } else printf ("\n%d notas de R$ %d", nota, tipo[cont]);
   }
   
    return 0;
}