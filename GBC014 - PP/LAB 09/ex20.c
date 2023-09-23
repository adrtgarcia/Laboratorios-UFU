#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char nome[30];
    int posX;
    int posY;
} Cidade;

float calcularDistancia(Cidade cidade1, Cidade cidade2) 
{
    int deltaX = cidade1.posX - cidade2.posX;
    int deltaY = cidade1.posY - cidade2.posY;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

int main ( ) 
{
    int N;
    
    printf("Digite o número de cidades: ");
    scanf("%d", &N);
    
    Cidade* cidades = (Cidade*)malloc(N * sizeof(Cidade));
    float** matrizDistancias = (float**)malloc(N * sizeof(float*));
    
    for (int i = 0; i < N; i++) 
    {
        matrizDistancias[i] = (float*)malloc(N * sizeof(float));
    }

    for (int i = 0; i < N; i++) 
    {
        printf("Digite o nome da cidade %d: ", i + 1);
        scanf("%s", cidades[i].nome);
        
        printf("Digite a coordenada X da cidade %d: ", i + 1);
        scanf("%d", &cidades[i].posX);
        
        printf("Digite a coordenada Y da cidade %d: ", i + 1);
        scanf("%d", &cidades[i].posY);
        
        printf("\n");
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            matrizDistancias[i][j] = calcularDistancia(cidades[i], cidades[j]);
        }
    }

    printf("Matriz de distâncias:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%.2f\t", matrizDistancias[i][j]);
        }
        printf("\n");
    }

    int cidade1, cidade2;
    printf("\nDigite o número das duas cidades (entre 1 e %d): ", N);
    scanf("%d %d", &cidade1, &cidade2);
    
    if (cidade1 >= 1 && cidade1 <= N && cidade2 >= 1 && cidade2 <= N) 
    {
        float distancia = matrizDistancias[cidade1 - 1][cidade2 - 1];
        printf("A distância entre a cidade %d e a cidade %d é: %.2f\n", cidade1, cidade2, distancia);
    } else {
        printf("Cidades inválidas.\n");
    }
    
    free(cidades);
    
    for (int i = 0; i < N; i++) 
    {
        free(matrizDistancias[i]);
    }
    free(matrizDistancias);
    
    return 0;
}