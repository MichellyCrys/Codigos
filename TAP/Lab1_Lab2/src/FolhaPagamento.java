import java.util.Scanner;

public class FolhaPagamento {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double  valorHora = scan.nextDouble();
		int horas = scan.nextInt();
		double salarioBruto, ir, inss, descontos, salarioLiquido;
		
		salarioBruto = valorHora * horas;
		ir = salarioBruto *11/100;
		inss = salarioBruto *8/100;
		descontos = ir + inss;
		salarioLiquido = salarioBruto - descontos ;
		
		System.out.printf("Salario bruto: R$%.2f\nIR: R$%.2f\nINSS: R$%.2f\nTotal de descontos: R$%.2f\nSalario liquido: R$%.2f\n", salarioBruto, ir, inss, descontos, salarioLiquido );
	}

}
