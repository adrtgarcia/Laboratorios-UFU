package laboratorios;

import static java.lang.Math.sqrt;
import static java.lang.Math.pow;

public class Ponto {
		private double x;
		private double y;
		
		public Ponto() {
			setX(0);
			setY(0);
		}
		
		public Ponto(double x, double y) {
			setX(x);
			setY(y);
		}
		
		public double getX() {
			return x;
		}
		
		public void setX(double x) {
			this.x = x;
		}
		
		public double getY() {
			return y;
		}
		
		public void setY(double y) {
			this.y = y;
		}
		
		public double distancia (Ponto p) {
			double xa = getX();
			double xb = p.getX();
			double ya = getY();
			double yb = p.getY();
			
			double d = sqrt((pow(xa - xb, 2)) + (pow(ya - yb, 2)));
			return d;
		}
}
