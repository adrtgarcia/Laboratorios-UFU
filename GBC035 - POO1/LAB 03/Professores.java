package laboratorios;

public class Professores {

	protected String nome;
	protected String matricula;
	protected int idade;
	
	public Professores(String nome, String matricula, int idade) {
		setNome(nome);
		setMatricula(matricula);
		setIdade(idade);
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getMatricula() {
		return matricula;
	}
	
	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	
	public int getIdade() {
		return idade;
	}
	
	public void setIdade(int idade) {
		this.idade = idade;
	}
	
}
