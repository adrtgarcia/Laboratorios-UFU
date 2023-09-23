#include <stdio.h>

int main ( )
{
    float nota;
    int falta;

    printf ("digite a nota do aluno: ");
    scanf ("%f", &nota);
    printf ("digite o numero de faltas do aluno: ");
    scanf ("%d", &falta);

    if (falta <= 20)
    {
        if ((nota >= 9.0) && (nota <= 10.0))
        {
            printf ("conceito: A");
        } else {
            if ((nota >= 7.5) && (nota <= 8.9))
            {
                printf ("conceito: B");
            } else {
                if ((nota >= 5.0) && (nota <= 7.4))
                {
                    printf ("conceito: C");
                } else {
                    if ((nota >= 4.0) && (nota <= 4.9))
                    {
                        printf ("conceito: D");
                    } else {
                        if ((nota >= 0.0) && (nota <= 3.9))
                        {
                            printf ("conceito: E");
                        }
                    }
                }
            }
        }
    }

    if (falta > 20)
    {
        if ((nota >= 9.0) && (nota <= 10.0))
        {
            printf ("conceito: B");
        } else {
            if ((nota >= 7.5) && (nota <= 8.9))
            {
                printf ("conceito: C");
            } else {
                if ((nota >= 5.0) && (nota <= 7.4))
                {
                    printf ("conceito: D");
                } else {
                    if ((nota >= 4.0) && (nota <= 4.9))
                    {
                        printf ("conceito: E");
                    } else {
                        if ((nota >= 0.0) && (nota <= 3.9))
                        {
                            printf ("conceito: E");
                        }
                    }
                }
            }
        }
    }

    return 0;
}