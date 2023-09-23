#include <stdio.h>
#include <string.h>

int main ( )
{
    char str[100];
    int i, j, k, quant;

    printf ("digite uma string: ");
    fgets (str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';


    for (i = 0; str[i] != '\0'; i++)
    {
        quant = 0;

        if (str[i] != ' ')
        {
            for (j = (i + 1); str[j] != '\0'; j++)
            {
                if (str[i] == str[j])
                {
                    quant++;

                    for (k = j; str[k] != '\0'; k++)
                    {
                        str[k] = str[(k + 1)];
                    }

                    j--;
                }
            }
        }

        if (quant != 0)
        {
            printf ("\na letra '%c' repete %d vezes", str[i], quant);
        }
    }

    return 0;
}
