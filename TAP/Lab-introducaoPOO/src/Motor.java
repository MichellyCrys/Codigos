
class Motor {
	int tipo;
	double capacidade;
	int potencia;
	
	Motor(){
		tipo = 0;
		capacidade = 0.00;
		potencia =0;
	}
	
	Motor(int tipo, double capacidade, int potencia){
		this.tipo = tipo;
		this.capacidade = capacidade;
		this.potencia = potencia;
	}
	
	String getTipoString() {
		String tipoMotor;
		int tip = tipo;
		
		if(tip == 1) {
			tipoMotor = "Gasolina";
		}
		else if(tip == 2) {
			tipoMotor = "Alcool";
		}
		else if(tip == 3) {
			tipoMotor = "Flex";
		}
		else if(tip == 4) {
			tipoMotor = "Diesel";
		}
		else if(tip == 5) {
			tipoMotor = "Eletrico";
		}
		else {
			tipoMotor ="Outros";
		}
		return tipoMotor;
	}
	
	String 	getDescricao() {
		String tPlaca, motor;
		double cap;
		int pot;
		
		
		tPlaca = getTipoString();
		cap = capacidade;
		pot = potencia;
		
		motor = "Motor: tipo="+tPlaca+", "+"capacidade="+String.valueOf(cap)+"L, "+"potencia="+String.valueOf(pot)+"CV.";
		return motor;
	}
}
