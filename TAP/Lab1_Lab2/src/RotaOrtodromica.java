import java.util.Scanner;
import java.lang.Math;

public class RotaOrtodromica {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double t1, g1, t2, g2, d, R, T1, G1, T2, G2;
		t1 = scan.nextDouble();
		g1 = scan.nextDouble();
		t2 = scan.nextDouble();
		g2 = scan.nextDouble();
		R = 6371;
		
		//radianos:
		T1 = Math.toRadians(t1);
		G1 = Math.toRadians(g1);
		T2 = Math.toRadians(t2);
		G2 = Math.toRadians(g2);
		
		d = R *  Math.acos(Math.sin(T1)*Math.sin(T2) + Math.cos(T1)*Math.cos(T2)*Math.cos(G1 - G2));
		//System.out.printf("%.2f", d);
		System.out.printf("A distancia entre os pontos (%.6f, %.6f) e (%.6f, %.6f) e de %.2f km", t1, g1, t2, g2, d);
	}
}
