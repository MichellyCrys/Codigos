import java.util.Scanner;
import java.lang.Math;

public class AreaTriangulo {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double a, b, c, s, area;
		a = scan.nextDouble();
		b = scan.nextDouble();
		c = scan.nextDouble();
		
		if(( a + b <= c ) || ( a + c <= b ) || ( b + c <= a )){
			System.out.printf("Triangulo invalido");
		}
		
		//if((a + b > c) || (a + c > b) || (b + c > a)) 
		else{
			s = (a + b + c)/2;
			area = Math.sqrt(s * (s - a) * (s - b ) * (s - c));
			System.out.printf("%.2f",area);
		}
		
		scan.close();
	}

}
