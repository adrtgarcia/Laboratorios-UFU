import numpy as np

def resolver_sistema_spa(lam, mu0, mu1):

    print(f"Taxa de chegada (λ): {lam}")
    print(f"Taxa de serviço - Massagem (μ0): {mu0}")
    print(f"Taxa de serviço - Acupuntura (μ1): {mu1}")
    print()

    p0, p1, p2, p3 = sp.symbols('p0 p1 p2 p3', real=True, positive=True)

    eq1 = sp.Eq(lam * p0, mu1 * p2)
    eq2 = sp.Eq(lam * p0, mu0 * p1)
    eq3 = sp.Eq(mu0 * p1, (lam + mu1) * p2)
    eq4 = sp.Eq(lam * p2, (mu0 + mu1) * p3)

    eq5 = sp.Eq(p0 + p1 + p2 + p3, 1)

    p2_expr = (lam/mu1) * p0
    p1_expr = (lam/mu0) * p0

    left_side = mu0 * p1_expr
    right_side = (lam + mu1) * p2_expr

    p3_expr = (lam/(mu0 + mu1)) * p2_expr
    p3_expr = (lam**2)/((mu0 + mu1)*mu1) * p0

    coef_total = 1 + lam/mu0 + lam/mu1 + (lam**2)/((mu0 + mu1)*mu1)

    p0_val = 1/coef_total
    p1_val = (lam/mu0) * p0_val
    p2_val = (lam/mu1) * p0_val
    p3_val = (lam**2)/((mu0 + mu1)*mu1) * p0_val

    prop_entrada = p0_val

    media_clientes = 0*p0_val + 1*p1_val + 1*p2_val + 2*p3_val

    lam_efetivo = lam * prop_entrada
    tempo_medio = media_clientes / lam_efetivo

    prob_esperar = p3_val / (p1_val + p2_val + p3_val)

    return {
        'probabilidades': {'p0': p0_val, 'p1': p1_val, 'p2': p2_val, 'p3': p3_val},
        'prop_entrada': prop_entrada,
        'media_clientes': media_clientes,
        'tempo_medio': tempo_medio,
        'frac_espera': prob_esperar,
        'lambda_efetivo': lam_efetivo
    }

if __name__ == "__main__":
    lam = 2.0    # Taxa de chegada
    mu0 = 3.0    # Taxa de serviço da massagem
    mu1 = 4.0    # Taxa de serviço da acupuntura

    resultados = resolver_sistema_spa(lam, mu0, mu1)

    print(f"1. Proporção de clientes que entra: {resultados['prop_entrada']:.4f} ({resultados['prop_entrada']*100:.2f}%)")
    print(f"2. Média de clientes no spa: {resultados['media_clientes']:.4f} clientes")
    print(f"3. Tempo médio no spa: {resultados['tempo_medio']:.4f} unidades de tempo")
    print(f"4. Fração que espera (μb): {resultados['frac_espera']:.4f} ({resultados['frac_espera']*100:.2f}%)")
