import numpy as np

experimentos = 100000
p_defeito = 0.001

amostras = np.random.rand(experimentos, 3)
defeituosos = amostras < p_defeito
com_defeito = np.any(defeituosos, axis=1)
probabilidade = np.mean(com_defeito)

print("Resultado teórico: 0.3% de chance")
print(f"Resultado obtido após 100,000 experimentos: {probabilidade:.6f} de chance")
