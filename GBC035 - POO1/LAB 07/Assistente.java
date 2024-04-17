public class Assistente extends Funcionario {
  public Assistente (String nome, String matricula, double salarioBase) {
    super (nome, matricula, salarioBase);
  }

  public double calculaSalario() {
    return getSalarioBase();
  }

  public void mostrarDados() {
    System.out.println("Nome: " + getNome());
    System.out.println("Matrícula: " + getMatricula());
    System.out.println("Cargo: Assistente");
    System.out.println("Salário base: " + getSalarioBase());
    System.out.println("Salário total: " + calculaSalario());
  }
}
