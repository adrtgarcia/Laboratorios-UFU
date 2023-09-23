#include "tad_string.h"

#include <stdio.h>
#include <stdlib.h>

struct str
{
    char *string;
    int tamanho;
};
typedef struct str str;

str *criar ( )
{
    str *s;

    s = (str *) calloc (1, (sizeof(str)));
    if (s == NULL)
        return NULL;

    s->string = NULL;
    s->tamanho = 0;

    return s;
}

void *preencher (str *s)
{
    int i;

    s->string = (char *) calloc (100, (sizeof(char)));
    if (s->string == NULL)
        exit (1);

    printf ("digite a string:\n");
    fgets (s->string, 100, stdin);

    for (i = 0; s->string[i] != '\0'; i++)
    {
        if (s->string[i] == '\n')
        {
            s->string[i] = '\0';

            s->string = (char *) realloc (s->string, ((i + 1) * (sizeof(char))));
            if (s->string == NULL)
            {
                printf ("\nerro na realocacao de memoria da string");
                exit (1);
            }

            break;
        }
    }
}

int tamanho (str *s)
{
    int i;

    for (i = 0; s->string[i] != '\0'; i++)
        s->tamanho++;

    return s->tamanho;
}

int ocorrencias (str *s, char c)
{
    int i, quant;

    for (i = 0, quant = 0; s->string[i] != '\0'; i++)
    {
        if (s->string[i] == c)
            quant++;
    }

    return quant;
}

void printar (str *s)
{
    printf ("%s", s->string);
}
