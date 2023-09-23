#include <stdio.h>

int divisao (int a, int b, int *q, int *r);

int main ( )
{
    int n1, n2, quociente, resto, analisa;

    printf ("digite o dividendo: ");
    scanf ("%d", &n1);

    printf ("digite o divisor: ");
    scanf ("%d", &n2);

    analisa = divisao (n1, n2, &quociente, &resto);
    switch (analisa)
    {
        case -1:
            printf ("\nnao eh possivel realizar a divisao");
            break;

        case 0:
            printf ("\nquociente: %d", quociente);
            printf ("\nresto: %d", resto);
            break;
    }

    return 0;
}

int divisao (int a, int b, int *q, int *r)
{
    if (b == 0)
    {
        return -1;
    }

    *q = a / b;
    *r = a % b;
    return 0;
}
