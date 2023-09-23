#include <stdio.h>
// leia um valor em REAL e a COTAÇÃO DO DÓLAR, imprima valor em DÓLARES

int main ( )
{
    float REAL, COT;
    printf ("insira o valor em reais: ");
    scanf ("%f", &REAL);

    printf ("insira a cotacao do dolar: ");
    scanf ("%f", &COT);

    float DOLAR = REAL / COT;
    printf ("valor em dolares: %.2f", DOLAR);

    return 0;
}