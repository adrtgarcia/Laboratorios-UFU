#include <stdio.h>

int maior (int a, int b);

int main ( )
{
    int num1, num2;
    printf ("digite o primeiro numero: ");
    scanf ("%d", &num1);
    printf ("digite o segundo numero: ");
    scanf ("%d", &num2);

    if (num1 == num2)
    {
        printf ("os numeros sao iguais");
    } else printf ("o maior numero eh: %d", maior (num1, num2));

    return 0;
}

int maior (int a, int b)
{
    if (a > b) {
        return a;
    } else if (b > a) {
        return b;
    }
}