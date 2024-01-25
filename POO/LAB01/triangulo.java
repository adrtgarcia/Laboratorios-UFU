package laboratorio;

public class Triangulo {
	private float lado1, lado2, lado3;
  
  //get e set lado1
	public float getLado1() {
		return lado1;
	}
	public void setLado1(float lado1) {
		if (lado1 > 0)
			this.lado1 = lado1;
		else this.lado1 = 1;
	}

  //get e set lado2
	public float getLado2() {
		return lado2;
	}
	public void setLado2(float lado2) {
		if (lado2 > 0)
			this.lado2 = lado2;
		else this.lado2 = 1;
	}

  //get e set lado3
	public float getLado3() {
		return lado3;
	}
	public void setLado3(float lado3) {
		if (lado3 > 0)
			this.lado3 = lado3;
		else this.lado3 = 1;
	}
	
	// verifica se o triângulo existe
	public boolean verificatriangulo () {
		if ((lado1 < lado2 + lado3) && (lado2 < lado1 + lado3) && (lado3 < lado1 + lado2))
			return true;
		else return false;
	}
	
	// alterar dados (nao corrigido)
	public int alteralados (float lado, float novovalor) {
		if (lado == 1) {
			setLado1 (novovalor);
			return 1; //deu certo
		}
		
		if (lado == 2) {
			setLado2 (novovalor);
			return 1; //deu certo
		}
		
		if (lado == 3) {
			setLado3 (novovalor);
			return 1; //deu certo
		}
		
		return 0; //lado invalido
	}
	
	// printar (nao corrigido)
	public void printarlados () {
		float l1 = getLado1();
		float l2 = getLado2();
		float l3 = getLado3();
		System.out.println ("lado 1: " + l1);
		System.out.println ("lado 2: " + l2);
		System.out.println ("lado 3: " + l3);
		
	}
	
	// calcula perímetro
	public float perimetro () {
		return lado1 + lado2 + lado3;
	}
	
	// tipo de triangulo (equilatero, isosceles ou escaleno)
	public String tipotriangulo () {
		if ((lado1 == lado2) && (lado1 == lado3))
			return "equilatero";
		if ((lado1 != lado2) && (lado1 != lado3))
			return "escaleno";
		else return "isosceles";
	}
	
}

/*
MAIN: 

package laboratorio;

public class Main {

	public static void main(String[] args) {		
		Triangulo t = new Triangulo();
		t.setLado1(3);
		t.setLado2(4);
		t.setLado3(5);
		
		boolean confere = t.verificatriangulo();
		System.out.println(confere);
		System.out.println("lado 1: " + t.getLado1());
		System.out.println("lado 2: " + t.getLado2());
		System.out.println("lado 3: " + t.getLado3());
		
		float p = t.perimetro();
		System.out.println("perimetro: " + p);
		
	}

}

FAZER CADASTRATRIANGULO (FLOAT L1, FLOAT L2, FLOAT L3) E APLICAR
FAZER RESTRIÇÃO PARA CASO NÃO FORME UM TRIANGULO

*/
