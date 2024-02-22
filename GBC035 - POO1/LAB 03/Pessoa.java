package laboratorios;

public class Pessoa {
	private String nome;
	private String sobrenome;
	private int idade;
	private String rg;
	private String lugarNascimento;
	
	public Pessoa(String nome, String sobrenome, int idade, String rg, String lugarNascimento) {
		setNome(nome);
		setSobrenome(sobrenome);
		setIdade(idade);
		setRg(rg);
		setLugarNascimento(lugarNascimento);
	}
	
	public Pessoa() {
		
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getSobrenome() {
		return sobrenome;
	}
	
	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}
	
	public int getIdade() {
		return idade;
	}
	
	public void setIdade(int idade) {
		this.idade = idade;
	}
	
	public String getRg() {
		return rg;
	}
	
	public void setRg(String rg) {
		this.rg = rg;
	}
	
	public String getLugarNascimento() {
		return lugarNascimento;
	}
	
	public void setLugarNascimento(String lugarNascimento) {
		this.lugarNascimento = lugarNascimento;
	}
	
}
