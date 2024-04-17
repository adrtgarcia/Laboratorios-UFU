public class Vendedor extends Funcionario {
  private double comissao;
  private int totalVendas;

  public Vendedor(String nome, String rg, double salarioBase) {
    super(nome, rg, salarioBase);
    setComissao(0.05);
    setTotalVendas(0);
  }

  public void setComissao(double comissao) {
    this.comissao = comissao;
  }

  public double getComissao() {
    return this.comissao;
  }

  public void setTotalVendas(int totalVendas) {
    this.totalVendas = totalVendas;
  }

  public int getTotalVendas() {
    return this.totalVendas;
  }

  public void adicionaVenda(int numVendas) {
    this.totalVendas += numVendas;
  }

  public double salarioTotal() {
    return getSalarioBase() + (getComissao() * getTotalVendas());
  }

  public void zerarVendar() {
    this.totalVendas = 0;
  }

}
