public class TestaConta {
	public static void main(String[] args) {
		Conta c = new Conta();
		
		c.alteraSaldo(500);
		System.out.println("saldo: " + c.verSaldo());
		
		c.credito(10);
		System.out.println("saldo: " + c.verSaldo());
		
		c.debita(250);
		System.out.println("saldo: " + c.verSaldo());
	}
}
