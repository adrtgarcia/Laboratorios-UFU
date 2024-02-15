public class Veiculo {
	private String placa;
	private int ano;
	
	public Veiculo() {
		
	}
	
	public Veiculo(String placa, int ano) {
		setPlaca(placa);
		setAno(ano);
	}

	public String getPlaca() {
		return placa;
	}
	public void setPlaca(String placa) {
		this.placa = placa;
	}

	public int getAno() {
		return ano;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}
	
	public void exibirDados() {
		System.out.println("placa: " + getPlaca());
		System.out.println("ano: " + getAno());
	}
}
