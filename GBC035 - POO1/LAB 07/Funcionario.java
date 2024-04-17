public abstract class Funcionario implements Imprimivel {
  private String nome;
  private String matricula;
  private double salarioBase;

  public Funcionario(String nome, String matricula, double salarioBase) {
    setNome(nome);
    setMatricula(matricula);
    setSalarioBase(salarioBase);
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return this.nome;
  }

  public void setMatricula(String matricula) {
    this.matricula = matricula;
  }

  public String getMatricula() {
    return this.matricula;
  }

  public void setSalarioBase(double salarioBase) {
    this.salarioBase = salarioBase;
  }

  public double getSalarioBase() {
    return this.salarioBase;
  }

  public abstract double calculaSalario();

  public void mostrarDados() {
    System.out.println("Nome: " + getNome());
    System.out.println("Matrícula: " + getMatricula());
  }
}
