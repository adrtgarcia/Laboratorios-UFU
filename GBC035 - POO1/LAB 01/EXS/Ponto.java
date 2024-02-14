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
		
		public double distancia (Ponto a, Ponto b) {
			int xa = a.getX();
			int xb = b.getX();
			int ya = a.getY();
			int yb = b.getY();
			
			double d = sqrt((pow(xa - xb, 2)) + (pow(ya - yb, 2)));
			return d;
		}
}
