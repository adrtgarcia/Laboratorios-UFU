#include <stdio.h>
// solicite o NÚMERO DE DIAS e imprima a QUANTIA LÍQUIDA A SER PAGA

int main ( )
{
    int d;
    printf ("insira o numero de dias trabalhados: ");
    scanf ("%d", &d);

    float v = (d * 30) * 0.92; //dados do exercício: 30 reais/dia, 8% para o imposto de renda
    printf ("quantia liquida: R$ %.2f", v);

    return 0;
}