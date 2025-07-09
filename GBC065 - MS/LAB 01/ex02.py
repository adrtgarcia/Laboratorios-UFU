import numpy as np
import random

cidades = ["Averagemont", "Discretown", "Bayesville", "Continuopolis", "East Vandermonde"]

A, D, B, C, E = 0, 1, 2, 3, 4

matriz_transicao = np.array([ [0, 1/3, 1/3, 1/3, 0],
                              [1/2, 0, 1/2, 0, 0],
                              [1/4, 1/4, 0, 1/4, 1/4],
                              [1/2, 0, 1/2, 0, 0],
                              [0, 0, 1, 0, 0] ])

def caminhada(matriz, estado_inicial, etapas):
    estado = estado_inicial
    visitas = np.zeros(len(cidades))
    for i in range(etapas):
        visitas[estado] += 1
        transicoes = matriz[estado]
        estado = np.random.choice(len(cidades), p=transicoes)
    return visitas / etapas

etapas = 100_000
distribuicao = caminhada(matriz_transicao, estado_inicial=B, etapas=etapas)

print("Distribuição aproximada após", etapas, "passos:")
for i, prob in enumerate(distribuicao):
    print(f"{cidades[i]}: {prob:.4f}")
