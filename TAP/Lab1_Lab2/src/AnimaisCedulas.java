import java.util.Scanner;

public class AnimaisCedulas {
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			double valor = scan.nextDouble();
			if(valor == 2) {
				System.out.printf("Tartaruga");
			}
			else if(valor == 5){
				System.out.printf("Garça");
			}
			else if(valor == 10) {
				System.out.printf("Arara");
			}
			else if(valor == 20) {
				System.out.printf("Mico-leão-dourado");
			}
			else if(valor == 50) {
				System.out.printf("Onça-pintada");
			}
			else if(valor == 100) {
				System.out.printf("Garoupa");
			}
			else {
				System.out.printf("erro");
			}
		}
	}

}
