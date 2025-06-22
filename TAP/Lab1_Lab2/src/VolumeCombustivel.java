import java.util.Scanner;
import java.lang.Math;

public class VolumeCombustivel {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double volumeCom, alturaT, nivelCom, raio, volumeEsfera, volumeCalota, volumeCilindro, pi, x, erro = -1.000, meio;
		
		alturaT = scan.nextDouble();
		nivelCom = scan.nextDouble();
		raio = scan.nextDouble();
		x = alturaT - nivelCom;
		pi = Math.PI;
		meio = alturaT/2; 
		
		if((x > 0) && (x != meio)) {
			volumeEsfera = (4.0/3.0)* pi *Math.pow(raio, 3);
			volumeCalota = (pi / 3.0) * Math.pow(x, 2) * (3*raio - x);
			volumeCilindro = pi * Math.pow(raio, 2) * x;
			volumeCom = volumeEsfera + volumeEsfera + volumeCilindro;
			
			//System.out.printf("%.3f\n", volumeEsfera);
			//System.out.printf("%.3f\n", volumeCalota);
			//System.out.printf("%.3f\n", volumeCilindro);
			System.out.printf("%.3f\n", volumeCom);
			
		}
		else if( x == meio) {
			volumeEsfera = (4.0/3.0)* pi *Math.pow(raio, 3);
			volumeCalota = (pi / 3.0) * Math.pow(x, 2) * (3*raio - x);
			volumeCilindro = pi * Math.pow(raio, 2) * x;
			volumeCom = volumeEsfera + volumeEsfera - volumeCilindro;
		}
		
		else {
			System.out.print(erro);
		}
		scan.close();
	}
}
