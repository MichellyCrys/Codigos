import java.util.Scanner;

public class Desconto {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		
		double valorCompras = scan.nextDouble(), valorPago, desconto;
		
		if(valorCompras>=200) {
			desconto = valorCompras * 5/100;
			valorPago = valorCompras - desconto;
			System.out.printf("%.2f", valorPago);
		}
		else {
			System.out.printf("%.2f", valorCompras);
		}
		scan.close();
	}

}
