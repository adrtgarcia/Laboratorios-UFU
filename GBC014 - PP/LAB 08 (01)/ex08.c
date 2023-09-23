#include <stdio.h>

int main ( )
{
    int num[6];
    int *p = NULL;
    int cont;

    p = num;

    for (cont = 0; cont < 6; cont++)
    {
        printf ("digite o valor de num[%d]: ", cont);
        scanf ("%d", &num[cont]);
    }

    printf ("\nvetor obtido:");
    printf ("\nnum[");
    for (cont = 0; cont < 6; cont++)
    {
        printf (" %d (%p) ", *(p + cont), (p + cont));
    }
    printf ("]");

    return 0;
}