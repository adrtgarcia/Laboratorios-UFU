#include <stdio.h>
// leia o HORÁRIO DE INÍCIO e a DURAÇÃO EM SEGUNDOS, mostre HORÁRIO DO TÉRMINO

int main ( )
{
    int hora, minuto, segundo;
    printf ("no formato hh:mm:ss, digite o horario inicial: ");
    scanf ("%d:%d:%d", &hora, &minuto, &segundo);

    int exp;
    printf ("em segundos, digite a duracao da experiencia: ");
    scanf ("%d", &exp);

    int tempo = (hora * 3600) + (minuto * 60) + segundo + exp;
    int h = tempo/3600, min = (tempo%3600)/60, s = (tempo%3600)%60;

    printf ("horario de termino: %02d:%02d:%02d", h, min, s);

    return 0;
}