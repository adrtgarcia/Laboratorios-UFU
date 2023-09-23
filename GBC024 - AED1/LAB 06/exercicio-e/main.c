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

int main ( )
{
    int i;

    texto *t;
    t = criar ( );

    if (t == NULL)
    {
        printf ("erro na alocacao de memoria");
        return -1;
    }

    printf ("digite seu texto (max: 2000 caracteres)\n");
    fgets (t->str, 2000, stdin);
    t->str[strcspn(t->str, "\n")] = '\0';

    transforma (t);
    analisa (t);

    printf ("\n\nHISTOGRAMA:\n");
    for (i = 0; i < 26; i++)
    {
        if (t->ocorrencia[i] != 0)
        {
            printf ("\na letra '%c' aparece %dx", t->caractere[i], t->ocorrencia[i]);
        }

    }

    free(t);

    return 0;
}
