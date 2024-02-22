package laboratorios;

public class Circulo {
	private String nome;
	private Ponto centro;
	private double raio;
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		if (nome != null) this.nome = nome;
	}

	public Ponto getCentro() {
		return centro;
	}
	
	public void setCentro(Ponto centro) {
		this.centro = centro;
	}

	public double getRaio() {
		return raio;
	}
	
	public void setRaio(double raio) {
		this.raio = raio;
	}
	
	public void inicializarCirculo(double raio, Ponto centro) {
		setRaio(raio);
		setCentro(centro);
	}

	public double calcDiametro(double r) {
		double diametro = 2 * r;
		return diametro;
	}
	
	public double calcArea(double r) {
		double area = 3.14 * (r * r);
		return area;
	}
	
	public double calcCircunferencia(double r) {
		double circunferencia = 2 * 3.14 * r;
		return circunferencia;
	}
	
	public void alterarNome(String nome) {
		setNome(nome);
	}
	
	public void exibirDados() {
		System.out.println("nome: " + getNome());
		System.out.println("centro: " + getCentro());
		System.out.println("raio: " + getRaio());
		System.out.println("diâmetro: " + calcDiametro(getRaio()));
		System.out.println("área: " + calcArea(getRaio()));
		System.out.println("circunferência: " + calcCircunferencia(getRaio()));
	}
}
