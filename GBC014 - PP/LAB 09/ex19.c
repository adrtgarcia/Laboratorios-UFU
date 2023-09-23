#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) 
{
    char matriz[5][30], substituir[30], novo[30], apagar[30];
    int i, opcao, linha;

    for (i = 0; i < 5; i++) 
    {
        matriz[i][0] = '\0';
    }
    
    do 
    {
        printf ("\nescolha uma opcao:\n");
        printf ("\n(1) gravar um nome em uma linha da matriz");
        printf ("\n(2) apagar o nome contido em uma linha da matriz");
        printf ("\n(3) substituir um nome em uma linha da matriz");
        printf ("\n(4) apagar um nome em uma linha da matriz");
        printf ("\n(5) recuperar o nome contido em uma linha da matriz");
        printf ("\n(0) sair\n");
        scanf ("%d", &opcao);
        
        switch (opcao) 
        {
            case 1:
                printf ("\ndigite o numero da linha (0-4): ");
                scanf("%d", &linha);

                if (linha >= 0 && linha < 5) 
                {
                    printf ("\ndigite o nome a ser gravado: ");
                    fgets (matriz[linha], 30, stdin);
                    printf ("\no nome registrado");
                    
                } else {
                    printf("\nlinha invalida");
                }

                break;
                
            case 2:
                printf ("\ndigite o numero da linha (0-4): ");
                scanf("%d", &linha);

                if (linha >= 0 && linha < 5) 
                {
                    matriz[linha][0] = '\0';
                    printf("\no nome foi apagado");
                } else {
                    printf("\nlinha invalida");
                }

                break;
                
            case 3:
                printf ("\ndigite o nome a ser substituido: ");
                fgets (substituir, 30, stdin);
                
                printf ("\ndigite o novo nome: ");
                fgets (novo, 30, stdin);
                
                for (i = 0; i < 5; i++) 
                {
                    if (strcmp(matriz[i], substituir) == 0) 
                    {
                        strcpy(matriz[i], novo);
                        printf("\no nome substituido");
                        break;
                    }
                }
                
                if (i == 5) 
                {
                    printf ("\nnome nao encontrado");
                }

                break;
                
            case 4:
                printf ("\ndigite o nome a ser apagado: ");
                fgets (apagar, 30, stdin);
                
                for (i = 0; i < 5; i++) 
                {
                    if (strcmp(matriz[i], apagar) == 0) 
                    {
                        matriz[i][0] = '\0';
                        printf ("\no nome foi apagado");
                        break;
                    }
                }
                
                if (i == 5) 
                {
                    printf("\nnome nao encontrado");
                }

                break;
                
            case 5:
                printf ("\ndigite o numero da linha (0-4): ");
                scanf ("%d", &linha);
                
                if (linha >= 0 && linha < 5) 
                {
                    if (matriz[linha][0] != '\0') 
                    {
                        printf("\nnome na linha %d: %s", linha, matriz[linha]);
                    } else {
                        printf("\nnenhum nome na linha %d", linha);
                    }
                } else {
                    printf("\nlinha invalida");
                }

                break;
                
            default:
                printf("\nopcao invalida");
                break;
        }
        
        printf("\n");
        
    } while (opcao != 0);
    
    return 0;
}