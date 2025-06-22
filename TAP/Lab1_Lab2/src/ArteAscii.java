import java.util.Scanner;

public class ArteAscii {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numero = scan.nextInt();
		for(int i=numero; i>0; i--) {
			for(int j=i; j>0;j--) {
				System.out.print('*');
			}
			if(i!=1) {
				System.out.println(' ');
			}
		}
		for(int a=numero; a>-1;a--) {
			for(int b=a; b<numero; b++) {
				System.out.print('*');
			}
			System.out.println(' ');
		}
		scan.close();
	}
}

