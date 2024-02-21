package laboratorios;

public class Conta {
	private String nome;
	private int numConta;
	private String senha;
	private double saldo;

	public Conta (String nome, int numConta, String senha, double saldo) {
		setNome(nome);
		setNumConta(numConta);
		setSenha(senha);
		setSaldo(500);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getNumConta() {
		return numConta;
	}

	public void setNumConta(int numConta) {
		this.numConta = numConta;
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}

	public double getSaldo() {
		return saldo;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}
}
