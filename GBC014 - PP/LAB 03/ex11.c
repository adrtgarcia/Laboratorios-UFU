#include <stdio.h>

int main ( )
{
    int N, num = 0, cont;
    printf ("digite um numero: ");
    scanf ("%d", &N);

    for (cont = 0; cont < N; cont++)
    {
        printf ("%d  ", num);
        num++;
    }

    return 0;
}