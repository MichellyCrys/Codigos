import java.util.Scanner;

public class Media {
	public static void main(String[] args) {
		Scanner scan= new Scanner(System.in);
		
		double num1, num2, num3, soma=0, media =0;
		
		num1 = scan.nextDouble();
		num2 = scan.nextDouble();
		num3 = scan.nextDouble();
		soma = num1 + num2 + num3;
		media = soma/3;
		
		System.out.printf("%.2f", media);
		scan.close();
	}
	
}
