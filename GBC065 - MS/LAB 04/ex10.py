import numpy as np
import math

def calcular_estado_estacionario():
    gamma1 = 115  # Chegada externa para A
    gamma2 = 140  # Chegada externa para C

    config = {
        'A': [1, 150],
        'B': [3, 120],
        'C': [1, 240],
        'D': [4, 80],
        'E': [1, 80]
    }

    lambda_A = gamma1
    lambda_B = 0.25 * lambda_A
    lambda_C = gamma2 + 0.75 * lambda_A + 0.70 * lambda_B
    lambda_D = 0.30 * lambda_B
    lambda_E = lambda_C

    lambdas = {
        'A': lambda_A,
        'B': lambda_B,
        'C': lambda_C,
        'D': lambda_D,
        'E': lambda_E
    }

    print(f"λA = {lambda_A}")
    print(f"λB = {lambda_B}")
    print(f"λC = {lambda_C}")
    print(f"λD = {lambda_D}")
    print(f"λE = {lambda_E}")
    print()

    resultados_filas = {}

    for fila in ['A', 'B', 'C', 'D', 'E']:
        c, mu_individual = config[fila]
        lam = lambdas[fila]
        mu_total = c * mu_individual
        rho = lam / mu_total
        a = lam / mu_individual

        print(f"Tipo: M/M/{c}")
        print(f"λ = {lam}, μ_total = {mu_total}, ρ = {rho:.6f}")
        print()

        if rho >= 1:
            print(f"Fila {fila} é instável (ρ ≥ 1)")
            return None

        if c == 1:  # M/M/1
            P0 = 1 - rho
            L = rho / (1 - rho)
            Lq = rho**2 / (1 - rho)
            W = 1 / (mu_total - lam)
            Wq = rho / (mu_total - lam)
            Pc = rho

        else:  # M/M/c
            sum1 = sum((a**n) / math.factorial(n) for n in range(c))
            sum2 = (a**c) / (math.factorial(c) * (1 - rho))
            P0 = 1 / (sum1 + sum2)

            Pc = ((a**c) / math.factorial(c)) * P0 / (1 - rho)

            Lq = Pc * rho / (1 - rho)
            L = Lq + a
            W = L / lam
            Wq = Lq / lam

        resultados_filas[fila] = {
            'lambda': lam,
            'rho': rho,
            'L': L,
            'Lq': Lq,
            'W': W,
            'Wq': Wq,
            'P0': P0,
            'Pc': Pc,
            'servidores': c,
            'mu_total': mu_total
        }

        print(f"ESTADO ESTACIONÁRIO - NÚMERO DE CLIENTES:")
        print(f"  L = {L:.6f} clientes")
        print(f"  Lq = {Lq:.6f} clientes")
        print(f"  Em atendimento = {L - Lq:.6f} clientes")
        print(f"  P0 = {P0:.6f}")
        print()

        print(f"ESTADO ESTACIONÁRIO - TEMPO DE ESPERA:")
        print(f"  W = {W:.6f} unidades de tempo")
        print(f"  Wq = {Wq:.6f} unidades de tempo")
        print(f"  Probabilidade de esperar = {Pc:.6f}")
        print()

    L_total = sum(resultados_filas[fila]['L'] for fila in ['A', 'B', 'C', 'D', 'E'])
    Lq_total = sum(resultados_filas[fila]['Lq'] for fila in ['A', 'B', 'C', 'D', 'E'])
    atendimento_total = L_total - Lq_total

    gamma_total = gamma1 + gamma2
    W_rede = L_total / gamma_total
    Wq_rede = Lq_total / gamma_total

    print("ESTADO ESTACIONÁRIO - NÚMERO DE CLIENTES NA REDE:")
    print(f"Total no sistema = {L_total:.6f} clientes")
    print(f"Total em filas = {Lq_total:.6f} clientes")
    print(f"Total em atendimento = {atendimento_total:.6f} clientes")
    print()

    print("ESTADO ESTACIONÁRIO - TEMPO DE ESPERA NA REDE:")
    print(f"Tempo médio total no sistema: {W_rede:.6f} unidades")
    print(f"Tempo médio total em filas: {Wq_rede:.6f} unidades")
    print(f"Tempo médio em atendimento: {W_rede - Wq_rede:.6f} unidades")
    print()

    return {
        'filas': resultados_filas,
        'rede': {
            'L_total': L_total,
            'Lq_total': Lq_total,
            'W_rede': W_rede,
            'Wq_rede': Wq_rede,
            'gamma_total': gamma_total
        }
    }

if __name__ == "__main__":

    resultados = calcular_estado_estacionario()
