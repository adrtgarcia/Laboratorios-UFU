#include <stdio.h>

int main( )
{
    double salario = 2000, aumento = 0.015; 
    int ano;

    for (ano = 1996; ano <= 2023; ano++) 
    {
        salario = salario + (salario * aumento); 
        aumento *= 2; 
    }

    printf ("salario do funcionario em 2023: R$ %.2lf", salario);

    return 0;
}