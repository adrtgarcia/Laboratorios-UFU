#include <stdio.h>

struct vetor
{
    float a;
    float b;
    float c;
};
typedef struct vetor vetor;

int main ( )
{
    vetor x, y, z;

    printf ("digite os valores do primeiro vetor:\n");
    scanf ("%f", &x.a);
    scanf ("%f", &x.b);
    scanf ("%f", &x.c);

    printf ("digite os valores do segundo vetor:\n");
    scanf ("%f", &y.a);
    scanf ("%f", &y.b);
    scanf ("%f", &y.c);

    z.a = x.a + y.a;
    z.b = x.b + y.b;
    z.c = x.c + y.c;

    printf ("\na soma desses dois vetores eh [%.1f, %.1f, %.1f]", z.a, z.b, z.c);

    return 0;
}