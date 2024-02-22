package laboratorios;

public class Cliente extends Pessoa {
	private String cpf;
	private String endereco;
	
	public Cliente(String nome, String sobrenome, int idade, String rg, String lugarNascimento, String cpf, String endereco) {
		super(nome, sobrenome, idade, rg, lugarNascimento);
		setCpf(cpf);
		setEndereco(endereco);
	}
	
	public Cliente() {
		
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	
	public void infoPessoal() {
		System.out.println("Nome: " + getNome());
		System.out.println("Sobrenome: " + getSobrenome());
		System.out.println("Idade: " + getIdade());
		System.out.println("RG: " + getRg());
		System.out.println("Lugar de nascimento: " + getLugarNascimento());
	}
	
	public void info() {
		System.out.println("Nome: " + getNome());
		System.out.println("Sobrenome: " + getSobrenome());
		System.out.println("Idade: " + getIdade());
		System.out.println("RG: " + getRg());
		System.out.println("Lugar de nascimento: " + getLugarNascimento());
		System.out.println("CPF: " + cpf);
		System.out.println("Endereço: " + endereco);
	}
	
}
