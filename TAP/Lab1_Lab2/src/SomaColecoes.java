import java.util.Scanner;

public class SomaColecoes {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int num = scan.nextInt(), soma = 0;
		while(num != -1) {
			
			soma += somaC(num);
			//soma += num;
			while(num != -1) {
				//soma += num;
				num = scan.nextInt();
				soma += somaC(num);
			}
			System.out.print(soma);
			soma =0;
			num = scan.nextInt();
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
