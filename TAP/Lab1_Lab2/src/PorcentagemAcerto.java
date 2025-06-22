import java.util.*;
public class PorcentagemAcerto {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int num1=0, num2 =0, tam = 0, c=0;
		//int vet1[], vet2[];
		double por = 0.0, acertos = 0.0;
		
		List<Integer> res = new ArrayList<Integer>();
		List<Integer> gab = new ArrayList<Integer>();
		
		while(num1 != -1) {
			if(num1 != 0) {
				res.add(num1);
			}
			tam += tamanho(num1);
			num1 = scan.nextInt();
		}
		while(num2 != -1) {
			if(num2 != 0) {
				gab.add(num2);	
			}
			num2 = scan.nextInt();
		}
		
		for(int i=0;i<tam;i++) {
			//res.get(i);
			//gab.get(i);
			if(res.get(i) == gab.get(i)) {
				acertos++;
				por=(acertos*100)/tam;
			}
		}
		System.out.printf("%d",c);
		System.out.printf("%.2f",por);
		/*System.out.print(res);
		System.out.println("\n");
		System.out.print(tam);*/
	}
	
	public static int tamanho(int numero) {
		int t = 0;
		if(numero != -1 && numero !=0) {
			t+=1;
		}
		return t;
	}
}
