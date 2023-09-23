#include <stdio.h>
#include <string.h>

int main ( )
{
    char str1[100], str2[100], concatenada[200];
    int tamanho1, tamanho2, N, i, j;

    printf ("digite a primeira string: ");
    fgets (str1, 100, stdin);
    tamanho1 = strlen(str1);

    printf ("digite a segunda string: ");
    fgets (str2, 100, stdin);
    tamanho2 = strlen(str2); 

    str1[strcspn(str1, '\n')] = '\0';
    str2[strcspn(str2, '\n')] = '\0';

    do
    {
        printf ("\ndigite um numero: ");
        scanf ("%d", &N);

        if (N <= 0)
        {
            printf ("\no numero precisa ser maior que zero");
        }

    } while (N <= 0);

    for (i = tamanho1, j = 0; (i < 100) && (j < N) && (j < tamanho2); i++, j++) 
    {
        str1[i] = str2[j];
    }

    str1[i] = '\0';
    
    printf ("\nnova string: %s", str1);

    return 0;
}