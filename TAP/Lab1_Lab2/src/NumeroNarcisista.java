import java.util.Scanner;
import java.lang.Math;

public class NumeroNarcisista {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		
		int num, cont=0, sep = 0, numNa =0, aux;
		num = scan.nextInt();
		
		cont = contador(num);
		aux =num;
		while(num > 0 ) {
			sep = num%10;
			numNa += Math.pow(sep, cont);
			num = num/10;
			
		}
		//System.out.printf("%d\n",cont);
		//System.out.printf("%d\n",aux);
		//System.out.printf("%d\n",numNa);
		
		if(aux == numNa) {
			System.out.println("SIM");
		}
		else {
			System.out.println("NAO");
		}
	}
	
	public static int contador(int numero) {
		int c =0;
		while(numero > 0) {
			c++;
			numero /= 10;
		}
		return c;
	}
}
