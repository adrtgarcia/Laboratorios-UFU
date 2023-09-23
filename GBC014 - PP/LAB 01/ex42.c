#include <stdio.h>
//receba o SALÁRIO-BASE, imprima o SALÁRIO A RECEBER sabendo que: 5% de gratificação, 7% imposto de renda

int main ( )
{
    float SB;
    printf ("digite o valor do salario-base: ");
    scanf ("%f", &SB);

    float S = (SB * 1.05) - (SB * 0.07);
    printf ("salario a receber: R$ %.2f", S);

    return 0;
}