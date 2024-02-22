package laboratorios;

public class MaquinaDePassagens {
	private double preco;
	private double qntdInserida;
	private double total;
	
	public MaquinaDePassagens() {
		setPreco(2.00);
		setQntdInserida(0);
		setTotal(0);
	}
	
	public MaquinaDePassagens(double valor) {
		setPreco(valor);
		setQntdInserida(0);
		setTotal(0);
	}
	
	public double getPreco() {
		return preco;
	}
	
	public void setPreco(double preco) {
		this.preco = preco;
	}
	
	public double getQntdInserida() {
		return qntdInserida;
	}
	
	public void setQntdInserida(double qntdInserida) {
		this.qntdInserida = qntdInserida;
	}
	
	public double getTotal() {
		return total;
	}
	
	public void setTotal(double total) {
		this.total = total;
	}
	
	public void precoPassagem() {
		System.out.println("Preço da passagem: R$ " + preco);
	}
	
	public void inserirDinheiro (double valor) {
		if ((valor == 1.00) || (valor == 2.00)) {
			qntdInserida += valor;
			total += valor;
		} else
			System.out.println("A máquina aceita apenas notas de R$ 1,00 e R$ 2,00");
	}
	
	public void emitirPassagem() {
		if (qntdInserida >= preco) {
			System.out.println("Emitindo passagem...");
			qntdInserida -= preco;
			
			if (qntdInserida != 0) {
				System.out.println("Troco: R$ " + qntdInserida);
				qntdInserida = 0;
			}
		} else {
			double falta = preco - qntdInserida;
			System.out.println("Faltam R$ " + falta + " para finalizar a compra");
		}
	}
	
	public void valorInserido() {
		System.out.println("Valor inserido: R$ " + qntdInserida);
	}
	
	public void totalInserido() {
		System.out.println("Total inserido na máquina: R$ " + total);
	}	
}
