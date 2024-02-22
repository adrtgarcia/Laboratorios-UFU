package laboratorios;

public class Especial extends Conta {
	private double limite;
	
	public Especial (String cpf, int numConta, double saldo, double limite) {
		super(cpf, numConta, saldo);
		setLimite(limite);
	}
	
	public double getLimite() {
		return limite;
	}
	
	public void setLimite(double limite) {
		if (limite >= 0) this.limite = limite;
		else this.limite = 0;
	}
	
	public void saque(double valor) {
		if (valor >= 0) {
			if ((valor > saldo) && (limite > 0)) {
				saldo -= valor;
				setLimite(limite += saldo);
				setSaldo(saldo);
			} else if (valor <= saldo) saldo -= valor;
		} else System.out.println("Valor inválido");
	}

}
