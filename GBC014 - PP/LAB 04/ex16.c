#include <stdio.h>

void desenha_linha (int x);

int main ( )
{
    int num;
    printf ("digite um numero: ");
    scanf ("%d", &num);
    
    desenha_linha (num);
    return 0;
}

void desenha_linha (int x)
{
    int cont;
    for (cont = 0; cont < x; cont++)
    {
        printf ("=");
    }
}