package laboratorios;

public class Horista extends Professores {

	private double salarioHora;
	private double horasTrabalhadas;
	
	public Horista(String nome, String matricula, int idade, double salHora, double horasTrab) {
		super(nome, matricula, idade);
		setSalarioHora(salHora);
		setHorasTrabalhadas(horasTrab);
		
	}

	public double getSalarioHora() {
		return salarioHora;
	}

	public void setSalarioHora(double salarioHora) {
		this.salarioHora = salarioHora;
	}

	public double getHorasTrabalhadas() {
		return horasTrabalhadas;
	}

	public void setHorasTrabalhadas(double horasTrabalhadas) {
		this.horasTrabalhadas = horasTrabalhadas;
	}
	
	public double calculaSalario() {
		double sal = salarioHora * horasTrabalhadas;
		return sal;
	}
	
}
