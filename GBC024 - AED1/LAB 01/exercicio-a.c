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
        a variável "acc", por não ter sido inicializada corretamente,
        está armazenando lixo, o que prejudica no funcionamento correto
        do código. para corrigir o problema, basta declarar a variável como
        acc = 1. dessa forma, o programa funcionará da maneira esperada.
    */
}
