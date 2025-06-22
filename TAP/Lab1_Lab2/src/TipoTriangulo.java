import java.util.Scanner;

public class TipoTriangulo {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double med1, med2, med3;
		med1 = scan.nextDouble();
		med2 = scan.nextDouble();
		med3 = scan.nextDouble();
		
		if((med1<0) || (med2<0) || (med3<0) || (med1 + med2 <= med3) || (med1 + med3 <= med2) || (med2 + med3 <= med1)) {
			System.out.printf("invalido");
		}
		else {
			if((med1 == med2) && (med1 == med3) && (med2 == med3)) {
				System.out.printf("equilatero");
			}
			else if((med1 != med2) && (med1 != med3) && (med2 !=3)) {
				System.out.printf("escaleno");
			}
			else {
				System.out.printf("isosceles");
			}
		}
	}

}
