public class Gerente extends Funcionario {

  public Gerente (String nome, String matricula, double salarioBase) {
    super (nome, matricula, salarioBase);
  }
  
  public double calculaSalario() {
    return 2 * getSalarioBase();
  }

  public void mostrarDados() {
    System.out.println("Nome: " + getNome());
    System.out.println("Matrícula: " + getMatricula());
    System.out.println("Cargo: Gerente");
    System.out.println("Salário base: " + getSalarioBase());
    System.out.println("Salário total: " + calculaSalario());
  }
}
