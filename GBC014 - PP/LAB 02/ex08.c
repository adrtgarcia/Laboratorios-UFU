#include <stdio.h>

int main ( )
{
    float n1, n2;
    printf ("digite a nota 1: ");
    scanf ("%f", &n1);
    printf ("digite a nota 2: ");
    scanf ("%f", &n2);

    if (((n1 >= 0.0) && (n1 <= 10.0)) && ((n2 >= 0.0) && (n2 <= 10.0)))
    {
        float media = (n1 + n2)/2;
        printf ("sua media: %.1f", media);
    } else {
        printf ("os valores nao sao validos");
    }

    return 0;
}