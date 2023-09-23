#include <stdio.h>

int main ( )
{
    float n1, n2, n3, media, exame;

    printf ("digite a primeira nota: ");
    scanf ("%f", &n1);

    printf ("digite a segunda nota: ");
    scanf ("%f", &n2);

    printf ("digite a terceira nota: ");
    scanf ("%f", &n3);

    media = (n1 + n2 + n3) / 3;

    if ((media >= 0) && (media < 3))
    {
        printf ("\no aluno esta reprovado");
    } else if ((media >= 3) && (media < 7))
    {
        printf ("\no aluno esta de exame final");

        // (media + exame) / 2 = 6
        exame = 12 - media;

        printf ("\no aluno precisa de %.2f pontos no exame final", exame);
    } else {
        printf ("\no aluno esta aprovado");
    }

    return 0;
}
