#include <stdio.h>

int main ( )
{
    int mes;
    printf ("digite um numero, de 1 a 12: ");
    scanf ("%d", &mes);

    switch (mes)
    {
    case 1: printf ("mes correspondente: janeiro"); break;
    case 2: printf ("mes correspondente: fevereiro"); break;
    case 3: printf ("mes correspondente: marco"); break;
    case 4: printf ("mes correspondente: abril"); break;
    case 5: printf ("mes correspondente: maio"); break;
    case 6: printf ("mes correspondente: junho"); break;
    case 7: printf ("mes correspondente: julho"); break;
    case 8: printf ("mes correspondente: agosto"); break;
    case 9: printf ("mes correspondente: setembro"); break;
    case 10: printf ("mes correspondente: outubro"); break;
    case 11: printf ("mes correspondente: novembro"); break;
    case 12: printf ("mes correspondente: dezembro"); break;

    default: printf ("numero invalido"); break;
    }

    return 0;
}