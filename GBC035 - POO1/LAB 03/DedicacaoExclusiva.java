package laboratorios;

public class DedicacaoExclusiva extends Professores {
	
	private double salarioFixo;
	
	public DedicacaoExclusiva(String nome, String matricula, int idade, double salario) {
		super(nome, matricula, idade);
		setSalarioFixo(salario);
	}

	public double getSalarioFixo() {
		return salarioFixo;
	}

	public void setSalarioFixo(double salarioFixo) {
		this.salarioFixo = salarioFixo;
	}
	
}
