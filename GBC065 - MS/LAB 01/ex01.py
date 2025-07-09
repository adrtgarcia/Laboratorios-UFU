import numpy as np
import random

# estados: 0 = bigmac, 1 = fritas, 2 = milkshake
estados = ['bigmac', 'fritas', 'milkshake']
matriz_transicao = np.array([ [0, 0.5, 0.5],
                              [0.5, 0, 0.5],
                              [0.5, 0.5, 0] ])

passos = 5
inicio = np.array([1, 0, 0])
prob_exata = [inicio[0]]  # P(X0 = bigmac | X0 = bigmac) = 1

v = inicio.copy()
for i in range(1, passos + 1):
    v = v @ matriz_transicao
    prob_exata.append(v[0])  # P(Xn = bigmac)

def monte_carlo(n, simulacoes=100_000):
    cont = 0
    for i in range(simulacoes):
        atual = 0  # bigmac
        for j in range(n):
            opcoes = [i for i in range(3) if i != atual]
            atual = random.choice(opcoes)
        if atual == 0:
            cont += 1
    return cont / simulacoes

prob_simulada = [monte_carlo(n) for n in range(passos + 1)]

for n in range(passos + 1):
    print(f"n = {n}:")
    print(f"  Exato:     P(Xn=bigmac | X0=bigmac) = {prob_exata[n]:.4f}")
    print(f"  Simulado:  P(Xn=bigmac | X0=bigmac) ≈ {prob_simulada[n]:.4f}")
    print()

autovalores, autovetores = np.linalg.eig(matriz_transicao.T)
estacionaria = np.real(autovetores[:, np.isclose(autovalores, 1)])
estacionaria = estacionaria / estacionaria.sum()
print("Distribuição estacionária:")
for i, p in enumerate(estacionaria.flatten()):
    print(f"  P({estados[i]}) = {p:.4f}")
