import java.util.Scanner;

public class SomaDigitos {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		int num, soma = 0, dig;
		num = scan.nextInt();
		
		while(num > 0) {
			soma += num%10;
			num = num/10;
			//System.out.printf("%d", soma);
			
		}
		System.out.printf("%d", soma);
		scan.close();
	}
}
