#include <stdio.h>

struct dma
{
    int dia;
    int mes;
    int ano;
};
typedef struct dma dma;

int main ( )
{
    dma a, b;
    int dias = 0;

    printf ("digite a primeira data: ");
    scanf ("%d/%d/%d", &a.dia, &a.mes, &a.ano);
    printf ("digite a segunda data: ");
    scanf ("%d/%d/%d", &b.dia, &b.mes, &b.ano);

    dias += (b.ano - a.ano) * 365;
    dias += (b.mes - a.mes) * 30;
    dias += (b.dia - a.dia);

    printf ("decorreram %d dias entre as duas datas", dias);

    return 0;
}