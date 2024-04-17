public class Contato {
  private String nome;
  private int idade;
  private String sexo;
  private String profissao;
  private String telefone;
  private String email;

  public Contato(String nome, int idade, String sexo, String profissao, String telefone, String email) {
    setNome(nome);
    setIdade(idade);
    setSexo(sexo);
    setProfissao(profissao);
    setTelefone(telefone);
    setEmail(email);
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public int getIdade() {
    return idade;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }

  public String getSexo() {
    return sexo;
  }

  public void setSexo(String sexo) {
    this.sexo = sexo;
  }

  public String getProfissao() {
    return profissao;
  }

  public void setProfissao(String profissao) {
    this.profissao = profissao;
  }

  public String getTelefone() {
    return telefone;
  }

  public void setTelefone(String telefone) {
    this.telefone = telefone;
  }

  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public String toString() {
    return (nome + ", " + idade + " anos de idade, do sexo " + sexo + ", " + profissao + ", telefone nº " + telefone + ", email: " + email);
  }
}
