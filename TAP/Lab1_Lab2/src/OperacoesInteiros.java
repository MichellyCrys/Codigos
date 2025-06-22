import java.util.Scanner;

public class OperacoesInteiros {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int num, quantElem, pares=0, impares=0, soma=0, maior ,menor;
		double media=0.00;
		
		num = scan.nextInt();
		
		while(num != -1) {
			quantElem = 0;
			soma += somaC(num);
			maior =0;
			menor = num;
			
			while(num!=-1) {
				if((num != -1) && (num != 0.00)) {
					quantElem++;
				}
				if(num%2 == 0) {
					pares++;
				}
				if(num%2 == 1) {
					impares++;
				}
				if(num >= maior) {
					maior = num;
				}
				
				if(num<=menor) {
					menor = num;
				}
				num = scan.nextInt();
				soma += somaC(num);
			}
			media = (soma*0.1)/(quantElem*0.1);
			System.out.printf("%d\n", quantElem);
			System.out.printf("%d\n", pares);
			System.out.printf("%d\n", impares);
			System.out.printf("%d\n", soma);
			System.out.printf("%.2f\n", media);
			System.out.printf("%d\n", maior);
			System.out.printf("%d\n", menor);
			soma = 0;
			media = 0.0;
			quantElem = 0;
			pares =0;
			impares =0;
			maior =0;
			menor =0;
			num = scan.nextInt();
			//num = scan.nextInt();
			//soma += somaC(num);
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
