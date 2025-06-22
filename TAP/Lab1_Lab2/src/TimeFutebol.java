import java.util.*;

public class TimeFutebol {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		
		int num1=0, num2 =0, tam = 0;
		int vit=0, empates=0, derrotas=0;
		
		List<Integer> time = new ArrayList<Integer>();
		List<Integer> adversario = new ArrayList<Integer>();
		
		while(num1 != -1) {
			if(num1 != 0) {
				time.add(num1);
			}
			tam += tamanho(num1);
			num1 = scan.nextInt();
		}
		while(num2 != -1) {
			if(num2 != 0) {
				adversario.add(num2);	
			}
			num2 = scan.nextInt();
		}
		
			for(int i=0;i<tam;i++) {
				if(time.get(i) < adversario.get(i)) {
					derrotas+=1;
				}
				if(time.get(i) == adversario.get(i)) {
					empates+=1;
				}
				/*if(time.get(i)  != adversario.get(i)) {
					vit+=1;
				}*/
			}
		System.out.print(vit);
		//System.out.println(" ");
		//System.out.print(empates);
		//System.out.print(derrotas);
	}
	
	public static int tamanho(int numero) {
		int t = 0;
		if(numero != -1 && numero !=0) {
			t+=1;
		}
		return t;
	}
}
