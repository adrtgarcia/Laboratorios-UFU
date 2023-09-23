#include <stdio.h>
// leia um valor INTEIRO em SEGUNGOS, imprima-o em HORAS, MINUTOS e SEGUNDOS

int main ( )
{
    int tempo;
    printf ("digite o tempo em segundos: ");
    scanf ("%d", &tempo);

    int h = tempo / 3600;
    int min = (tempo - (h * 3600)) / 60;
    int s = tempo - (h * 3600) - (min * 60);
    printf ("%02d:%02d:%02d", h, min, s);

    return 0;
}