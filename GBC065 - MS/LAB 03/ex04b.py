import numpy as np

taxa_base = 1.0

Q = taxa_base * np.array([[-1, 1, 0, 0],
                          [0, -1, 0.5, 0.5],
                          [0, 0.5, -1, 0.5],
                          [2, 0, 0, -2]])

def simular_ctmc(Q, tempo_total=10000.0, estado_inicial=0, semente=None):
    rng = np.random.default_rng(semente)
    num_estados = Q.shape[0]
    estado_atual = estado_inicial
    tempo = 0.0
    tempo_estados = np.zeros(num_estados)

    while tempo < tempo_total:
        taxa_saida = -Q[estado_atual, estado_atual]
        duracao = rng.exponential(1.0 / taxa_saida)

        if tempo + duracao > tempo_total:
            tempo_estados[estado_atual] += (tempo_total - tempo)
            break

        tempo_estados[estado_atual] += duracao

        probabilidades = Q[estado_atual, :].copy()
        probabilidades[estado_atual] = 0.0
        probabilidades = probabilidades / probabilidades.sum()

        estado_atual = rng.choice(num_estados, p=probabilidades)

        tempo += duracao

    distribuicao_estimada = tempo_estados / tempo_total
    return distribuicao_estimada

pi_estimado = simular_ctmc(Q, tempo_total=20000.0, semente=42)
print("Distribuição estimada via Monte Carlo:", pi_estimado)
print("Distribuição teórica: [2/7, 8/21, 4/21, 1/7] ≈ ", [2/7, 8/21, 4/21, 1/7])
