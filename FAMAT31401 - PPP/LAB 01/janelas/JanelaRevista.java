package janelas;

import javax.swing.*;
import classes.MaterialBibliografico;
import classes.Revista;
import java.awt.event.*;

@SuppressWarnings("serial")
public class JanelaRevista extends JFrame implements ActionListener {
	
	public JTextField campoTitulo;
	public JTextField campoOrganizacao;
	public JTextField campoVolume;
	public JTextField campoNumero;
	public JTextField campoAno;
	
	public JButton botaoIncluir;
	public JButton botaoLivros;
	public JButton botaoListagem;
		
	public JanelaRevista() {
		// criando a janela
		this.setTitle("Revistas");									// nome da janela
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		// encerrar o programa no x
		this.setSize(550, 250);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo		
		this.setLocationRelativeTo(null); 							// centralizar a janela
				
		// adicionando labels
		JLabel labelTitulo = new JLabel("Título: ");
		JLabel labelOrganizacao = new JLabel("Org.: ");
		JLabel labelVolume = new JLabel("Vol.: ");
		JLabel labelNumero = new JLabel("Nro.: ");
		JLabel labelAno = new JLabel("Ano: ");
		
		// adicionando campos de texto
		campoTitulo = new JTextField(41);
		campoOrganizacao = new JTextField(42);
		campoVolume = new JTextField(5);
		campoNumero = new JTextField(5);
		campoAno = new JTextField(5);
		
		// adicionando botões
		botaoIncluir = new JButton("Incluir");
		botaoIncluir.addActionListener(this);						// tratamento
		botaoLivros = new JButton("Livros");
		botaoLivros.addActionListener(this);						// tratamento
		botaoListagem = new JButton("Listagem");
		botaoListagem.addActionListener(this);						// tratamento
		
		// criando o panel e adicionando os componentes
		JPanel panel = new JPanel();
		panel.add(labelTitulo);
		panel.add(campoTitulo);
		panel.add(labelOrganizacao);
		panel.add(campoOrganizacao);
		panel.add(labelVolume);
		panel.add(campoVolume);
		panel.add(labelNumero);
		panel.add(campoNumero);
		panel.add(labelAno);
		panel.add(campoAno);
		panel.add(botaoIncluir);
		panel.add(botaoLivros);
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
						new Revista(campoTitulo.getText(), 
								campoOrganizacao.getText(), 
								Integer.parseInt(campoVolume.getText()), 
								Integer.parseInt(campoNumero.getText()), 
								Integer.parseInt(campoAno.getText()))
				);
				JOptionPane.showMessageDialog(null, "Revista incluída.");
				
			} catch(NumberFormatException error) {
				JOptionPane.showMessageDialog(null, "Não foi possível incluir esta revista.");
			}
						
			// limpando os campos de texto
			campoTitulo.setText("");
			campoOrganizacao.setText("");
			campoVolume.setText("");
			campoNumero.setText("");
			campoAno.setText("");
			
		} else if(e.getSource() == botaoLivros) {
			// trocando para a janela de livros
			this.dispose();
			new JanelaLivro();
			
		} else if(e.getSource() == botaoListagem) {
			// trocando para a janela de listagem
			this.dispose();
			new JanelaListagem();
		}
	}
}