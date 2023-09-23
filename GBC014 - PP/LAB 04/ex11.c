#include <stdio.h>

float calculo_notas (float n1, float n2, float n3, char x);

int main ( )
{
    float nota1, nota2, nota3;
    char letra;

    printf ("digite a nota 1: ");
    scanf ("%f", &nota1);
    printf ("digite a nota 2: ");
    scanf ("%f", &nota2);
    printf ("digite a nota 3: ");
    scanf ("%f", &nota3);

    do
    {
        printf ("\npara calcular media aritmetica, digite A");
        printf ("\npara calcular media ponderada, digite P");
        printf ("\ndigite sua escolha: ");
        scanf (" %c", &letra);

        if ((letra != 'A') && (letra != 'a') && (letra != 'P') && (letra != 'p'))
        {
            printf ("\nopcao invalida\n");
        }

    } while ((letra != 'A') && (letra != 'a') && (letra != 'P') && (letra != 'p'));

    printf ("nota final: %.2f", calculo_notas (nota1, nota2, nota3, letra));

    return 0;
}

float calculo_notas (float n1, float n2, float n3, char x)
{
    if ((x == 'A') || (x == 'a'))
    {
        float nota = (n1 + n2 + n3)/3;
        return nota;
    } else if ((x == 'P') || (x == 'p'))
    {
        float nota = ((n1*5) + (n2*3) + (n3*2))/10;
        return nota;
    }
}