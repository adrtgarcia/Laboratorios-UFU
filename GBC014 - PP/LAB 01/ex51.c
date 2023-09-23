#include <stdio.h>
#include <math.h>
// leia as coordenadas (x,y), calcule sua DISTÂNCIA da origem (0,0)

int main ( )
{
    int x, y;
    printf ("digite o valor de x: ");
    scanf ("%d", &x);

    printf ("digite o valor de y: ");
    scanf ("%d", &y);

    float dist = sqrt (pow(0 - x, 2) + pow (0 - y, 2)); // dab = sqrt (pow (xb-xa, 2) + pow (yb-ya, 2))
    printf ("distancia entre (x,y) e (0,0): %.2f", dist);

    return 0;
}