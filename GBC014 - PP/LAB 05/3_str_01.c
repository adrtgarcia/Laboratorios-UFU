#include <stdio.h>

int main ( )
{
    char string[100];
    printf ("digite uma string: ");
    fgets(string, 100, stdin);

    printf ("string lida: %s", string);

    return 0;
}