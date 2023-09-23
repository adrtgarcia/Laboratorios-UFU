#include <stdio.h>

void lernotas (float *n1, float *n2);
void media (float n1, float n2, float *simples, float *ponderada);

int main ( )
{
    float nota1, nota2, simp, pond;
    float *p1 = NULL, *p2 = NULL, *ps = NULL, *pp = NULL;

    p1 = &nota1;
    p2 = &nota2;
    ps = &simp;
    pp = &pond;

    lernotas (p1, p2);
    media (nota1, nota2, ps, pp);

    printf ("\nmedia simples: %.2f", *ps);
    printf ("\nmedia ponderada: %.2f", *pp);

    return 0;
}

void lernotas (float *n1, float *n2)
{
    printf ("digite a primeira nota: ");
    scanf ("%f", n1);

    printf ("digite a segunda nota: ");
    scanf ("%f", n2);
}

void media (float n1, float n2, float *simples, float *ponderada)
{
    *simples = (n1 + n2) / 2;
    *ponderada = (n1 + (n2 * 2)) / 3;
}