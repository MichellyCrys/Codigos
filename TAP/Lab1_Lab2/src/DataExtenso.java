import java.util.Scanner;
public class DataExtenso {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String ddmmaaaa = scan.next();
		String d = ddmmaaaa.substring(0,2);
		int dia = Integer.parseInt(d);
		//System.out.println(dia);
		String m = ddmmaaaa.substring(2,4);
		int mes = Integer.parseInt(m);
		//System.out.println(mes);
		String meses[] = {"janeiro", "fevereiro", "março", "abril",
			      "maio", "junho", "julho", "agosto", "setembro", "outubro",
			      "novembro", "dezembro"};
		String a = ddmmaaaa.substring(4,8);
		int ano = Integer.parseInt(a);
		//System.out.println(ano);
		if(mes == 01) {
			System.out.printf("%d de %s de %d", dia, meses[0], ano);
		}
		if(mes == 02) {
			System.out.printf("%d de %s de %d", dia, meses[1], ano);
		}
		else if(mes == 03) {
			System.out.printf("%d de %s de %d", dia, meses[2], ano);
		}
		else if(mes == 04) {
			System.out.printf("%d de %s de %d", dia, meses[3], ano);
		}
		else if(mes == 05) {
			System.out.printf("%d de %s de %d", dia, meses[4], ano);
		}
		else if(mes == 06) {
			System.out.printf("%d de %s de %d", dia, meses[5], ano);
		}
		else if(mes == 07) {
			System.out.printf("%d de %s de %d", dia, meses[6], ano);
		}
		else if(mes == 8) {
			System.out.printf("%d de %s de %d", dia, meses[7], ano);
		}
		else if(mes == 9) {
			System.out.printf("%d de %s de %d", dia, meses[8], ano);
		}
		else if(mes == 10) {
			System.out.printf("%d de %s de %d", dia, meses[9], ano);
		}
		else if(mes == 11) {
			System.out.printf("%d de %s de %d", dia, meses[10], ano);
		}
		else if(mes == 12) {
			System.out.printf("%d de %s de %d", dia, meses[11], ano);
		}
		scan.close();
	}
		
}
