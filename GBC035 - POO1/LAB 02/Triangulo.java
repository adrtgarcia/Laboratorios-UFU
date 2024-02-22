package laboratorios;

public class Triangulo {
	private double lado1;
	private double lado2;
	private double lado3;
	
	public Triangulo() {
		setLado1(lado1);
		setLado2(lado2);
		setLado3(lado3);
	}
	
	public Triangulo(double lado1, double lado2, double lado3) {
		setLado1(lado1);
		setLado2(lado2);
		setLado3(lado3);
	}
  
	public double getLado1() {
		return lado1;
	}
	
	public void setLado1(double lado1) {
		if (lado1 > 0)
			this.lado1 = lado1;
		else this.lado1 = 1;
	}

	public double getLado2() {
		return lado2;
	}
	
	public void setLado2(double lado2) {
		if (lado2 > 0)
			this.lado2 = lado2;
		else this.lado2 = 1;
	}

	public double getLado3() {
		return lado3;
	}
	
	public void setLado3(double lado3) {
		if (lado3 > 0)
			this.lado3 = lado3;
		else this.lado3 = 1;
	}
	
	public boolean verificaTriangulo() {
		if ((lado1 < lado2 + lado3) && (lado2 < lado1 + lado3) && (lado3 < lado1 + lado2))
			return true;
		else return false;
	}

	public void alteraLados(double lado, double valor) {
		if (lado == 1) setLado1(valor);
		if (lado == 2) setLado2(valor);
		if (lado == 3) setLado3(valor);
	}
	
	public void printarLados() {
		System.out.println ("lado 1: " + lado1);
		System.out.println ("lado 2: " + lado2);
		System.out.println ("lado 3: " + lado3);
	}
	
	public double perimetro(Triangulo t) {
		return lado1 + lado2 + lado3;
	}

	public String tipoTriangulo(Triangulo t) {
		if ((lado1 == lado2) && (lado1 == lado3))
			return "equilatero";
		if ((lado1 != lado2) && (lado1 != lado3))
			return "escaleno";
		else return "isosceles";
	}
}
