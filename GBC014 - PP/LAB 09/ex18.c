#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro
{
    char nome[30];
    int codigo;
    float preco;
};
typedef struct registro registro;

int main ( ) 
{
    int i, j;
    char *vetor1KB = (char *) malloc (1024);
    int **matriz = (int **) malloc (10 * (sizeof(int*)));
    registro *vetorreg = (registro *) malloc (50 * (sizeof(registro)));
    char** texto = (char**)malloc(100 * (sizeof(char*)));
       
    for (i = 0; i < 10; i++) 
    {
        matriz[i] = (int *) malloc(10 * (sizeof(int)));
    }
    
    for (i = 0; i < 100; i++) 
    {
        texto[i] = (char *) malloc ((80 + 1) * (sizeof(char)));
    }
    
    strcpy (vetor1KB, "exemplo de vetor de 1024 bytes");
    printf ("vetor 1KB: %s", vetor1KB);
    
    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 10; j++) 
        {
            matriz[i][j] = i + j;
        }
    }
    
    printf("\nmatriz 10x10:\n");
    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 10; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        
        printf("\n");
    }
    
    for (i = 0; i < 50; i++) 
    {
        sprintf (vetorreg[i].nome, "produto %d", i + 1);
        vetorreg[i].codigo = i + 1;
        vetorreg[i].preco = (float)(i + 1) * 10.0;
    }
    
    printf("\nvetor de registros:\n");
    for (i = 0; i < 50; i++) 
    {
        printf ("\n");
        printf ("\nregistro %d", (i + 1)); 
        printf ("\nnome: %s", vetorreg[i].nome);
        printf ("\ncodigo: %d", vetorreg[i].codigo);
        printf ("\npreco: %.2f", vetorreg[i].preco);
    }
    
    for (i = 0; i < 100; i++) 
    {
        sprintf (texto[i], "linha %d: ", (i + 1));
        
        for (j = 0; j < 80; j++) 
        {
            texto[i][j + 10] = 'A' + (j % 26);
        }

        texto[i][80 + 10] = '\0';
    }
    
    printf("\ntexto de 100 linhas:\n");
    for (i = 0; i < 100; i++) 
    {
        printf("\n%s", texto[i]);
    }
    
    free(vetor1KB);
    
    for (i = 0; i < 10; i++) 
    {
        free(matriz[i]);
    }
    free(matriz);
    
    free(vetorreg);
    
    for (i = 0; i < 100; i++) 
    {
        free(texto[i]);
    }
    free(texto);
    
    return 0;
}