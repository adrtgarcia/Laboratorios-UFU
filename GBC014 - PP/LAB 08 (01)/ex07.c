#include <stdio.h>

int main ( )
{
    int a, b, c;
    int *pa = NULL, *pb = NULL, *pc = NULL;

    pa = &a;
    pb = &b;
    pc = &c;

    printf ("digite o primeiro numero: ");
    scanf ("%d", &(*pa));
    printf ("digite o segundo numero: ");
    scanf ("%d", &(*pb));
    printf ("digite o terceiro numero: ");
    scanf ("%d", &(*pc));

    if ((a < b) && (b < c))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", a, pa, b, pb, c, pc);
    } else if ((a < c) && (c < b))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", a, pa, c, pc, b, pb);
    } else if ((b < a) && (a < c))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", b, pb, a, pa, c, pc);
    } else if ((b < c) && (c < a))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", b, pb, c, pc, a, pa);
    } else if ((c < a) && (a < b))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", c, pc, a, pa, b, pb);
    } else if ((c < b) && (b < a))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", c, pc, b, pb, a, pa);
    } else if ((a == b) && (a < c))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", a, pa, b, pb, c, pc);
    } else if ((a == c) && (a < b))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", a, pa, c, pc, b, pb);
    } else if ((b == c) && (b < a))
    {
        printf ("\nordem crescente: %d (%p) - %d (%p) - %d (%p)", b, pb, c, pc, a, pa);
    }

    return 0;
}