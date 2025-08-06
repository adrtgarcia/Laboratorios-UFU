import numpy as np
import random

experimentos = 100000
total_lancamentos = []

for i in range(experimentos):
    dado1 = random.randint(1, 6)
    lancamentos = 1

    while True:
        dado2 = random.randint(1, 6)
        lancamentos += 1
        if dado1 == dado2:
            break
        dado1 = dado2

    total_lancamentos.append(lancamentos)

numero_esperado = np.mean(total_lancamentos)

print("Resultado teórico: 7 lançamentos")
print(f"Resultado obtido após 100,000 experimentos: {numero_esperado:.5f} lançamentos")
