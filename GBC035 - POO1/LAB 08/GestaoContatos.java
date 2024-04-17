import java.util.ArrayList;

public class GestaoContatos {
  private ArrayList<Contato> contatos;

  public void adicionaContato(Contato contato) {
    contatos.add(contato);
  }
  
  public void eliminaContato(String nome) {
    int flag = 0;
    for (int i = 0; i < contatos.size(); i++) {
      if (contatos.get(i).getNome().equals(nome)) {
        contatos.remove(i);
        flag = 1;
        break;
      }
    }
    if (flag == 1) System.out.println("Contato excluído.");
    else System.out.println("Contato não encontrado.");
  }
  
  public void listaContatos() {
    System.out.println("\nLista de contatos:");
    for (Contato contato : contatos) {
      contato.toString();
      System.out.println();
    }
  }
  
  public Contato maisVelho() {
    int maisVelho = 0;
    for (int i = 0; i < contatos.size(); i++) {
      if (contatos.get(i).getIdade() > contatos.get(maisVelho).getIdade()) {
        maisVelho = i;
      }
    }
    return contatos.get(maisVelho);
  }
  
  public Contato maisNovo() {
    int maisNovo = 0;
    for (int i = 0; i < contatos.size(); i++) {
      if (contatos.get(i).getIdade() < contatos.get(maisNovo).getIdade()) {
        maisNovo = i;
      }
    }
    return contatos.get(maisNovo);
  }
}
