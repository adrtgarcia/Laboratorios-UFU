package classes;

public class Livro extends MaterialBibliografico {
	private String autor;
	
	// construtor
	public Livro(String titulo, String autor, int ano) { 
		super(titulo, ano);
		setAutor(autor);
	}
	
	// getter e setter
	public String getAutor() {
		return this.autor;
	}
	
	public void setAutor(String autor) {
	 // o nome do autor não pode ser NULL
	 if(autor != null) this.autor = autor;
	}

	// método
	@Override
	public String toString() {
		return "Livro: " 
				+ super.getTitulo() + ", " 
				+ getAutor() 
				+ " (" + super.getAno() + ")";
	}
}