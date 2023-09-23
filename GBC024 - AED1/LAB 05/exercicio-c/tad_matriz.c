#include "tad_matriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct matriz
{
    int i, j;
    float **mat;
};
typedef struct matriz matriz;

matriz *criar (int linhas, int colunas)
{
    matriz *m;
    int aux;

    m = (matriz **) calloc (1, (sizeof(matriz *)));
    if (m == NULL)
        return NULL;

    m->i = linhas;
    m->j = colunas;

    m->mat = (float **) calloc (m->i, (sizeof(float *)));
    if (m->mat == NULL)
        return NULL;

    for (aux = 0; aux < m->i; aux++)
    {
        m->mat[aux] = (float *) calloc (m->j, (sizeof(float)));
        if (m->mat[aux] == NULL)
            return NULL;
    }

    return m;
}

void destruir (matriz *m)
{
    int aux;

    for (aux = 0; aux < m->i; aux++)
        free (m->mat[aux]);

    free (m->mat);
}

void atribuir (matriz *m, int i, int j)
{
    printf ("\ndigite o valor de mat[%d][%d]: ", i, j);
    scanf ("%f", &m->mat[i][j]);
}

float acessar (matriz *m, int i, int j)
{
    return m->mat[i][j];
}

int numero_linhas (matriz *m)
{
    return m->i;
}

int numero_colunas (matriz *m)
{
    return m->j;
}

void preencher (matriz *m, float minimo, float maximo)
{
    float num;
    int a, b;

    srand (time(NULL));

    for (a = 0; a < m->i; a++)
    {
        for (b = 0; b < m->j; b++)
        {
            num = ((float)rand() / RAND_MAX) * (maximo - minimo) + minimo;
            m->mat[a][b] = num;
        }
    }
}

matriz *somar (matriz *m1, matriz *m2)
{
    matriz *s;
    int a, b;

    if ((m1->i != m2->i) || (m1->j != m2->j))
        return -1;

    s = criar (m1->i, m1->j);
    if (s == NULL)
        return NULL;

    for (a = 0; a < m1->i; a++)
    {
        for (b = 0; b < m1->j; b++)
        {
            s->mat[a][b] = (m1->mat[a][b]) + (m2->mat[a][b]);
        }
    }

    return s;
}
