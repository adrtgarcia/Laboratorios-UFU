public class Conta {
	private double saldo;
	
	public double getSaldo() {
		return saldo;
	}
	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	public double verSaldo () {
		return getSaldo();
	}
	
	public void alteraSaldo(double valor) {
		setSaldo(valor);
	}
	
	public void credito(double valor) {
		if (valor >= 0)
			setSaldo(getSaldo() + valor);
	}
	
	public void debita(double valor) {
		if ((valor >= 0) && (valor <= getSaldo()))
			setSaldo(getSaldo() - valor);
	}
}
