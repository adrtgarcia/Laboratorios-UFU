package janelas;

import javax.swing.*;
import classes.MaterialBibliografico;

@SuppressWarnings("serial")
public class JanelaListagem extends JFrame {

	public JanelaListagem() {
		// criando a janela
		this.setTitle("Listagem");									// nome da janela
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		// encerrar o programa no x
		this.setSize(550, 250);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo		
		this.setLocationRelativeTo(null); 							// centralizar a janela
		
		// imprimindo o conteúdo do arraylist
		JTextArea arraylist = new JTextArea();
		arraylist.setText(MaterialBibliografico.listarMaterialBibliografico());		
				
		this.add(arraylist);										// adicionando o conteúdo na janela
		this.setVisible(true);										// janela visível
	}
}
