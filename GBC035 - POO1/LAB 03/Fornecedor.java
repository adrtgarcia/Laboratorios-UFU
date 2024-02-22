package laboratorios;

public class Fornecedor extends Pessoa {
	private String cnpj;
	private String enderecoEmpresa;
	
	public Fornecedor(String nome, String sobrenome, int idade, String rg, String lugarNascimento, String cnpj, String enderecoEmpresa) {
		super(nome, sobrenome, idade, rg, lugarNascimento);
		setCnpj(cnpj);
		setEnderecoEmpresa(enderecoEmpresa);
	}
	
	public Fornecedor() {
		
	}

	public String getCnpj() {
		return cnpj;
	}

	public void setCnpj(String cnpj) {
		this.cnpj = cnpj;
	}

	public String getEnderecoEmpresa() {
		return enderecoEmpresa;
	}

	public void setEnderecoEmpresa(String enderecoEmpresa) {
		this.enderecoEmpresa = enderecoEmpresa;
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
		System.out.println("CNPJ: " + getCnpj());
		System.out.println("Endereço da empresa: " + getEnderecoEmpresa());
	}
}
