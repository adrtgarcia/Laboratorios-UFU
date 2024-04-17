public abstract class Funcionario {
  private String nome;
  private String rg;
  private double salarioBase;

  public Funcionario(String nome, String rg, double salarioBase) {
    setNome(nome);
    setRg(rg);
    setSalarioBase(salarioBase);
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setRg(String rg) {
    this.rg = rg;
  }

  public void setSalarioBase(double salarioBase) {
    this.salarioBase = salarioBase;
  }

  public String getNome() {
    return this.nome;
  }

  public String getRg() {
    return this.rg;
  }

  public double getSalarioBase() {
    return this.salarioBase;
  }

  public abstract double salarioTotal() {
    return salarioBase;
  }
}
