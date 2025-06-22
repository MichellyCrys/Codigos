import java.util.*;
public class Mediana {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		
		int num = 0, tam = 0, meio =0;
		double med = 0.0;
		
		List<Integer> vet = new ArrayList<Integer>();
		
		while(num != -1) {
			if(num != 0) {
				vet.add(num);
			}
			tam += tamanho(num);
			num = scan.nextInt();
		}
		
		for(int i=0;i<tam;i++) {
			//meio = i/2;
			if(tam%2 == 0) {
				meio = i/2;
				med = (vet.get(meio)+vet.get(meio+1))/2.0;
			}
			else {
				meio = (i+1)/2;
				med = vet.get(meio);
			}
		}
		System.out.printf("%.1f", med);
	}
	
	public static int tamanho(int numero) {
		int t = 0;
		if(numero != -1 && numero !=0) {
			t+=1;
		}
		return t;
	}
}
