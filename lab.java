
public class Tempo {
	
	private int hora;
	private int minuto;
	private int segundo;
	//get e set para todos (usar this.coisa = validacoisa) dentro
  /*valid minseg:
    private int validaMinSeg (int valor) {
      if ((valor >= 0) && (valor < 60))
        return valor;
      else return 0;
    }

    private int validaHora (int h) {
      if ((h >= 0) && (h < 24))
        return h;
      else return 0;
    }
  
  */
	public void Tempo (int h, int m, int s) {
    hora = validaHora(h);		
		minuto = validaMinSeg(m);		
		segundo = validaMinSeg(s);
  }
	
	public Tempo (int h, int m) {
		hora = validaHora(h);		
		minuto = validaMinSeg(m);		
		segundo = 0;
	}
	
	public Tempo (int h) {
		hora = validaHora(h);		
		minuto = 0;		
		segundo = 0;
	}
	
	public void TempoT (Tempo t) {
		hora = validaHora(t.getHora());
		minuto = validaMinSeg(t.getMinuto());
		segundo = validaMinSeg(t.getSegundo());
	}
	
	public void PrintaT (Tempo t) {
		System.out.printf ("%d : %d : %d", hora, minuto, segundo);
	}
	
	public void AumentaM (Tempo t) {
		int mintemp = t.minuto;
		mintemp++;
		minuto = mintemp;
	}
	
	public void DiminuiM (Tempo t) {
		int mintemp = t.minuto;
		mintemp--;
		minuto = mintemp;
	}
}
