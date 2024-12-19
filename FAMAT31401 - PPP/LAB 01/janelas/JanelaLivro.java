package janelas;

import javax.swing.*;
import classes.MaterialBibliografico;
import classes.Livro;
import java.awt.event.*;

@SuppressWarnings("serial")
public class JanelaLivro extends JFrame implements ActionListener {
	
	public JTextField campoTitulo;
	public JTextField campoAutor;
	public JTextField campoAno;
	
	public JButton botaoIncluir;
	public JButton botaoRevistas;
	public JButton botaoListagem;
		
	public JanelaLivro() {
		// criando a janela
		this.setTitle("Livros");									// nome da janela
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		// encerrar o programa no x
		this.setSize(550, 250);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo	
		this.setLocationRelativeTo(null); 							// centralizar a janela
				
		// adicionando labels
		JLabel labelTitulo = new JLabel("Título: ");
		JLabel labelAutor = new JLabel("Autor: ");
		JLabel labelAno = new JLabel("Ano: ");
		
		// adicionando campos de texto
		campoTitulo = new JTextField(41);
		campoAutor = new JTextField(31);
		campoAno = new JTextField(5);
		
		// adicionando botões
		botaoIncluir = new JButton("Incluir");
		botaoIncluir.addActionListener(this);						// tratamento
		botaoRevistas = new JButton("Revistas");
		botaoRevistas.addActionListener(this);						// tratamento
		botaoListagem = new JButton("Listagem");
		botaoListagem.addActionListener(this);						// tratamento
		
		// criando o panel e adicionando os componentes
		JPanel panel = new JPanel();
		panel.add(labelTitulo);
		panel.add(campoTitulo);
		panel.add(labelAutor);
		panel.add(campoAutor);
		panel.add(labelAno);
		panel.add(campoAno);
		panel.add(botaoIncluir);
		panel.add(botaoRevistas);
		panel.add(botaoListagem);		
		
		this.getContentPane().add(panel);							// adicionando panel na janela
		this.setVisible(true);										// janela visível
	}

	// tratamento de botões
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == botaoIncluir) {
			try {
				MaterialBibliografico.adicionarMaterialBibliografico(
						new Livro(campoTitulo.getText(), 
								campoAutor.getText(), 
								Integer.parseInt(campoAno.getText()))
				);
				JOptionPane.showMessageDialog(null, "Livro incluído.");
				
			} catch(NumberFormatException error) {
				JOptionPane.showMessageDialog(null, "Não foi possível incluir este livro.");
			}
			
			// limpando os campos de texto
			campoTitulo.setText("");
			campoAutor.setText("");
			campoAno.setText("");
			
		} else if(e.getSource() == botaoRevistas) {
			// trocando para a janela de revistas
			this.dispose();
			new JanelaRevista();
			
		} else if(e.getSource() == botaoListagem) {
			// trocando para a janela de listagem
			this.dispose();
			new JanelaListagem();
		}
	}
}