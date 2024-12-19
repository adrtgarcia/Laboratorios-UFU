package classes;

import java.util.ArrayList;

public class MaterialBibliografico {
	private static ArrayList<MaterialBibliografico> materialBibliografico = new ArrayList<>();
	private String titulo;
	private int ano;

	// construtor
	public MaterialBibliografico(String titulo, int ano) {
		setTitulo(titulo);
	    setAno(ano);
	}

	// getters e setters
	public String getTitulo() {
	    return this.titulo;
	}

	public void setTitulo(String titulo) {
		// o título não pode ser NULL
	    if(titulo != null) this.titulo = titulo;
	}

	public int getAno() {
		return this.ano;
	}

	public void setAno(int ano) {
		// o ano deve ser um valor positivo
	    if(ano > 0) this.ano = ano;
	}

	// métodos
	public static String listarMaterialBibliografico() {
		if(materialBibliografico.isEmpty()) 
			return "Não há nenhum material bibliográfico cadastrado.";
		else {
			String str = "";
			for(MaterialBibliografico material : materialBibliografico) str = str + material.toString() + "\n";
			return str;
		}
	}

	public static void adicionarMaterialBibliografico(MaterialBibliografico material) {
	    // o material (livro ou revista) não pode ser NULL
	    if(material != null) materialBibliografico.add(material);
	}
}

