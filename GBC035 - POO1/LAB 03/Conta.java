package laboratorios;

public class Conta {
	protected String cpf;
	protected int numConta;
	protected double saldo;
	
	public Conta(String cpf, int numConta, double saldo) {
		setCpf(cpf);
		setNumConta(numConta);
		setSaldo(saldo);
	}
	
	public String getCpf() {
		return cpf;
	}
	
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	
	public int getNumConta() {
		return numConta;
	}
	
	public void setNumConta(int numConta) {
		this.numConta = numConta;
	}
	
	public double getSaldo() {
		return saldo;
	}
	
	public void setSaldo(double saldo) {
		if (saldo >= 0) this.saldo = saldo;
		else this.saldo = 0;
	}
	
	public void saque(double valor) {
		if (valor <= saldo) saldo -= valor;
		else System.out.println("Saldo insuficiente");
	}
	
	public void deposito(double valor) {
		if (valor >= 0) saldo += valor;
		else System.out.println("Valor inválido");
	}
}
