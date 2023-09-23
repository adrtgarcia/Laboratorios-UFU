#include <stdio.h>

int main ( )
{
    char operador;
    int n1, n2;

    do
    {
        printf ("escolha um operador aritmetico: ");
        scanf (" %c", &operador);

        if ((operador != '+') && (operador != '-') && (operador != 'x') && (operador != 'X') && (operador != '*') && (operador != '/'))
        {
            printf ("operador invalido\n\n");
        }
    } while ((operador != '+') && (operador != '-') && (operador != 'x') && (operador != 'X') && (operador != '*') && (operador != '/'));

    printf ("digite o primeiro numero: ");
    scanf ("%d", &n1);

    do
    {
        printf ("digite o segundo numero: ");
        scanf ("%d", &n2);

        if ((operador == '/') && (n2 == 0))
        {
            printf ("\no segundo numero nao pode ser 0\n");
        }
    } while ((operador == '/') && (n2 == 0));

    if (operador == '+')
    {
        printf ("%d + %d = %d", n1, n2, (n1 + n2));
    } else if (operador == '-')
    {
        printf ("%d - %d = %d", n1, n2, (n1 - n2));
    } else if ((operador == 'x') || (operador == 'X') || (operador == '*'))
    {
        printf ("%d x %d = %d", n1, n2, (n1 * n2));
    } else {
        printf ("%d / %d = %d", n1, n2, (n1 / n2));
    }

    return 0;
}
