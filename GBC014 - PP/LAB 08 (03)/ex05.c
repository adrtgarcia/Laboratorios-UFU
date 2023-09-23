#include <stdio.h>

void frac (float num, int *inteiro, float *frac);

int main ( )
{
    float x, partef = 0;
    float *pf = NULL;
    
    int partei = 0;
    int *pi = NULL;

    pf = &partef;
    pi = &partei;

    printf ("digite um numero real: ");
    scanf ("%f", &x);

    frac (x, pi, pf);
    printf ("\nparte inteira: %d", *pi);
    printf ("\nparte funcionaria: %f", *pf);

    return 0;
}

void frac (float num, int *inteiro, float *frac)
{
    *inteiro = (int)num;
    *frac = num - *inteiro;
}