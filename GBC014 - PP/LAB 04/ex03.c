#include <stdio.h>

int verificar_num (int x);

int main ( )
{
    int num;
    printf ("digite um numero: ");
    scanf ("%d", &num);

    if (verificar_num (num) == 1)
    {
        printf ("1 (numero positivo)");
    } else if (verificar_num (num) == -1)
    {
        printf ("-1 (numero negativo)");
    } else if (verificar_num (num) == 0)
    {
        printf ("0 (numero zero)");
    }

    return 0;
}

int verificar_num (int x)
{
    if (x > 0)
    {
        return 1;
    } else if (x < 0)
    {
        return -1;
    } else return 0;
}