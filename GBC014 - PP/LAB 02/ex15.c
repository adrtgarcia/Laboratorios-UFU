#include <stdio.h>

int main ( )
{
    int dia;
    printf ("digite um numero, de 1 a 7: ");
    scanf ("%d", &dia);

    switch (dia)
    {
    case 1:
        printf ("dia correspondente: domingo");
        break;
    case 2:
        printf ("dia correspondente: segunda-feira");
        break;
    case 3:
        printf ("dia correspondente: terca-feira");
        break;
    case 4:
        printf ("dia correspondente: quarta-feira");
        break;
    case 5:
        printf ("dia correspondente: quinta-feira");
        break;
    case 6:
        printf ("dia correspondente: sexta-feira");
        break;
    case 7:
        printf ("dia correspondente: sabado");
        break;

    default:
        printf ("numero invalido");
        break;
    }

    return 0;
}