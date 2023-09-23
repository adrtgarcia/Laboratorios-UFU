#include <stdio.h>

int main ( )
{
    float lab, ava, exa;
    printf ("digite sua nota no trabalho de laboratorio: ");
    scanf ("%f", &lab);
    printf ("digite sua nota na avaliacao semestral: ");
    scanf ("%f", &ava);
    printf ("digite sua nota no exame final: ");
    scanf ("%f", &exa);

    float media = ((lab*2) + (ava*3) + (exa*5))/10;

    // reprovado = 0 a 2,9
    if ((media <= 2.9))
    {
        printf ("o aluno esta reprovado");
    } else {
        if (media <= 4.9)
        {
            printf ("o aluno esta de recuperacao");
        } else {
            printf ("o aluno esta aprovado");
        }
    }
    // recuperação = 3 a 4,9
    // aprovado = 5 a 10

    return 0;
}