import java.util.Scanner;

public class IdadeUfam {

	public static void main(String[] args) {
		
			Scanner scan = new Scanner(System.in);
			int anoAtual = scan.nextInt(),anoFundacao=1909,x;
			x=anoAtual - anoFundacao;
			
			System.out.printf("A UFAM tem %d anos de fundacao",x);
			scan.close();
			}
	

}
