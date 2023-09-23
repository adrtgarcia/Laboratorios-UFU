#include <stdio.h>
//leia o VALOR DA HORA de trabalho, número de HORAS TRABALHADAS e imprima o valor final + 10%

int main ( )
{
    float VAL, HOR;
    printf ("insira o valor da hora: ");
    scanf ("%f", &VAL);

    printf ("insira as horas trabalhadas: ");
    scanf ("%f", &HOR);

    float TOTAL = (VAL * HOR) * 1.10; //adicionando 10% = 110% = 1.10
    printf ("valor a ser pago: R$ %.2f", TOTAL);

    return 0;
}