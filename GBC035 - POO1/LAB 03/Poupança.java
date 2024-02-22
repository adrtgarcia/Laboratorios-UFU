package laboratorios;

public class Poupança extends Conta {
	private static double taxaRendMensal = 0.25;
	
	public Poupança(String cpf, int numConta, double saldo) {
		super(cpf, numConta, saldo);
	}
	
	public double calcularNovoSaldo() {
		saldo = saldo + (saldo * taxaRendMensal);
		return saldo;
	}
}
