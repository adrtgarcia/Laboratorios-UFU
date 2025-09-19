import numpy as np
import math

lambda_falha = 1/10.0
mu_reparo = 1/2.0
R = mu_reparo / lambda_falha

def pi_exata(mu, lamb, max_k=4):
    r = mu / lamb
    termos = [r**k / math.factorial(k) for k in range(max_k+1)]
    S = sum(termos)
    pi0 = 1.0 / S
    pis = [pi0 * termos[k] for k in range(max_k+1)]
    return pis

pis = pi_exata(mu_reparo, lambda_falha, max_k=4)
esperanca = sum(k * pis[k] for k in range(5))

print("Prob. estacionárias:", pis)
print("Esperança:", esperanca)

def simular_ctmc_maquinas(lambda_falha, mu_reparo, tempo_total=1e5, estado_inicial=4, semente=None):
    rng = np.random.default_rng(semente)
    k = estado_inicial
    t = 0.0
    tempo_em_estados = np.zeros(5)
    while t < tempo_total:
        taxa_falha = k * lambda_falha
        taxa_reparo = mu_reparo if k <= 3 else 0.0
        taxa_total = taxa_falha + taxa_reparo
        if taxa_total <= 0:
            break

        tau = rng.exponential(1.0 / taxa_total)
        if t + tau > tempo_total:
            tempo_em_estados[k] += (tempo_total - t)
            break
        tempo_em_estados[k] += tau

        p_reparo = taxa_reparo / taxa_total
        if rng.random() < p_reparo:
            k += 1
        else:
            k -= 1
        t += tau
    proporcoes = tempo_em_estados / tempo_total
    return proporcoes, sum(i*proporcoes[i] for i in range(5))

pi_mc, esperanca_mc = simular_ctmc_maquinas(lambda_falha, mu_reparo, tempo_total=200000.0, semente=12345)
print("Fração do tempo em cada estado:", pi_mc)
print("Esperança):", esperanca_mc)
