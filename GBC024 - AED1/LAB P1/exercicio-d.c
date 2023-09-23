#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analisatexto (char *texto);

int main ( )
{
    char texto[400];

    printf ("digite um texto (maximo de 400 caracteres):\n");
    fgets (texto, 400, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    analisatexto (texto);

    return 0;
}

void analisatexto (char *texto)
{
    char *digitados;
    int *quant;
    int i, j, k;

    digitados = (char *) calloc (strlen(texto), (sizeof(char)));
    if (digitados == NULL)
    {
        printf ("\nerro de alocacao de memoria");
        exit(1);
    }

    quant = (int *) calloc (strlen(texto), (sizeof(int)));
    if (quant == NULL)
    {
        printf ("\nerro de alocacao de memoria");
        exit(1);
    }

    for (i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] != ' ')
        {
            digitados[i] = texto[i];
            quant[i] = 0;

            for (j = (i + 1); texto[j] != '\0'; j++)
            {
                if (texto[i] == texto[j])
                {
                    quant[i]++;

                    for (k = j; texto[k] != '\0'; k++)
                    {
                        texto[k] = texto[(k + 1)];
                    }

                    j--;
                }
            }
        } else {
            for (j = i; texto[j] != '\0'; j++)
            {
                texto[j] = texto[(j + 1)];
            }

            i--;
        }
    }

    printf ("\ncaracteres digitados:");
    printf ("\nvet[");
    for (i = 0; texto[i] != '\0'; i++)
    {
        printf (" %c ", digitados[i]);
    }
    printf ("]");

    printf ("\n\nrepeticacao de cada caractere:");
    printf ("\nvet[");
    for (i = 0; texto[i] != '\0'; i++)
    {
        printf (" %d ", quant[i]);
    }
    printf ("]");

    free(digitados);
    free(quant);
}
