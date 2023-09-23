#include <stdio.h>

void calc_esfera (float R, float *area, float *volume);

int main ( )
{
    float raio, area = 0, vol = 0;
    float *pr = NULL, *pa = NULL, *pv = NULL;

    pr = &raio;
    pa = &area;
    pv = &vol;

    printf ("digite o valor do raio: ");
    scanf ("%f", pr);

    calc_esfera (raio, pa, pv);

    printf ("\narea da esfera: %.2f", *pa);
    printf ("\nvolume da esfera: %.2f", *pv);

    return 0;
}

void calc_esfera (float R, float *area, float *volume)
{
    float A, V;
    
    A = 4 * 3.14 * (R * R);
    V = (4 * 3.14 * (R * R * R)) / 3;

    *area = A;
    *volume = V;
}