#include <stdio.h>
#include <math.h>

struct polar
{
    float r, a;
};
typedef struct polar polar;

struct cartesiano
{
    float x, y;
};
typedef struct cartesiano cartesiano;

int main ( )
{
    polar pontop;
    cartesiano pontoc;
    
    printf ("digite o raio da coordenada polar: ");
    scanf ("%f", &pontop.r);
    printf ("digite o argumento da coordenada polar, em radianos: ");
    scanf ("%f", &pontop.a);

    pontoc.x = pontop.r * cos(pontop.a);
    pontoc.y = pontop.r * sin(pontop.a);

    printf ("coordenadas no plano cartesiano: (%.2f, %.2f)", pontoc.x, pontoc.y);

    return 0;
}