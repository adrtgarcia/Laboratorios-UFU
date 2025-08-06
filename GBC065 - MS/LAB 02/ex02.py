import numpy as np

mat = np.array([ [0.6, 0.4, 0.0],
                           [0.1, 0.6, 0.3],
                           [0.0, 0.2, 0.8] ])

simulacoes = 100000
transicoes = 100
estados_finais = np.zeros(3)

for i in range(simulacoes):
    estado_atual = np.random.choice([0, 1, 2])

    for j in range(transicoes):
        estado_atual = np.random.choice([0, 1, 2], p = mat[estado_atual])

    estados_finais[estado_atual] += 1

proporcao = estados_finais / simulacoes

print("Resultado teórico:")
print("Não-Desejável = 0.1")
print("Satisfatório = 0.36")
print("Preferencial = 0.54")

print("\nResultado obtido após 100,000 experimentos:")
print(f"Não-Desejável = {proporcao[0]:.5f}")
print(f"Satisfatório = {proporcao[1]:.5f}")
print(f"Preferencial = {proporcao[2]:.5f}")
