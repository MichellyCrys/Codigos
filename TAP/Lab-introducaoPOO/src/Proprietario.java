
class Proprietario {
	String nome;
	int cnh;
	int anoNascimento;
	
	Proprietario(){
		nome = "";
		cnh = 0;
		anoNascimento = 0; 
	}
	
	Proprietario(String nome, int cnh, int anoNascimento){
		this.nome = nome;
		this.cnh = cnh;
		this.anoNascimento = anoNascimento;
	}
	
	int getIdade(int anoReferencia) {
		int anoNas = anoNascimento, ida;
		ida = anoReferencia - anoNas;
		return ida;
	}
	
	String getDescricao() {
		String x, a;
		int  y, z;
		x = nome;
		y = cnh;
		
		z = anoNascimento;
		
		a = "Proprietario: nome="+ x+", " +"cnh="+String.valueOf(y)+", " +"anoNascimento="+String.valueOf(z)+".";
		return a;
	}
}
