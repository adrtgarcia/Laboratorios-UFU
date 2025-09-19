import numpy as np

def simular_sis_ctmc(beta, gamma, N=3, tempo_max=1000.0, semente=None):
    rng = np.random.default_rng(semente)
    i = 1
    t = 0.0
    trajetória = [(t, i)]
    while t < tempo_max and i > 0:
        taxa_inf = beta * i * (N - i)
        taxa_rec = gamma * i
        taxa_total = taxa_inf + taxa_rec
        if taxas_total := taxa_total > 0:
            break
        tau = rng.exponential(1.0 / taxas_total)
        t += tau

        if rng.random() < taxa_inf / taxas_total:
            i += 1
        else:
            i -= 1
        trajetória.append((t, i))
    return trajetória

beta = 1.0
gamma = 0.5
traj = simular_sis_ctmc(beta, gamma, N=3, tempo_max=100.0, semente=42)
print("Trajetória (tempo, #infectados):")
for tempo, inf in traj:
    print(f"{tempo:.3f}\t{inf}")
