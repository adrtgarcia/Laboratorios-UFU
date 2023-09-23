#include <stdio.h>
#include <string.h>

struct funcionario
{
    char nome[100], sexo, cpf[15], nasc[11], cargo[30];
    int idade, setor;
    float salario;
};
typedef struct funcionario funcionario;

int main ( )
{
    funcionario x;

    printf ("digite o nome: ");
    fgets (x.nome, 100, stdin);
    x.nome[strcspn(x.nome, "\n")] = '\0';

    printf ("digite a idade: ");
    scanf ("%d", &x.idade);

    printf ("digite o sexo (M/F): ");
    scanf (" %c", &x.sexo);

    printf ("digite o CPF: ");
    scanf ("%s", &x.cpf);

    printf ("digite a data de nascimento (DD/MM/AAAA): ");
    scanf ("%s", &x.nasc);

    printf ("digite o codigo do setor (0-99): ");
    scanf ("%d", &x.setor);

    setbuf (stdin, NULL);
    printf ("digite o cargo: ");
    fgets (x.cargo, 30, stdin);
    x.cargo[strcspn(x.cargo, "\n")] = '\0';

    printf ("digite o salario: R$ ");
    scanf ("%f", &x.salario);

    printf ("\nficha do funcionario: ");
    printf ("\nnome: %s", x.nome);
    printf ("\nidade: %d", x.idade);
    printf ("\nsexo: %c", x.sexo);
    printf ("\nCPF: %s", x.cpf);
    printf ("\ndata de nascimento: %s", x.nasc);
    printf ("\ncodigo do setor: %d", x.setor);
    printf ("\ncargo: %s", x.cargo);
    printf ("\nsalario: R$ %.2f", x.salario);

    return 0;
}