#include <stdio.h>
// dividindo o prêmio da loteria entre três amigos de forma proporcional

int main ( )
{
    float premio;
    printf ("valor do premio: ");
    scanf ("%f", &premio);

    float a1, a2, a3;
    printf ("aposta 1: ");
    scanf ("%f", &a1);

    printf ("aposta 2: ");
    scanf ("%f", &a2);

    printf ("aposta 3: ");
    scanf ("%f", &a3);

    float aposta = a1 + a2 + a3;
    float p1 = a1 / aposta, p2 = a2 / aposta, p3 = a3 / aposta;
    float v1 = premio * p1, v2 = premio * p2, v3 = premio * p3;

    printf ("apostador 1 recebe: R$ %.2f \n", v1);
    printf ("apostador 2 recebe: R$ %.2f \n", v2);
    printf ("apostador 3 recebe: R$ %.2f", v3);

    return 0;
}