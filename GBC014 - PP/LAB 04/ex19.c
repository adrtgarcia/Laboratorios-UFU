#include <stdio.h>

int fatorial (int n);

int main ( )
{
    int num;
    printf ("digite o numero: ");
    scanf ("%d", &num);

    printf ("o fatorial de %d eh %d", num, fatorial (num));

    return 0;
}

int fatorial (int n)
{
    int cont, fat = 1;
    
    for (cont = n; cont >= 1; cont--)
    {
        fat *= cont;
    }

    return fat;
}