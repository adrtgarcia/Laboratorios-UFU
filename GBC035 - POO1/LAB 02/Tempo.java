package laboratorios;

public class Tempo {
	public int hora;
	public int minuto;
	public int segundo;
	
	public Tempo(int h, int m, int s) {
		setHora(h);
		setMinuto(m);
		setSegundo(s);
	}
	
	public Tempo(int h, int m) {
		setHora(h);
		setMinuto(m);
		setSegundo(0);
	}
	
	public Tempo(int h) {
		setHora(h);
		setMinuto(0);
		setSegundo(0);
	}
	
	public Tempo(Tempo t) {
		setHora(t.getHora());
		setMinuto(t.getMinuto());
		setSegundo(t.getSegundo());
	}

	public int getHora() {
		return hora;
	}

	public void setHora(int hora) {
		if((hora >= 0) && (hora < 24)) this.hora = hora;
		else this.hora = 0;
	}

	public int getMinuto() {
		return minuto;
	}

	public void setMinuto(int minuto) {
		if ((minuto >= 0) && (minuto < 60)) this.minuto = minuto;
		else this.minuto = 0;
	}

	public int getSegundo() {
		return segundo;
	}

	public void setSegundo(int segundo) {
		if ((segundo >= 0) && (segundo < 60)) this.segundo = segundo;
		else this.segundo = 0;
	}
	
	public void imprimeTempo() {
		System.out.println(hora + " : " + minuto + " : " + segundo);
	}
	
	public void aumentaMin() {
		if (minuto == 59) {
			setHora(++hora);
			minuto = 0;
		} else minuto++;
	}
	
	public void diminuiMin() {
		if (minuto == 0) {
			setHora(--hora);
			minuto = 59;
		} else minuto--;
	}
	
}
