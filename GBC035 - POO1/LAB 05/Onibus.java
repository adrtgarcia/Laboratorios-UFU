public class Onibus extends Veiculo{
	private int assentos;
	
	public Onibus(String placa, int ano, int assentos) {
		setPlaca(placa);
		setAno(ano);
		setAssentos(assentos);
	}

	public int getAssentos() {
		return assentos;
	}
	public void setAssentos(int assentos) {
		this.assentos = assentos;
	}
	
	public void exibirDados() {
		System.out.println("placa: " + getPlaca());
		System.out.println("ano: " + getAno());
		System.out.println("assentos: " + getAssentos());
	}
}
