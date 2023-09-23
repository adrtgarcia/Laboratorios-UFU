#include <stdio.h>

int operacoes (int a, int b, char x);

int main ( )
{
    int num1, num2;
    char operador;

    do
    {   
        printf ("digite o primeiro numero: ");
        scanf ("%d", &num1);
        printf ("digite o segundo numero: ");
        scanf ("%d", &num2);
        printf ("escolha o operador: ");
        scanf (" %c", &operador);

        if ((operador != '+') && (operador != '-') && (operador != '*') && (operador != '/'))
        {
            printf ("\noperador invalido\n\n");
        }

    } while ((operador != '+') && (operador != '-') && (operador != '*') && (operador != '/'));

    printf ("resultado: %d", operacoes (num1, num2, operador));

    return 0;
}

int operacoes (int a, int b, char x)
{
    if (x == '+')
    {
        return a+b;
    } else if (x == '-')
    {
        return a-b;
    } else if (x == '*')
    {
        return a*b;
    } else if (x == '/')
    {
        return a/b;
    }
}