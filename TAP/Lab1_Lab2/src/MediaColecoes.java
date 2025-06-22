import java.util.Scanner;

public class MediaColecoes {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double num = 0.0, soma = 0.0, denominador, media = 0.0;
		
		while(num != -1) {
			denominador = 0.0;
			soma += somaC(num);
			
			while(num != -1) {
				if((num != -1) && (num!=0.0)) {
					denominador++;
				}
				num = scan.nextInt();
				soma += somaC(num);
				//denominador++;
				
			}
			
			media = soma/denominador;
			System.out.printf("%.2f\n", media);
			soma = 0.0;
			media = 0.0;
			denominador = 0.0;
			num = scan.nextDouble();
			
		}
		
	}
			
	public static double somaC(double numero) {
		double x = 0;
		
		if(numero != -1) {
			x += numero;
		}
		return x;
	}

}
