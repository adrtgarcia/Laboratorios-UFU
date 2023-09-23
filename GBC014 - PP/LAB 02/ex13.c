#include <stdio.h>

int main ( )
{
    float n1, n2, n3;
    printf ("digite a nota 1: ");
    scanf ("%f", &n1);
    printf ("digite a nota 2: ");
    scanf ("%f", &n2);
    printf ("digite a nota 3: ");
    scanf ("%f", &n3);

    float media = (n1 + n2 + (n3 * 2))/4;

    if (media >= 60)
    {
        printf ("a media foi %.2f e o aluno esta aprovado", media);
    } else {
        printf ("a media foi %.2f o aluno esta reprovado", media);
    }

    return 0;
}