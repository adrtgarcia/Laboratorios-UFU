#include <stdio.h>

void potenciacao (int base, int expoente);

int main ( )
{
    int n1, n2;

    printf ("digite o primeiro numero: ");
    scanf ("%d", &n1);

    printf ("digite o segundo numero: ");
    scanf ("%d", &n2);

    potenciacao (n1, n2);

    return 0;
}

void potenciacao (int base, int expoente)
{
    int resultado, i;

    if (base == 0)
    {
        printf ("0 elevado a %d eh 0", expoente);
    } else if (expoente > 0)
    {
        for (i = 1, resultado = base; i < expoente; i++)
        {
            resultado *= base;
        }
        printf ("%d elevado a %d eh %d", base, expoente, resultado);
    } else if (expoente == 0)
    {
        printf ("%d elevado a 0 eh 1", base);
    } else if (expoente < 0)
    {
        for (i = 1, resultado = base; i < (expoente * (-1)); i++)
        {
            resultado *= base;
        }
        printf ("%d elevado a %d eh 1/%d", base, expoente, resultado);
    }
}
