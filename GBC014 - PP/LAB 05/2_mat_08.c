#include <stdio.h>

int main ( )
{
    int mat1[2][2], mat2[2][2], mat3[2][2], a, b, op, cte;

    printf ("digite os valores da primeira matriz:\n");
    for (a = 0; a < 2; a++)
    {
        for (b = 0; b < 2; b++)
        {
            scanf ("%d", &mat1[a][b]);
        }
    }

    printf ("digite os valores da segunda matriz:\n");
    for (a = 0; a < 2; a++)
    {
        for (b = 0; b < 2; b++)
        {
            scanf ("%d", &mat2[a][b]);
        }
    }

    do
    {
        printf ("\nmenu:\n");
        printf ("\n(1) somar as duas matrizes");
        printf ("\n(2) subtrair a primeira matriz da segunda");
        printf ("\n(3) adicionar uma constante as duas matrizes");
        printf ("\n(4) imprimir as matrizes\n");
        printf ("\nescolha uma opcao: ");
        scanf ("%d", &op);

        if ((op < 1) || (op > 4))
        {
            printf ("opcao invalida");
        }
    } while ((op < 1) || (op > 4));
    
    switch (op)
    {
    case 1:
        printf ("\nmatriz resultante:\n");
        for (a = 0; a < 2; a++)
        {
            for (b = 0; b < 2; b++)
            {
                mat3[a][b] = mat1[a][b] + mat2[a][b];
                printf ("%5d ", mat3[a][b]);
            }
            
            printf ("\n");
        }
        break;

    case 2:
        printf ("\nmatriz resultante:\n");
        for (a = 0; a < 2; a++)
        {
            for (b = 0; b < 2; b++)
            {
                mat3[a][b] = mat2[a][b] - mat1[a][b];
                printf ("%5d ", mat3[a][b]);
            }

            printf ("\n");
        }
        break;

    case 3:
        printf ("\ndigite o valor da constante: ");
        scanf ("%d", &cte);

        printf ("\nmatriz 1 + contante:\n");
        for (a = 0; a < 2; a++)
        {
            for (b = 0; b < 2; b++)
            {
                mat3[a][b] = mat1[a][b] + cte;
                printf ("%5d ", mat3[a][b]);
            }

            printf ("\n");
        }

        printf ("\nmatriz 2 + contante:\n");
        for (a = 0; a < 2; a++)
        {
            for (b = 0; b < 2; b++)
            {
                mat3[a][b] = mat2[a][b] + cte;
                printf ("%5d ", mat3[a][b]);
            }

            printf ("\n");
        }
        break;

    case 4:
        printf ("\nmatriz 1:\n");
        for (a = 0; a < 2; a++)
        {
            for (b = 0; b < 2; b++)
            {
                printf ("%5d ", mat1[a][b]);
            }

            printf ("\n");
        }
        
        printf ("\nmatriz 2:\n");
        for (a = 0; a < 2; a++)
        {
            for (b = 0; b < 2; b++)
            {
                printf ("%5d ", mat2[a][b]);
            }

            printf ("\n");
        }
        break;
    }

    return 0;
}