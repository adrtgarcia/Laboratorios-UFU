#include <stdio.h>

int main ( )
{
    float A, B, C;
    printf ("digite o primeiro valor: ");
    scanf ("%f", &A);
    printf ("digite o segundo valor: ");
    scanf ("%f", &B);
    printf ("digite o terceiro valor: ");
    scanf ("%f", &C);

    if ((A < B + C) && (B < A + C) && (C < A + B))
    {
        if ((A == B) && (A == C) && (B == C))
        {
            printf ("o triangulo formado eh equilatero");
        } else {
            if (((A == B) && (A != C)) || ((A == C) && (A != B)) || ((B == C) && (B != A)))
            {
                printf ("o triangulo formado eh isosceles");
            } else {
                printf ("o triangulo formado eh escaleno");
            }
        }
    } else {
        printf ("os valores dados nao formam um triangulo");
    }

    return 0;
}