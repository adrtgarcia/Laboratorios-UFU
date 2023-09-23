#include <stdio.h>

int transformar_segs (int h, int m, int s);

int main ( )
{
    int hora, min, seg;
    printf ("no formato HH:MM:SS, digite o horario: ");
    scanf ("%d:%d:%d", &hora, &min, &seg);
    
    printf ("tempo total em segundos: %d", transformar_segs (hora, min, seg));

    return 0;
}

int transformar_segs (int h, int m, int s)
{
    int total = (h*3660) + (m*60) + s;

    return total;
}