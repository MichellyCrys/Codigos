
public class Placa {
	String placa;
	int tipo;
	
	Placa(){
		placa ="";
		tipo =0;
	}
	
	Placa(String placa, int tipo){
		this.placa = placa;
		this.tipo = tipo;
	}
	
	String getTipoString() {
		String tipoPlaca;
		int tip;
		tip = tipo;
		if(tip == 1) {
			tipoPlaca = "Normal";
		}
		else if(tip == 2) {
			tipoPlaca = "Servico";
		}
		else if(tip == 3) {
			tipoPlaca = "Oficial";
		}
		else if(tip == 4) {
			tipoPlaca = "Auto escola";
		}
		else if(tip == 5) {
			tipoPlaca = "Prototipo";
		}
		else if(tip == 6) {
			tipoPlaca = "Colecionador";
		}
		else {
			tipoPlaca ="Outros";
		}
		return tipoPlaca;
	}
	
	boolean temEstacionamentoLivre() {
		int t = tipo;
		if((t == 2) || (t == 3)) {
			return true;
		}
		else {
			return false;
		}
	}
	
	String getDescricao() {
		String p ,tPlaca, des;
		boolean estacionamento;
		
		p = placa;
		tPlaca = getTipoString();
		estacionamento = temEstacionamentoLivre();
		
		des = "Placa: placa="+p+", "+"tipo="+tPlaca+", "+"estacionamentoLivre="+String.valueOf(estacionamento)+".";
		return des;
	}
}
