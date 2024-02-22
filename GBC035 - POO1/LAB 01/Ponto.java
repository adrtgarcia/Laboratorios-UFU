package laboratorios;

import static java.lang.Math.sqrt;
import static java.lang.Math.pow;

public class Ponto {
		private int x;
		private int y;
		
		public int getX() {
			return x;
		}
		
		public void setX(int valor) {
			if (valor >= 0) x = valor;
			else x = 0;
		}
		
		public int getY() {
			return y;
		}
		
		public void setY(int valor) {
			if (valor >= 0) y = valor;
			else y = 0;
		}
		
		public void inicializarPonto (int x, int y) {
			setX(x);
			setY(y);
		}
		
		public double distancia (Ponto p) {
			int xa = getX();
			int xb = p.getX();
			int ya = getY();
			int yb = p.getY();
			
			double d = sqrt((pow(xa - xb, 2)) + (pow(ya - yb, 2)));
			return d;
		}
}
