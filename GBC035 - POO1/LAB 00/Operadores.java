import java.util.Scanner;

public class Operadores {

	public static void main(String[] args) {
		int a = 9, b = 6;
		
		int soma = a + b;
		System.out.println ("soma = " + soma);
		int sub = a  - b;
		System.out.println ("subtração = " + sub);
		int mult = a * b;
		System.out.println ("multiplicação = " + mult);
		int div = a / b;
		System.out.println ("divisão = " + div);
		int resto = a % b;
		System.out.println ("resto = " + resto);
		
		if (a == b) System.out.println ("a é igual a b");
		else /*a != b*/ { 
			System.out.println("a é diferente de b");
			if (a > b) System.out.println ("a é maior que b");
			else /*a < b*/ System.out.println ("a é menor que b");
		}
		
		boolean p = true, q = false;
		if (p && q) System.out.println ("p && q = true");
		else System.out.println ("p && q = false");
		
		if (p || q) System.out.println ("p || q = true");
		else System.out.println ("p || q = false");
		
		if (!p) System.out.println ("!p = true");
		else System.out.println ("!p = false");
		
		if (p ^ q) System.out.println ("p xor q = true");
		else System.out.println ("p xor q = false");
		
		Scanner entrada = new Scanner(System.in);
		int i, num;
		
		for (i = 0, soma = 0; i < 5; i++) {
			num = entrada.nextInt();
			soma += num;
		}
		System.out.println ("resultado: " + soma);
		
		num = 2309;
		while (i != 0) {
			num -= 10;
			i--;
		}
		System.out.println ("resultado: " + num);
	}
}
