#include <stdio.h>

int main ( )
{
    float sal, pem;
    printf ("digite o valor do salario: ");
    scanf ("%f", &sal);
    printf ("digite o valor da prestacao do emprestimo: ");
    scanf ("%f", &pem);

    if (pem > 0.2 * sal)
    {
        printf ("emprestimo nao concedido");
    } else {
        printf ("emprestimo concedido");
    }

    return 0;
}