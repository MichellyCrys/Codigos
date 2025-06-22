
public class CarroMain {
	public static void main(String[] args) {
		Proprietario proprietario = new Proprietario();
		Placa placa = new Placa();
		Motor motor = new Motor();

		/*
		 * proprietario.nome = "Emmett L. Brown";
		 * proprietario.cnh = 98008173;
		 * proprietario.anoNascimento = 1920;
		 * 
		 * placa.placa = "OAT-3966";
		 * placa.tipo =6;
		 * 
		 * motor.tipo = 1;
		 * motor.capacidade = 2.85;
		 * motor.potencia = 130;
		 */

		Carro car = new Carro("DeLorean", "DMC-12", proprietario, placa, motor);

		// System.out.print(idade);
		// System.out.println("\n");
		// System.out.print(proprietario);
		// Placa pl = new Placa("NAN-8192", 6);
		System.out.println(car.getDescricao());
	}
}
