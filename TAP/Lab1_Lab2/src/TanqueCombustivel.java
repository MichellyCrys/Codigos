import java.util.Scanner;
import java.lang.Math;

public class TanqueCombustivel {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int r,x,opcao;
		r = scan.nextInt();
		x = scan.nextInt();
		opcao = scan.nextInt();
		
		double volumeEspera = (4.0/3.0)*Math.PI*Math.pow(r, 3);
		double volumeCalota = (Math.PI/3)*Math.pow(x,2)*(3*r-x);
		
		double volumeAr = volumeCalota;
		double volumeCombustivel = volumeEspera - volumeCalota;
		
		if(opcao==1) {
			System.out.printf("%.4f",volumeAr);
		}
		if(opcao==2) {
			System.out.printf("%.4f",volumeCombustivel);
		}
	}
}
