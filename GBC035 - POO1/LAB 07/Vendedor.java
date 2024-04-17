public class Vendedor extends Funcionario {
  private double comissao;

  public Vendedor(String nome, String matricula, double salarioBase, double comissao) {
    super(nome, matricula, salarioBase);
    setComissao(comissao);
  }

  public void setComissao(double comissao) {
    this.comissao = comissao;
  }

  public double getComissao() {
    return this.comissao;
  }

  public double calculaSalario() {
    return getSalarioBase() + getComissao();
  }

  public void mostrarDados() {
    System.out.println("Nome: " + getNome());
    System.out.println("Matrícula: " + getMatricula());
    System.out.println("Cargo: Vendedor");
    System.out.println("Salário base: " + getSalarioBase());
    System.out.println("Salário total: " + calculaSalario());
  }
}
