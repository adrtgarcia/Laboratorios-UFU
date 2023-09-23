#include "histograma.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct texto
{
    char str[2000];
    char caractere[26];
    int ocorrencia[26];
};
typedef struct texto texto;

texto *criar ( )
{
    int i;

    texto *t;
    t = (texto *) malloc (sizeof(texto));

    if (t != NULL)
    {
        for (i = 0; i < 26; i++)
        {
            t->caractere[i] = 'A' + i;
            t->ocorrencia[i] = 0;
        }
    }

    return t;
}

void transforma (texto *t)
{
    int i;

    for (i = 0; t->str[i] != '\0'; i++)
    {
        if (islower(t->str[i]))
        {
            t->str[i] = toupper(t->str[i]);
        }
    }
}

void analisa (texto *t)
{
    int i, j;

    for (i = 0; t->str[i] != '\0'; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (t->str[i] == t->caractere[j])
            {
                t->ocorrencia[j]++;
            }
        }
    }
}
