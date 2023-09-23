#include <stdio.h>

int main ( )
{
    int x, y;
    printf ("digite o primeiro numero: ");
    scanf ("%d", &x);
    printf ("digite o segundo numero: ");
    scanf ("%d", &y);

    if (x > y)
    {
        printf ("%d eh o maior numero", x);
    } else {
        if (x < y)
        {
            printf ("%d eh o maior numero", y);
        } else {
            printf ("numeros iguais");
        }
    }
    
    return 0;
}