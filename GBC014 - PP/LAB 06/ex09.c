#include <stdio.h>
#include <math.h>

struct complexo
{
    float real, imag;
};
typedef struct complexo complexo;

int main ( )
{
    complexo z, w;
    float somar, somai, subr, subi, prod1, prod2, modz, modw;

    printf ("digite a parte real de z: ");
    scanf ("%f", &z.real);
    printf ("digite a parte imaginaria de z: ");
    scanf ("%f", &z.imag);

    printf ("digite a parte real de w: ");
    scanf ("%f", &w.real);
    printf ("digite a parte imaginaria de w: ");
    scanf ("%f", &w.imag);

    somar = z.real + w.real;
    somai = z.imag + w.imag;
    printf ("\nsoma: %.2f + %.2fi", somar, somai);

    subr = z.real - w.real;
    subi = z.imag - w.imag;
    printf ("\nsubtracao: %.2f + %.2fi", subr, subi);
    
    prod1 = (z.real * w.real) - (z.imag * w.imag);
    prod2 = (z.real * w.imag) + (w.real * z.imag);
    printf ("\nproduto: %.2f + %.2fi", prod1, prod2);

    modz = sqrt ((z.real * z.real) + (z.imag * z.imag));
    modw = sqrt ((w.real * w.real) + (w.imag * w.imag));
    printf ("\nmodulo de z: %.2f", modz);
    printf ("\nmodulo de w: %.2f", modw);

    return 0;
}