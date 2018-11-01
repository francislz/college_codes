package principal;

public class Data {
	private int dia;
	private int mes;
	private int ano;
	
	public Data(int dia, int mes, int ano) {
		super();
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	
	public int getDia() {
		return dia;
	}


	public void setDia(int dia) {
		this.dia = dia;
	}


	public int getMes() {
		return mes;
	}


	public void setMes(int mes) {
		this.mes = mes;
	}


	public int getAno() {
		return ano;
	}


	public void setAno(int ano) {
		this.ano = ano;
	}


	public String retornaNumData() {
		return dia + "/" + mes + "/" + ano;
	}
	
	public String retornaExtData() {
		String mesExt = null;
		if(mes == 1)
			mesExt = "Janeiro";
		else if(mes == 2)
			mesExt = "Fevereiro";
		else if(mes == 3)
			mesExt = "Março";
		else if(mes == 4)
			mesExt = "Abril";
		else if(mes == 5)
			mesExt = "Maio";
		else if(mes == 6)
			mesExt = "Junho";
		else if(mes == 7)
			mesExt = "Julho";
		else if(mes == 8)
			mesExt = "Agosto";
		else if(mes == 9)
			mesExt = "Setembro";
		else if(mes == 10)
			mesExt = "Outubro";
		else if(mes == 11)
			mesExt = "Novembro";
		else
			mesExt = "Dezembro";
		
		return dia + " de " + mesExt + " de " + ano;
	}
	
	public boolean isBissexto() {
		if((ano % 4 == 0) && (ano % 100 != 0) || (ano % 400 == 0))
			return true;
		else
			return false;
	}
	
	public int dataDiff(Data data) {
		if(data.getAno() > this.ano) {
			return data.getAno() - this.ano;
		}
		else {
			return this.ano - data.getAno();
		}		
	}
	
	public static void main(String[] args) {
		Data data = new Data(12, 01, 12);
		Data data1 = new Data(12, 01, 16);
		Data data2 = new Data(12, 01, 14);
		System.out.println(data.dataDiff(data1));
		System.out.println(data.dataDiff(data2));
		System.out.println("É bissexto : " + data1.isBissexto());
		System.out.println("É bissexto : " + data2.isBissexto());
	}
	
}
