import java.util.Scanner;

public class Xadrez {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int linhas = scan.nextInt();
		for(int i = linhas;i>0;i--) {
			for(int j=i; j>0;j--) {
				if(i<=j) {
					System.out.print("*");
				}
				if(j==0) {
					System.out.println(" ");
				}
			}
		}
	}
}
