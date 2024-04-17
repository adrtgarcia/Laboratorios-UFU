public class Administrativo extends Funcionario {
  private int horaExtra;
  private double bonusExtra;

  public Administrativo(String nome, String rg, double salarioBase) {
    super(nome, rg, salarioBase);
    setHoraExtra(0);
    setBonusExtra(0.01);
  }

  public void setHoraExtra(int horaExtra) {
    this.horaExtra = horaExtra;
  }

  public int getHoraExtra() {
    return this.horaExtra;
  }

  public void setBonusExtra(double bonusExtra) {
    this.bonusExtra = bonusExtra;
  }

  public double getBonusExtra() {
    return this.bonusExtra;
  }

  public void adicionaHoraExtra(int numHoras) {
    this.horaExtra += numHoras;
  }

  public double salarioTotal() {
    return getSalarioBase() + (getHoraExtra() * (getBonusExtra() * getSalarioBase()));
  }

  public void zerarHoras() {
    this.horaExtra = 0;
  }
}
