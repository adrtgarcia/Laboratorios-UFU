#include <stdio.h>

int main ( )
{
    float alt;
    printf ("informe sua altura, em metros: ");
    scanf ("%f", &alt);

    char sex;
    printf ("informe seu sexo, com F ou M: ");
    scanf (" %c", &sex);

    if ((sex == 'M') || (sex == 'm'))
    {
        float peso = (72.7 * alt) - 58.0;
        printf ("%.2f eh seu peso ideal", peso);
    } else {
        if ((sex == 'F') || (sex == 'f'))
        {
            float peso = (62.1 * alt) - 44.7;
            printf ("%.2f eh seu peso ideal", peso);
        } else {
            printf ("dados invalidos");
        }
    }

    return 0;
}