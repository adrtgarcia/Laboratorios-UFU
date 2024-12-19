package classes;

public class Revista extends MaterialBibliografico {
	private String organizacao;
	private int volume;
	private int numero;
	
	// construtor
	public Revista(String titulo, String organizacao, int  volume, int numero, int ano) {
		super(titulo, ano);
		setOrganizacao(organizacao);
		setVolume(volume);
		setNumero(numero);
	}
	
	// getters e setters
	public String getOrganizacao() {
		return this.organizacao;
	}
	
	public void setOrganizacao(String organizacao) {
		// o nome da organização não pode ser NULL
		if(organizacao != null) this.organizacao = organizacao;
	}

	public int getVolume() {
		return this.volume;
	}

	public void setVolume(int volume) {
		// o volume deve ser um valor positivo
		if(volume > 0) this.volume = volume;
	}

	public int getNumero() {
		return this.numero;
	}

	public void setNumero(int numero) {
		// o número deve ser um valor positivo
		if(numero > 0) this.numero = numero;
	}
	
	// método
	@Override
	public String toString() {
		return "Revista: " 
				+ super.getTitulo() + ", "
				+ getOrganizacao() 
				+ " - Vol. " + getVolume() + ", "
				+ "Nro. " + getNumero()
				+ " (" + super.getAno() + ")";
	}
}