import java.util.Scanner;

public class Fahrenheit {
	public static void main(String[] args) {
		Scanner scan= new Scanner(System.in);
	
		double F, C = scan.nextDouble();
		F = ((9*C)/5)+32;
		System.out.printf("%.1f", F);
		
		scan.close();
	}
	
}
