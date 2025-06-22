import java.util.Scanner;

public class OperacoesString {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);
		
		String nome = scan.next();
		String lerEspaco;
		int quantidade, primeiro, ultimo, conMaiuculo, conMinusculo, subAPorE, pares, quantVogais, vogais, cont;
		
		//nome = scan.nextLine();
		//quantidade = nome.length();
		nome = scan.nextLine();
		lerEspaco = nome;
		quantidade = nome.length();
		quantidade = lerEspaco.length();
		
		System.out.print(quantidade);
		//System.out.print(nome);
	}
}
