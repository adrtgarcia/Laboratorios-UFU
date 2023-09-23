#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( )
{
    char nome[] = "Carla Faria";
    double vet[10];
    int i;

    printf ("string: ");
    for (i = 0; *(nome + i) != '\0'; i++)
    {
        printf ("%c", *(nome+i));
    }

    srand(time(NULL));

    printf ("\n\nvetor double: [");
    for (i = 0; i < 10; i++)
    {
        *(vet + i) = rand ( ) % 100;
        printf (" %lf ", *(vet + i));
    }
    printf ("]");

    return 0;
}
