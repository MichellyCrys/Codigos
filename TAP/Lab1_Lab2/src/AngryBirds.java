import java.util.Scanner;
import java.lang.Math;
import java.text.DecimalFormat;

public class AngryBirds {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		DecimalFormat dec = new DecimalFormat("0.00");
		
		double vi, anguloGraus, dis, radians, R, D, mod, g = 9.8, tol1, tol2, seno, quadrado, rDec;
		vi = scan.nextDouble();
		anguloGraus = scan.nextDouble();
		dis = scan.nextDouble();	
		
		radians = Math.toRadians(anguloGraus);
		mod = Math.abs(vi);
		seno = Math.sin(radians * 2);
		quadrado = Math.pow(mod, 2);
		
		R = (quadrado * seno)/g;
		
		tol1 = dis + 0.1;
		tol2 = dis - 0.1;
		System.out.print(R);
		System.out.println("\n");
		System.out.print(tol1);
		System.out.println("\n");
		System.out.print(tol2);
		System.out.println("\n");
		if((R == dis) || (R == tol1) || (R == tol2)){
			System.out.print(1);
		}
		else if(R != dis){
			System.out.print(0);
		}
	}
}
