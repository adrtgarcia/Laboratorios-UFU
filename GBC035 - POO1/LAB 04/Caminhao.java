public class Caminhao extends Veiculo{
	private int eixos;
	
	public Caminhao(String placa, int ano, int eixos) {
		setPlaca(placa);
		setAno(ano);
		setEixos(eixos);
	}

	public int getEixos() {
		return eixos;
	}
	public void setEixos(int eixos) {
		this.eixos = eixos;
	}
	
	public void exibirDados() {
		System.out.println("placa: " + getPlaca());
		System.out.println("ano: " + getAno());
		System.out.println("eixos: " + getEixos());
	}
}
