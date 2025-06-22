import java.util.Scanner;

public class FaltasTrabalho {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double num, cont = 0.0, seg=0.0, ter=0.0, qua=0.0, qui=0.0, sex=0.0, sab=0.0, cemPor;
		double porSeg=0.0, porTer=0.0, porQua=0.0, porQui=0.0, porSex=0.0, porSab=0.0;
		//num = scan.nextInt();
		num = 0.0;
		while(num != -1) {
			//cont = 0.0;
			//num = scan.nextInt();
			while(num != -1) {
				if((num != -1) && (num !=0)) {
					cont++;
				}
				num = scan.nextInt();
				if(num == 2) {
					seg++;
					//porSeg = (seg*100)/cont;
					//System.out.printf("%.2f\n",seg);
				}
				if(num == 3) {
					ter++;
				}
				if(num == 4) {
					qua++;
				}
				if(num == 5) {
					qui++;
				}
				if(num == 6) {
					sex++;
				}
				if(num == 7) {
					sab++;
				}
				
			}
			//cont = 0.0;
			//num = scan.nextInt();
			if(cont > 0) {
				if(seg > 0) {
					porSeg = (seg * 100)/cont;
					//System.out.printf("%.2f\n", seg);
				}
				if(ter > 0) {
					porTer = (ter * 100)/cont;
				}
				if(qua > 0) {
					porQua = (qua * 100)/cont;
				}
				if(qui > 0) {
					porQui = (qui * 100)/cont;
				}
				if(sex> 0) {
					porSex = (sex * 100)/cont;
				}
				if(sab > 0) {
					porSab = (sab * 100)/cont;
				}
				
				System.out.printf("%.1f %.1f %.1f %.1f %.1f %.1f", porSeg, porTer, porQua, porQui, porSex, porSab);
			}
			/*if(seg > 0) {
				porSeg = (seg * 100)/cont;
				System.out.printf("%.2f\n", porSeg);
			}
			else if(seg<=0) {
				porSeg = 0.00;
			}*/
			//System.out.printf("%.2f\n", porSeg);
			//System.out.print(cont);
			
		}
		
	}
}
