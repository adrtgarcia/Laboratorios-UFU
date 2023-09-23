#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int tam, i, j;
    char *s = NULL;

    printf ("digite o tamanho da string: ");
    scanf ("%d", &tam);
    setbuf (stdin, NULL);

    s = (char *) calloc (tam, (sizeof(char)));
    if (s == NULL)
    {
        printf ("\nerro: memoria insuficiente");
        exit(1);
    }

    printf ("\ndigite a string: ");
    fgets (s, tam, stdin);

    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == 'A') || (s[i] == 'a') || (s[i] == 'E') || (s[i] == 'e') || (s[i] == 'I') || (s[i] == 'i') || (s[i] == 'O') || (s[i] == 'o') || (s[i] == 'U') || (s[i] == 'u'))
        {
            for (j = i; s[j] != '\0'; j++)
            {
                s[j] = s[j + 1];
            }

            i--;
        }
    }
    
    printf ("string final: %s", s);

    free(s);

    return 0;
}