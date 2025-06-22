import java.util.*;
import java.lang.*;

public class ValorExpoente {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		
		int num = scan.nextInt();
		int soma = 0, k =0, c;
		
		while(num >= soma) {
			if(num >= soma) {
				k++;
			}
			soma+=Math.pow(2, k);
		}
		//System.out.print(soma);
	//System.out.println("\n");
		System.out.print(k);
	}
}
