#include "tad_conjuntos.h"

#include <stdio.h>
#include <stdlib.h>

struct conjunto
{
    int *vet;
    int tamanho;
};
typedef struct conjunto conjunto;

conjunto *criacao ( )
{
    conjunto *c;

    c = (conjunto *) calloc (1, (sizeof(conjunto)));
    if (c == NULL) exit(1);

    c->vet = NULL;
    c->tamanho = 0;

    return c;
}

void membro (conjunto *c)
{
    int num, analisa;
    int i, j;

    c->vet = (int *) calloc (1, (sizeof(int)));
    if (c->vet == NULL) exit(1);

    c->tamanho = 1;

    printf ("\ndigite os elementos do conjunto (negativo encerra):");
    i = 0;

    while (1)
    {
        printf ("\nelemento %d = ", (i + 1));
        scanf ("%d", &num);

        if (num < 0)
        {
            printf ("\n\nencerrando leitura...");
            break;
        }

        c->vet[i] = num;

        analisa = 0;

        for (j = (i + 1); j < c->tamanho; j++)
        {
            if (num == c->vet[j])
            {
                analisa = 1;
                break;
            }

        }

        if (analisa == 0)
        {
            c->tamanho++;
            i++;

            c->vet = (int *) realloc (c->vet, (c->tamanho * (sizeof(int))));
            if (c->vet == NULL) exit(1);
        }
    }

    printf ("\n\nconjunto criado:\n[");
    for (i = 0; i < c->tamanho; i++)
    {
        printf (" %d ", c->vet[i]);
    }
    printf ("]");
}

void inserir (conjunto *c)
{
    int num;
    int i;

    c->tamanho++;

    printf ("\ndigite o numero que deseja inserir: ");
    scanf ("%d", &num);

    c->vet = (int *) realloc (c->vet, (c->tamanho * (sizeof(int))));
    if (c->vet == NULL) exit(1);

    c->vet[c->tamanho] = num;

    printf ("\n\nconjunto atualizado:\n[");
    for (i = 0; i < c->tamanho; i++)
    {
        printf (" %d ", c->vet[i]);
    }
    printf ("]");
}

void remover (conjunto *c)
{
    int num;
    int i, j;

    printf ("\ndigite o numero que deseja remover: ");
    scanf ("%d", &num);

    for (i = 0; i < c->tamanho; i++)
    {
        if (c->vet[i] == num)
        {
            for (j = (i + 1); j < c->tamanho; j++)
            {
                c->vet[i] = c->vet[j];
            }

            c->tamanho--;
            break;
        }
    }

    c->vet = (int *) realloc (c->vet, (c->tamanho * (sizeof(int))));
    if (c->vet == NULL) exit(1);

    printf ("\n\nconjunto atualizado:\n[");
    for (i = 0; i < c->tamanho; i++)
    {
        printf (" %d ", c->vet[i]);
    }
    printf ("]\n");
}

conjunto *uniao (conjunto *c1, conjunto *c2)
{
    int i, j, k;
    conjunto *u;

    u = criacao ( );
    u->tamanho = (c1->tamanho) + (c2->tamanho);

    u->vet = (int *) calloc (u->tamanho, (sizeof(int)));
    if (u->vet == NULL) exit(1);

    for (i = 0; i < c1->tamanho; i++)
    {
        u->vet[i] = c1->vet[i];
    }

    for (j = 0; j < c2->tamanho; j++, i++)
    {
        u->vet[i] = c2->vet[j];
    }

    for (i = 0; i < u->tamanho; i++)
    {
        for (j = 1; j < u->tamanho; j++)
        {
            if (u->vet[i] == u->vet[j])
            {
                for (k = j; k < u->tamanho; k++)
                {
                    u->vet[k] = u->vet[(k + 1)];
                }

                u->tamanho--;
                u->vet = (int *) realloc (u->vet, ((u->tamanho) * (sizeof(int))));
                if (u->vet == NULL) exit(1);
            }
        }
    }

    return u;
}

conjunto *interseccao (conjunto *c1, conjunto *c2)
{
    int a, b, c;
    conjunto *i;

    i = criacao ( );
    i->tamanho = (c1->tamanho) + (c2->tamanho);

    i->vet = (int *) calloc (i->tamanho, (sizeof(int)));
    if (i->vet == NULL) exit(1);

    for (a = 0, c = 0; a < i->tamanho; a++)
    {
        for (b = 0; b < i->tamanho; b++)
        {
            if (c1->vet[a] == c2->vet[b])
            {
                i->vet[c] = c1->vet[a];
                c++;
                break;
            }
        }
    }

    i->vet = (int *) realloc (i->vet, (c * (sizeof(int))));
    if (i->vet == NULL) exit(1);

    return i;
}

conjunto *diferenca (conjunto *c1, conjunto *c2)
{
    int i, j, k;
    conjunto *d;

    d = criacao ( );
    d->tamanho = (c1->tamanho) + (c2->tamanho);

    d->vet = (int *) calloc (d->tamanho, (sizeof(int)));
    if (d->vet == NULL) exit(1);

    for (i = 0, k = 0; i < d->tamanho; i++)
    {
        for (j = 0; j < d->tamanho; j++)
        {
            if (c1->vet[i] == c2->vet[j])
            {
                break;
            } else {
                d->vet[k] = c1->vet[i];
                k++;
                break;
            }
        }
    }

    d->vet = (int *) realloc (d->vet, (k * (sizeof(int))));
    if (d->vet == NULL) exit(1);

    return d;
}
