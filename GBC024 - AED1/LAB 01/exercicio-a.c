#include <stdio.h>

int main ( )
{
    printf ("Entre com o valor: ");
    int n;
    scanf ("%d", &n);
    int i, acc = 1;
    for (i = n; i > 0; i--)
        acc = acc * i;
    printf ("O valor do fatorial de %d eh %d", n, acc);

    /*
        a vari�vel "acc", por n�o ter sido inicializada corretamente,
        est� armazenando lixo, o que prejudica no funcionamento correto
        do c�digo. para corrigir o problema, basta declarar a vari�vel como
        acc = 1. dessa forma, o programa funcionar� da maneira esperada.
    */
}
