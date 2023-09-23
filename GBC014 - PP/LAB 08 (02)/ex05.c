#include <stdio.h>
#include <string.h>

int main ( )
{
    char str1[50], str2[50];
    char *ps1 = NULL, *ps2 = NULL;
    int confere = 0; // 0 = não corre, 1 = ocorre

    printf ("digite a primeira string: ");
    fgets (str1, 50, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf ("digite a segunda string: ");
    fgets (str2, 50, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    for (ps1 = str1, ps2 = str2; (*ps1 != '\0') && (*ps2 != '\0'); ps1++)
    {
        while (*ps1 == *ps2)
        {
            ps1++;
            ps2++;

            if (*ps2 == '\0')
            {
                confere = 1;
            } else if (*ps1 != *ps2) {
                ps2 = str2;
            }
        }
    }

    if (confere == 1)
    {
        printf ("\na segunda string ocorre dentro da primeira");
    } else {
        printf ("\na segunda string nao ocorre dentro da primeira");
    }

    return 0;
}