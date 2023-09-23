#include <stdio.h>      //printf, scanf

void pontos (int *pt1, int *pt2, int gt1, int gt2);

int main ( )
{
    int pts_t1, pts_t2, gol_t1, gol_t2;

    printf ("digite a pontuacao dos times antes do jogo\n");
    printf ("time 1: ");
    scanf ("%d", &pts_t1);
    printf ("time 2: ");
    scanf ("%d", &pts_t2);

    printf ("\ndigite o numero de gols marcados por cada time\n");
    printf ("time 1: ");
    scanf ("%d", &gol_t1);
    printf ("time 2: ");
    scanf ("%d", &gol_t2);

    pontos (&pts_t1, &pts_t2, gol_t1, gol_t2);

    return 0;
}

void pontos (int *pt1, int *pt2, int gt1, int gt2)
{
    if (gt1 > gt2)
    {
        printf ("\ntime 1 ganhou\n");
        *pt1 += 3;

        printf ("\npontuacao final");
        printf ("\ntime 1: %d", *pt1);
        printf ("\ntime 2: %d", *pt2);

    } else if (gt1 < gt2)
    {
        printf ("\ntime 2 ganhou\n");
        *pt2 += 3;

        printf ("\npontuacao final");
        printf ("\ntime 1: %d", *pt1);
        printf ("\ntime 2: %d", *pt2);

    } else if (gt1 == gt2)
    {
        printf ("\nempate\n");
        *pt1 += 3;

        printf ("\npontuacao final");
        printf ("\ntime 1: %d", *pt1);
        printf ("\ntime 2: %d", *pt2);
        
    }
}