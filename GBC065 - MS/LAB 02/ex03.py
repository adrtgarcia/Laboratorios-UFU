import numpy as np

estado = np.random.choice([0, 1])
contagem = [0, 0]
experimentos = 100000

for i in range(experimentos):
    contagem[estado] += 1

    if estado == 0:
        estado = np.random.choice([0, 1], p=[0.8, 0.2])
    else:
        estado = np.random.choice([0, 1], p=[0.75, 0.25])

proporcao = [c / experimentos for c in contagem]

print("Resultado teórico:")
print("Carros na estrada = 78.95%")
print("Caminhões na estrada = 21.05%")

print("\nResultado obtido após 100,000 experimentos:")
print(f"Carros na estrada = {proporcao[0]:.5f}")
print(f"Caminhões na estrada = {proporcao[1]:.5f}")
