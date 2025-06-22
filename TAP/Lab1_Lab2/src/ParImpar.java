import java.util.Scanner;

public class ParImpar {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		
		int num = 0;
		String  par = "PAR", impar = "IMPAR";
	
		while(num != -1) {
			num = scan.nextInt();
			if(num%2 == 0) {
				System.out.printf("%s\n",par);
			}
			if(num%2 == 1) {
				System.out.printf("%s\n",impar);
			}
		}
	}
	
}
