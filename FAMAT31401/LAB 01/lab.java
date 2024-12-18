package classes;

import java.util.ArrayList;

// classe mãe para o controle do material bibliotecário
// contém os atributos comuns a livros e revistas

public class Material {
	private ArrayList<Material> materialBibliotecario = new ArrayList<Material>();
	private String titulo;
	private int ano;
	
	// construtor
	public Material(String titulo, int ano) {
		setTitulo(titulo);
		setAno(ano);
	}

	// getters e setters
	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		// o título não pode ser NULL
		if(titulo != null) this.titulo = titulo; 
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		// o ano não pode ser um número negativo
		if(ano > 0) this.ano = ano;
	}
	
	// métodos
	public void adicionarLivro(Livro livro) {
		if(livro != null) materialBibliotecario.add(livro);
	}
	
	public void adicionarRevista(Revista revista) {
		if(revista != null) materialBibliotecario.add(revista);
	}
	
	public void listarMaterialBibliotecario() {
		for(Material material : materialBibliotecario) {
			
		}
	}
	
}


package classes;

// classe filha de material
// contém os atributos exclusivos de livros

public class Livro extends Material {
	private String autor;
	
	// construtor
	public Livro(String titulo, String autor, int ano) {
		super(titulo, ano);
		this.autor = autor;
	}

	// getter e setter
	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		// o autor não pode ser NULL
		if(autor != null) this.autor = autor;
	}
	
}



package classes;
// classe filha de material
// contém os atributos exclusivos de revistas

public class Revista extends Material {
	private String organizacao;
	private int volume;
	private int numero;

	// construtor
	public Revista(String titulo, String organizacao, int volume, int numero, int ano) {
		super(titulo, ano);
		setOrganizacao(organizacao);
		setVolume(volume);
		setNumero(numero);
	}

	// getters e setters
	public String getOrganizacao() {
		return organizacao;
	}

	public void setOrganizacao(String organizacao) {
		// a organização não pode ser NULL
		if(organizacao != null) this.organizacao = organizacao;
	}

	public int getVolume() {
		return volume;
	}

	public void setVolume(int volume) {
		// o volume deve ser um valor positivo
		if(volume > 0) this.volume = volume;
	}
	
	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		// o número deve ser um valor positivo
		if(numero > 0) this.numero = numero;
	}
	
}



package janelas;

import javax.swing.*;
import java.awt.*;

public class JanelaLivro extends JFrame {
	public JanelaLivro() {
		// criando a janela
		JFrame janela = new JFrame("Livros");
		janela.setSize(300, 100);
		
		// campos de texto
		JLabel titulo = new JLabel("Título: ");
		JTextField campoTitulo = new JTextField(100);
	
		JLabel autor = new JLabel("Autor: ");
		JTextField campoAutor = new JTextField(100);
		
		JLabel ano = new JLabel("Ano: ");
		JTextField campoAno = new JTextField(5);
		
		// botões da janela
		JButton botaoIncluir = new JButton("Incluir");
		JButton botaoRevistas = new JButton("Revistas");
		JButton botaoListagem = new JButton("Listagem");
		
		// criando painel
		JPanel painel = new JPanel();
		painel.add(titulo);
		painel.add(campoTitulo);
		painel.add(autor);
		painel.add(campoAutor);
		painel.add(ano);
		painel.add(campoAno);
		painel.add(botaoIncluir);
		painel.add(botaoRevistas);
		painel.add(botaoListagem);
		
		// tratamento dos botões
		botaoIncluir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// adicionar o livro no arraylist
				adicionarLivro();
			}
		});
			
		botaoRevistas.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// chamar a janela de revistas
			}
		});
		
		botaoListagem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// chamar a janela de listagem
			}
		});
		
	}
	
}



package janelas;

import javax.swing.*;
import java.awt.*;

public class JanelaRevista extends JFrame {
	public JanelaRevista() {
		// criando a janela
		JFrame janela = new JFrame("Revistas");
		janela.setSize(300, 100);
		
		// campos de texto
		JLabel titulo = new JLabel("Título: ");
		JTextField campoTitulo = new JTextField(100);
	
		JLabel organizacao = new JLabel("Org.: ");
		JTextField campoOrganizacao = new JTextField(100);
		
		JLabel volume = new JLabel("Vol.: ");
		JTextField campoVolume = new JTextField(5);
		
		JLabel numero = new JLabel("Nro.: ");
		JTextField campoNumero = new JTextField(5);
		
		JLabel ano = new JLabel("Ano: ");
		JTextField campoAno = new JTextField(5);
		
		// botões da janela
		JButton botaoIncluir = new JButton("Incluir");
		JButton botaoLivros = new JButton("Livros");
		JButton botaoListagem = new JButton("Listagem");
		
		// criando painel
		JPanel painel = new JPanel();
		painel.add(titulo);
		painel.add(campoTitulo);
		painel.add(organizacao);
		painel.add(campoOrganizacao);
		painel.add(volume);
		painel.add(campoVolume);
		painel.add(numero);
		painel.add(campoNumero);
		painel.add(ano);
		painel.add(campoAno);
		painel.add(botaoIncluir);
		painel.add(botaoLivros);
		painel.add(botaoListagem);
		
		// tratamento dos botões
		botaoIncluir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// adicionar o livro no arraylist
				adicionarLivro();
			}
		});
			
		botaoRevistas.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// chamar a janela de revistas
			}
		});
		
		botaoListagem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// chamar a janela de listagem
			}
		});
		
	}
	
}




package janelas;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class JanelaListagem {
	public JanelaListagem() {
		// criando a janela
		JFrame janela = new JFrame("Listagem");
		janela.setSize(300, 100);
		
		// campos de texto
		
		
		// criando painel
		JPanel painel = new JPanel();
		painel.add(titulo);
		
		
		// tratamento dos botões
		
		
	}
	
}
