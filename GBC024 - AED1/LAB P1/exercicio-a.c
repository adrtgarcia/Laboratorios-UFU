#include <stdio.h>
#include <stdlib.h>

struct data
{
    int dia, mes, ano;
};
typedef struct data data;

void formatadata (data d);

int main ( )
{
    data d;

    do
    {
        printf ("digite o dia: ");
        scanf ("%d", &d.dia);

        if ((d.dia < 1) || (d.dia > 31))
        {
            printf ("dia invalido\n\n");
        }
    } while ((d.dia < 1) || (d.dia > 31));

    do
    {
        printf ("digite o mes: ");
        scanf ("%d", &d.mes);

        if ((d.mes < 1) || (d.mes > 12))
        {
            printf ("mes invalido\n\n");
        }
    } while ((d.mes < 1) || (d.mes > 12));

    do
    {
        printf ("digite o ano: ");
        scanf ("%d", &d.ano);

        if (d.ano < 1)
        {
            printf ("ano invalido\n\n");
        }
    } while (d.ano < 1);

    formatadata (d);

    return 0;
}

void formatadata (data d)
{
    if ((d.mes == 2) && (d.dia > 29))
    {
        printf ("\ndata invalida");
        exit(1);
    } else if (((d.mes == 4) || (d.mes == 6) || (d.mes == 9) || (d.mes == 11)) && (d.dia > 30))
    {
        printf ("\ndata invalida");
        exit(1);
    }

    if ((d.dia < 10) && (d.mes < 10))
    {
        printf ("\n0%d/0%d/%d", d.dia, d.mes, d.ano);
    } else if ((d.dia < 10) && (d.mes >= 10))
    {
        printf ("\n0%d/%d/%d", d.dia, d.mes, d.ano);
    } else if ((d.dia >= 10) && (d.mes < 10))
    {
        printf ("\n%d/0%d/%d", d.dia, d.mes, d.ano);
    }
}
